//
// Created by hualong on 2019/3/28.
//

#ifndef C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYQUEUE_H
#define C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYQUEUE_H

#include "myVector.h"
#include "myList.h"

template <typename T> class QueueWithVector : public Vector<T>
{
    //注意vector的最后是队尾，开始是队首， 队尾入，队首出
    //size() empty() 可以直接继承
    void enqueue(T const& e) {insert(e);} //插入到最后
    T dequeue() {return remove(0);}
    T& front() { return (this*)[0];}

};

template <typename T> class QueueWithList : public List<T>
{
    //注意List的尾节点是队尾，首节点是队首
    void enqueue(T const& e) {insertAsLast(e);}
    T dequeue() { return  remove(first());}
    T& front() { return first()->data;}
};



#endif //C_PLUS_PLUS_SOFTWARE_DEVELOPER_MYQUEUE_H
