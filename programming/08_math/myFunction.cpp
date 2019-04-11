
/* *********************************************************
 *
 *memset()  内存数据置值  #include <cstring>  //memset
 *
 * ----------------------------------
 * 输入示例：
 *
 * *********************************************************
 */

#include <iostream>
#include <cstring>

using namespace std;

class Solution{
    void function(){

    }

};

int main() {
    char str[] = "almost every programmer should know memset!";
    memset (str,'-',6); //从字符串首地址到第六个数据 全部置为 ‘-’

    std::cout << "Hello, World!" << std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 *
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */