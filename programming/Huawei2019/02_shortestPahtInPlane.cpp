
/*
 * **********************************************
 * 华为笔试第2题： 从原点出发到平面上5点的最短距离
 *
 * 以蜂巢为平面原点的5片花丛A B C D E的坐标，
 * 从出发到返回蜂巢最短路径的长度取整数，丢弃小数点后面的整数
 *
 * 测试用例：
 * 输入:
 * 200 0 200 10 200 50 200 30 200 25
 *
 * 输出：
 * 456
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

