
#ifndef MYVECTOR_H 
#define MYVECTOR_H


typedef int     Rank; // vector 秩
#define DEFAULT_CAPACITY    10 //默认的初始容量， 根据实际情况设置

template <typename T> class Vector 
{
protected:
    Rank _size;   //规模
    int _capacity; //容量
    T* _elem;    //数据区

    void expend(); // 可扩充向量的溢出策略

public: 
    //构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //capecity rankSize elem初值
    {
        _elem = new T[_capacity = c]; //size < capacity
        for(_size=0; _size < s; _elem[_size++] = v); //所有元素初始为v
    }

    //析构函数 
    ~Vector(){ delete [] _elem;}

    // read-only  (这个const是指返回值是常量)
    Rank size() const {return _size;}; //返回vector 规模
    bool empty() const {return !_size;}; //判断vector 是否为空 true is empty
    int disordered() const; //判断vector 是否已经排序

    //无序查找
    Rank find( T const& e, Rank lo, Rank hi) const; //从区间[lo, hi]中查找
    Rank find( T const& e) const { return find(e, 0, _size);} //从整个vector中查找

    //有序查找
    Rank search( T const& e, Rank lo, Rank hi) const; //从区间[lo, hi]中查找
    Rank search( T const& e) const  //从整个vector中查找
    {
        return (_size <= 0) ? -1:search(e, 0, _size);
    };

    //重载操作 新增
    T& operator[] (Rank r) const; //重载下标操作符，实现数组形式的元素引用
    Vector<T> & operator= (Vector<T> const&); //重载赋值操作符，实现vector 克隆

};



#endif