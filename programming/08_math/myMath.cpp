//
// Created by hualong on 2019/4/8.
//

/*
 *  ******************************************************
 * C++ 取整函数  ceil向上取整  floor向下取整  round四舍五入 如果抹去小数点 直接int强制类型转换
 *
 *
 *
 *  ******************************************************
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //1. string初始化与赋值
    std::string str="We think in generalities, but we live in details.";
    std::string str2 = str.substr (3,5);     // "think"
    std::size_t pos = str.find("live");      // position of "live" in str
    std::string str3 = str.substr (pos);     // get from "live" to the end

    str.append(str2);                       // 全部拼接
    str.append(str3,6,3);                   // 从6开始 长度为3
    str.append("dots are cool",5);          // 从0开始，长度为5
    str.append("here: ");                   // 直接拼字符串
    str.append(10u,'.');                    // ".........."

    char* cstr = new char [str.length()+1];
    std::strcpy (cstr, str.c_str());

    // 插入操作
    str.insert(6,str2);                 // to be (the )question
    str.insert(6,str3,3,4);             // to be (not )the question
    str.insert(10,"that is cool",8);    // to be not (that is )the question
    str.insert(10,"to be ");            // to be not (to be )that is the question
    str.insert(15,1,':');               // to be not to be(:) that is the question
    str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
    str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)

    str.erase (10,8);
    str.erase (str.begin()+5, str.end()-9);  //

    // ``````
    delete[] cstr;

    //字符串切分
    char c_str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",c_str);
    pch = strtok (c_str," ,.-");  //以空格 逗号 点号 横向都可以切分
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }

    //反向迭代器实现逆序
    string str_orinal;
    cin >> str_orinal;
    string s(str_orinal.rbegin(),str_orinal.rend());
    cout << s <<endl;


    std::cout << str2 << ' ' << str3 << '\n';

    return 0;
}