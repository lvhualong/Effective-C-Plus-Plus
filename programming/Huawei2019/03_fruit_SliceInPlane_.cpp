
/*
 * **********************************************
 * 华为笔试第2题： 二维平面切水果游戏
 *
 * 已知屏幕由40*50小方格组成，经过每个方格画出的直线最多有四条
 * 左上角坐标为(0,0)  右下角坐标为(39,49)
 *
 *第一行输入整数 N (0<N<=36)
 * 下面每行表示点的 x y 值
 * 测试用例：
 * 输入:
 * 2
 * 3 4
 * 2 2
 *
 * 输出：
 * 2
 *
 *
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

