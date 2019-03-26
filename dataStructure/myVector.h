#ifndef MYVECTOR_H 
#define MYVECTOR_H

// #include "fib.h"
#include <string>

typedef int     Rank; // vector 秩
#define DEFAULT_CAPACITY    10 //默认的初始容量， 根据实际情况设置


// 二分查找DSA 在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
// 二分查找算法（版本A）：三个分支，两个比较
//template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
//    /*DSA*/printf ( "BIN search (A)\n" );
//    while ( lo < hi ) { //每步迭代可能要做两次比较判断，有三个分支
//        /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
//        Rank mi = ( lo + hi ) >> 1; //以中点为轴点
//        if      ( e < A[mi] ) hi = mi; //深入前半段[lo, mi)继续查找
//        else if ( A[mi] < e ) lo = mi + 1; //深入后半段(mi, hi)继续查找
//        else                return mi; //在mi处命中
//        /*DSA*/ if ( lo >= hi ) { for ( int i = 0; i < mi; i++ ) printf ( "     " ); if ( mi >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" ); }
//    } //成功查找可以提前终止
//    return -1; //查找失败
// } //有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置


// 二分查找算法（版本B）：两个分支 一个比较
//template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
//    /*DSA*/printf ( "BIN search (B)\n" );
//    while ( 1 < hi - lo ) { //每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
//        /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
//        Rank mi = ( lo + hi ) >> 1; //以中点为轴点
//        ( e < A[mi] ) ? hi = mi : lo = mi; //经比较后确定深入[lo, mi)或[mi, hi)
//    } //出口时hi = lo + 1，查找区间仅含一个元素A[lo]
//    /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
//    return ( e == A[lo] ) ? lo : -1 ; //查找成功时返回对应的秩；否则统一返回-1
// } //有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置


// 二分查找算法（版本C）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
    /*DSA*/printf ( "BIN search (C)\n" );
    while ( lo < hi ) { //每步迭代仅需做一次比较判断，有两个分支
        /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
        Rank mi = ( lo + hi ) >> 1; //以中点为轴点
        ( e < A[mi] ) ? hi = mi : lo = mi + 1; //经比较后确定深入[lo, mi)或(mi, hi)
    } //成功查找不能提前终止
    /*DSA*/ for ( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
    return --lo; //循环结束时，lo为大于e的元素的最小秩，故lo - 1即不大于e的元素的最大秩
} //有多个命中元素时，总能保证返回秩最大者；查找失败时，能够返回失败的位置


// // Fibonacci查找算法（版本A）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
// template <typename T> static Rank fibSearch ( T* A, T const& e, Rank lo, Rank hi ) {
//     /*DSA*/printf ( "FIB search (A)\n" );
//     Fib fib ( hi - lo ); //用O(log_phi(n = hi - lo)时间创建Fib数列
//     while ( lo < hi ) { //每步迭代可能要做两次比较判断，有三个分支
//         /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); else printf ( "<<<<|" ); printf ( "\n" );
//         while ( hi - lo < fib.get() ) fib.prev(); //通过向前顺序查找（分摊O(1)）――至多迭代几次？
//         Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
//         if      ( e < A[mi] ) hi = mi; //深入前半段[lo, mi)继续查找
//         else if ( A[mi] < e ) lo = mi + 1; //深入后半段(mi, hi)继续查找
//         else                return mi; //在mi处命中
//         /*DSA*/ if ( lo >= hi ) { for ( int i = 0; i < mi; i++ ) printf ( "     " ); if ( mi >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" ); }
//     } //成功查找可以提前终止
//     return -1; //查找失败
// } //有多个命中元素时，不能保证返回秩最大者；失败时，简单地返回-1，而不能指示失败的位置






template <typename T> class Vector 
{
protected:
    Rank _size;   //规模
    int _capacity; //容量
    T* _elem;    //数据区

    void expand(); // 可扩充向量的溢出策略
    void shrink(); // 装载因子过低时，进行缩容
    void copyFrom ( T const* A, Rank lo, Rank hi ); //复制数组区间A[lo, hi)

    //排序
    bool bubble ( Rank lo, Rank hi ); //扫描交换
    void bubbleSort ( Rank lo, Rank hi );    //起泡排序算法

    void merge ( Rank lo, Rank mi, Rank hi ); //归并算法
    void mergeSort ( Rank lo, Rank hi ); //归并排序算法

//    void selectionSort ( Rank lo, Rank hi ); //选择排序算法
//    void quickSort ( Rank lo, Rank hi ); //快速排序算法
//    void heapSort ( Rank lo, Rank hi ); //堆排序（稍后结合完全堆讲解）

public: 
    //默认构造函数  指定初始容量 申请内存空间
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //capecity rankSize elem初值
    {
        _elem = new T[_capacity = c]; //size < capacity
        for(_size=0; _size < s; _elem[_size++] = v); //所有元素初始为v
    }

    //析构函数 
    ~Vector(){ delete [] _elem;}

    // read-only  (这个const是指返回值是常量)
    Rank size() const {return _size;} //返回vector 规模
    bool empty() const {return !_size;} //判断vector 是否为空 true is empty
    int disordered() const; //判断vector 是否已经排序,有序return 0

    //随机置乱
    void unsort(Rank lo, Rank hi);
    void unsort() {unsort(0, _size);}

    //排序 [多种排序方法的接口]
    void sort(Rank lo, Rank hi);
    void sort() { sort(0, _size); }

    //无序查找
    Rank find( T const& e, Rank lo, Rank hi) const; //从区间[lo, hi]中查找
    Rank find( T const& e) const { return find(e, 0, _size);} //从整个vector中查找

    //有序查找
    Rank search( T const& e, Rank lo, Rank hi) const; //从区间[lo, hi]中查找
    Rank search( T const& e) const  //从整个vector中查找
    {
        return (_size <= 0) ? -1:search(e, 0, _size);
    };

    // 插入
    Rank insert(Rank r, T const& e); //中间插入
    Rank insert(T const& e) {return insert(_size, e);}; //尾部插入

    // 删除
    int remove(Rank lo, Rank hi); //删除区间[lo, hi]
    T remove(Rank r); //删除

    //剔除重复元素
    //无序剔除
    int deduplicate(); //无序去重
    int uniquify(); //有序去重

    void print_vector(); //打印vector
    //重载操作 
    T& operator[] (Rank r) const; //重载下标操作符，实现数组形式的元素引用
    Vector<T> & operator= (Vector<T> const&); //重载赋值操作符，实现vector 克隆

    void traverse( void(*visit) (T&)); //遍历 (使用函数指针，只读/局部性修改)
    template <typename VST> void traverse(VST& ); //遍历 使用函数对象，可全局性修改


};



#endif