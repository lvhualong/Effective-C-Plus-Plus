//
// Created by hualong on 2019/3/28.
//

#ifndef C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYSTACK_H
#define C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYSTACK_H

#include "myList.h"
#include "myVector.h"

/*
 * 基于 Vector 实现的 Stack
 */
//template <typename T> class StackWithVector : public Vector<T>
//{
//public:
//    //size() empty() 直接继承
//    void push(T const& e) {this->insert(e); } //vector 入栈方式，在Vector结尾插入
//    T pop() { return remove((this->size()) -1);} //删除并返回尾元素
//    T& top() { return (*this)[this->size()-1];} //返回尾部元素
//
//};


/*
 * 基于 List 实现的 Stack
 */
template <typename T> class StackWithList : public List<T>
{
public:
    void push(T const& e) {this->insertAsLast(e);}
    T pop() { return remove(this->last());}
    T& top() { return this->last()->data;}
};


#endif //C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYSTACK_H
