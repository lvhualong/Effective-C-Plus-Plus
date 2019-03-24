

#include "myVector.h"
#include <iostream>


// protected

// 控制可扩充向量的溢出策略：数据溢出，申请一个更大的数组(2倍)，原数据集体搬迁到新空间，释放原空间
template <typename T>
void Vector<T>::enpand()
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


 //重载Vector里的赋值操作符，实现vector 克隆
template <typename T> 
Vector<T>&  Vector<T>::operator= (Vector<T> const& V)
{
   if ( _elem ) delete [] _elem; //释放原有内容
   copyFrom ( V._elem, 0, V.size() ); //整体复制
   return *this; //返回当前对象的引用 Vector，以便链式赋值
}


int main()
{
    std::cout << "test" << std::endl;
    return 0;
}