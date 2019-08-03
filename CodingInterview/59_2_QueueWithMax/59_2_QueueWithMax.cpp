//
// Created by LAB540 on 2019/8/3.
//
/*
 * 实现一个带最大值的队列
 * 要求 max push_back pop_front时间复杂度都是O(1)
 */


/*
 * 内部维护两个队列，一个data 一个maximums
 */

#include <cstdio>
#include <deque>
#include <exception>
#include <iostream>
using namespace std;

template<typename T> class QueueWithMax
{
public:
    QueueWithMax() : currentIndex(0)
    {
    }

    void push_back(T number)
    {
        while(!maximums.empty() && number >= maximums.back().number)
            maximums.pop_back();

        InternalData internalData = { number, currentIndex };
        data.push_back(internalData);
        maximums.push_back(internalData);

        ++currentIndex;
    }

    void pop_front()
    {


        if(maximums.front().index == data.front().index)
            maximums.pop_front();

        data.pop_front();
    }

    T max() const
    {


        return maximums.front().number;
    }

private:
    struct InternalData
    {
        T number;
        int index;
    };

    deque<InternalData> data; //维护list的数据，数据包含value and index
    deque<InternalData> maximums;//同时需要维护 maximums
    int currentIndex;
};

int main()
{
    QueueWithMax<int> queueWithMax;
    queueWithMax.push_back(3);
    queueWithMax.push_back(1);
    queueWithMax.push_back(2);

    int result = queueWithMax.max();
    cout << "the max is: " << result <<endl;
}
