
/* *********************************************************
 * 问题描述：寻找子串问题
 * 先输入 n 个子串，然后 然后再输入一个大的字符串，
 * 在字符串中搜索子串出现的次数，不允许重复
 * 例如 n=3
 * aa
 * b
 * ac
 * bbaac
 * 输出为3
 * 找到子串 b b aa 或者找到 b b ac
 *
 * ----------------------------------
 * 输入示例：
 *
 * *********************************************************
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
    //输入长串 和待查找短串，返回查找的子串的数量
    int finsSubstringAndRemove(string& stringFull, const string& subString ){
        int count = 0;
        size_t found = stringFull.find(subString);
        while(found != string::npos){
            count++;
//            stringFull.erase(found, subString.size());//不能删除，会改变顺序，只能替换成空格
            stringFull.replace(found, subString.size()," ");//不能删除，会改变顺序，只能替换成空格
            found = stringFull.find(subString);
        }
        return count;
    }

};

//bool mycompX(Point& p1, Point& p2){
//    return p1.x < p2.x;
//}
int main() {

    int subStringNum; //子串数量
    vector<pair<int, string>> subStrings;
    //{pair<int,string>(2,"aa"),pair<int,string>(1,"b"),pair<int,string>(2,"ac")};
    cin >> subStringNum;
    for(int i=0; i<subStringNum; i++){
        string temp;
        cin >> temp;
        int length = temp.size();

        subStrings.push_back(pair<int, string>(length, temp)); //数据缓冲
    }
    string stringFull;  // {"bbaac"};
    cin >> stringFull;

    sort(subStrings.begin(), subStrings.end());
    cout << "the first string :" <<subStrings[0].second <<" length:"<<subStrings[0].first <<endl;
    Solution solution;
    int maxSubstringCount = 0;
    for(auto subString:subStrings){
        maxSubstringCount += solution.finsSubstringAndRemove(stringFull, subString.second);
    }
    cout << "the max substring count is: "<< maxSubstringCount << endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 先写一个子串查找，并把原来的子串替换成空格的函数，主要利用 string的find 和 replace
 *
 * 然后 把所有的子串和它的对应长度组织成pair的数据格式，然后按size排序
 * 从小字符到大字符一次查找
 *
 * 注意空格替换很巧妙，因为每行输入的时候，刚好没有空格
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */