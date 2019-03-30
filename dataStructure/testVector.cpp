#include "myVector.h"
#include<iostream>

int main()
{
    Vector<int>  intVectorTest(100, 10, 0);
    for(int i=0; i<=10; i++)
    {
        intVectorTest.insert(i);
    }
    std::cout << "test vector_size " << intVectorTest.size() << std::endl;
    for(int i=0; i< intVectorTest.size(); i++)
    {
        std::cout << intVectorTest[i] << "  " << std::endl;
    }
    


    return 0;
}