//
// Created by hualong on 2019/4/6.
//
#include <iostream>
using namespace std;
/*
 * ************************************************
 * 问题描述：有序二维数组中的查找
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
 * ************************************************
 */
class Solution {
public:
// 方法描述：
 int  findInPartiallySortedMatrix(int* matrix, int rows, int cols, int num){
    if(matrix != nullptr && rows>0 && cols>0)
    {
        int row = 0; //0行开始
        int col = cols-1; //最后一列开始
        while(row<rows && col >=0)
        {
            if(matrix[row*cols + col] == num)
                return num;
            else if(matrix[row*cols + col] > num) //排除一列
                col--;
            else row++; //比较下一个元素

        }
    }
        return  false;
}


};


int main()
{
    //输入
    int matrix_num[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Solution solution;

    int num = solution.findInPartiallySortedMatrix((int*)matrix_num, 4, 4, 7);
    if(num)
        cout << "find num: " << num << endl;
    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */