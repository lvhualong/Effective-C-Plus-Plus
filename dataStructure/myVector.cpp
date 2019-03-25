

#include "myVector.h"
#include <iostream>


// protected

// 控制可扩充向量的溢出策略：数据溢出，申请一个更大的数组(2倍)，原数据集体搬迁到新空间，释放原空间
template <typename T>
void Vector<T>::expand()
{
   if ( _size < _capacity ) return; //尚未满员时，不必扩容
   if ( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //不低于最小容量
   T* oldElem = _elem;  
   _elem = new T[_capacity <<= 1]; //容量加倍 (新数组的地址由操作系统分配，与原数据区没有直接的关系)
   for ( int i = 0; i < _size; i++ )
      _elem[i] = oldElem[i]; //复制原向量内容（T为基本类型，或已重载赋值操作符'='）
   /*DSA*/ //printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity/2, _elem, _size, _capacity);
   delete [] oldElem; //释放原空间  
}

template <typename T>
void Vector<T>::shrink() // 装载因子过低时，进行缩容
{
   if ( _capacity < DEFAULT_CAPACITY << 1 ) return; //不致收缩到DEFAULT_CAPACITY以下
   if ( _size << 2 > _capacity ) return; //以25%为界
   T* oldElem = _elem;  _elem = new T[_capacity >>= 1]; //容量减半
   for ( int i = 0; i < _size; i++ ) _elem[i] = oldElem[i]; //复制原向量内容
   delete [] oldElem; //释放原空间
}


//以数组区间A[lo, hi)为蓝本复制向量
template <typename T> 
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi )
 { 
   _elem = new T[_capacity = 2 * ( hi - lo ) ]; _size = 0; //分配空间(2倍)，规模清零
   while ( lo < hi ) //A[lo, hi)内的元素逐一
      _elem[_size++] = A[lo++];  //复制至_elem[0, hi - lo)
}



// public

// 乱序操作
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T* V = _elem + lo; //将子向量_elem[lo, hi)视作另一向量V[0, hi - lo)
    for ( Rank i = hi - lo; i > 0; i-- ) //自后向前
        swap ( V[i - 1], V[rand() % i] ); //将V[i - 1]与V[0, i)中某一元素随机交换
}

//无序查找
template <typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
{
    while((lo < hi--) && (e != _elem[hi])) ; //从后向前，顺序查找
    return  hi;
}

//插入元素
template <typename T>
Rank Vector<T>::insert(Rank r, const T &e)
{
    expand(); //若有必要，扩容
    for ( int i = _size; i > r; i-- ) _elem[i] = _elem[i-1]; //自后向前，后继元素顺次后移一个单元
    _elem[r] = e; _size++; //置入新元素并更新容量
    return r; //返回秩
}

//删除元素

//删除区间
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if ( lo == hi ) return 0; //出于效率考虑，单独处理退化情况，比如remove(0, 0)
    while ( hi < _size ) _elem[lo++] = _elem[hi++]; //[hi, _size)顺次前移hi - lo个单元
    _size = lo; //更新规模，直接丢弃尾部[lo, _size = hi)区间
    shrink(); //若有必要，则缩容
    return hi - lo; //返回被删除元素的数目
}

//删除单个元素
template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r, r+1);
    return e;
}

// 剔除重复元素
// 无序剔除
template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size; //记录原规模
    Rank i = 1; //从_elem[1]开始
    while ( i < _size ) //自前向后逐一考查各元素_elem[i]
        ( find ( _elem[i], 0, i ) < 0 ) ? //在其前缀中寻找与之雷同者（至多一个）
        i++ : remove ( i ); //若无雷同则继续考查其后继，否则删除雷同者
    return oldSize - _size; //向量规模变化量，即被删除元素总数
}
// 有序剔除
// [循环迭代了 _size-1] 如果每次都remove 那么时间复杂度是O(n^2)
//template <typename T>
//int Vector<T>::uniquify() { //有序向量重复元素剔除算法（低效版 仿照无序的）
//    int oldSize = _size; int i = 1; //当前比对元素的秩，起始于首元素
//    while ( i < _size ) //从前向后，逐一比对各对相邻元素
//        _elem[i - 1] == _elem[i] ? remove ( i ) : i++; //若雷同，则删除后者；否则，转至后一元素
//    return oldSize - _size; //向量规模变化量，即被删除元素总数
//}

//有序向量重复元素剔除算法（高效版 相邻的多个重复只做一次copy, 修改尺寸直接截断）
template <typename T> int Vector<T>::uniquify()
{
    Rank i = 0, j = 0; //各对互异“相邻”元素的秩
    while ( ++j < _size ) //逐一扫描，直至末元素
        if ( _elem[i] != _elem[j] ) //跳过雷同者
            _elem[++i] = _elem[j]; //发现不同元素时，向前移至紧邻于前者右侧

    _size = ++i; shrink(); //直接截除尾部多余元素
    return j - i; //向量规模变化量，即被删除元素总数
}


 //重载Vector里的赋值操作符，实现vector 克隆
template <typename T> 
Vector<T>&  Vector<T>::operator= (Vector<T> const& V)
{
   if ( _elem ) delete [] _elem; //释放原有内容
   copyFrom ( V._elem, 0, V.size() ); //整体复制
   return *this; //返回当前对象的引用 Vector，以便链式赋值
}

template <typename T> 
Vector<T>&  Vector<T>::operator[] (Rank r) const //重载下标操作符，实现数组形式的元素引用
{
    return _elem[r];
}

int main()
{
    std::cout << "test" << std::endl;
    return 0;
}