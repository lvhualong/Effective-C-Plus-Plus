
#include <iostream>
#include <boost/thread.hpp>
#include <boost/filesystem/path.hpp> 
#include <boost/filesystem/operations.hpp>


void wait( int seconds)
{
    boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void thread_function()
{
    for(int i=0; i<5; i++)
    {
        wait(1);
        std::cout << i << std::endl;
    }
}

int main()
{
    boost::thread thread1(thread_function);
    thread1.join();
    return 0;
}