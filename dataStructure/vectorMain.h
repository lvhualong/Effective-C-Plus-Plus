
#ifndef MYVECTOR_H 
#define MYVECTOR_H


typedef int Rank; // vector 秩


template <typename T> class Vector 
{
protected:
    Rank _size;   //规模
    int _capacity; //容量
    T* _elem;    //数据区


public: 
    //构造函数
    Vector()
    {}    
}



#endif