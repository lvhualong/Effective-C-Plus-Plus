
/*
 * **********************************************
 * 华为笔试第1题： 字符串的小端/大端编码
 *
 * 计算机系统内存的两种字节序： 大端/小端
 * 以数字0x12345678为例
 * Big Endian:     低字节在高位地址端，高字节在低位地址端 【地址由低到高依次存储 0x12 0x34 0x56 0x78】
 * Little Endian:  低字节在低位地址端，高字节在高位地址端 【地址由低到高依次存储 0x78 0x56 0x34 0x12】
 *
 * 定义一种字符编码：
 * 9个字符为一个编码组
 * 第一个字符定义后续8个字符的字节序
 * 第一个字符 ‘0’表示小端， ‘1’表示大端
 * 后续8个字符，每一个字符代表一个字节
 *
 * 编码解析之后字符串采用大端模式
 * 例如：
 * 编码组“012345678” 解析之后大端字符串为“87654321”
 * 编码组“112345678” 解析之后大端字符串为“12345678”
 *
 * 输入：
 * 第一行 N  表示有多少个编码组
 * 第二行  编码的字符串
 *
 * 测试用例：
 * 输入:
 * 2
 * 012345678112345678
 *
 * 输出：
 * 87654321 12345678
 *
 *
 * 解决思路：
 * 循环 对每个编码组处理
 * 从大字符串取出每一个小substr
 * 根据首元素 判断大端小端
 * 0 逆序 使用逆向迭代器  先反序，然后把最后一个pop掉
 * 1 正序 去掉第一个元素就可以
 * cout 直接打印 【注意 每一个字符都是一个字节】
 * *********************************************
 */
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    void bigEndian_Decode(string& str, int num){
        int interval = 9;
        for(int i=0; i<num; i++){
            string encode_str = str.substr(i*interval, 9); //取每一个编码组
//            cout << encode_str << " ";
            if(encode_str[0] == '0') //LittelEndion
            {
                string littleEnding(encode_str.rbegin(), encode_str.rend());
                littleEnding.pop_back();
                cout << littleEnding << " ";
            } else if(encode_str[0] == '1'){
                string bigEndion(encode_str.begin()+1, encode_str.end());
                cout << bigEndion << " ";
            }
            else
                continue; //错误编码
        }
    }
};

int main()
{
    int num;
    string str;
    cin >> num;
    cin >> str;
//    string str = "012345678112345678";

    Solution solution;
    solution.bigEndian_Decode(str, num);

    return 0;
}

/*
 * *************************************************
 * 测试示例:
 *
 * 2
 * 012345678112345678
 *
 * 3
 * 1abcdefgh0123456781ABCDEFGH
 *
 * *************************************************
 */

