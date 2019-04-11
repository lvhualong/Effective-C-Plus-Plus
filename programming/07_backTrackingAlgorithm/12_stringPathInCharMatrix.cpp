
/* *********************************************************
 * 问题描述：  剑指offer 12题
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 * ----------------------------------
 * 输入示例：
 * 输入一个字符二维矩阵，和一个待查找字符串，  输出是否包含该路径
// A B T G
// C F C S
// J D E H
 例如针对这个矩阵，存在字符串“BFCE”的路径，不存在"ABFB"的路径
 * *********************************************************
 */

#include <iostream>
#include <cstring>  //memset
#include <cstdio>
//#include <stack>

using namespace std;
class Solution{
public:
    //输入矩阵 和 待查找路径
    bool hasPath(const char* matrix, int rows, int cols, const char* str){
        //边界判断
        if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
            return false;

        bool *visited = new bool[rows*cols];//定义一个bool数组，标记方格是否已经走过
        memset(visited, 0, rows*cols); //初始化为0 都没走过

        int pathLength = 0;
        for(int row=0; row<rows; row++) {
            for (int col = 0; col < cols; col++) { //找第一匹配元素
                if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        delete [] visited;
        return false;
    }

private:
    bool hasPathCore(const char* matrix, int rows, int cols,
                    int row, int col, const char* str, int& pathLength, bool* visited)
    {
        if(str[pathLength] == '\0')  return true; //终止条件

        bool hasPath = false;
        //坐标有效   //找到一个点  //并且这个值没有被访问到
        if(row>=0 && row<=rows && col>=0 && col<= cols
            && matrix[row*cols +col] == str[pathLength]
          && !visited[row*cols +col])
        {
            ++pathLength; //字符串指针右移一位
            visited[row*cols +col] = true; //标记为已走过
            hasPath = hasPathCore(matrix,rows,cols, row-1, col, str, pathLength, visited)
                   || hasPathCore(matrix,rows,cols, row+1, col, str, pathLength, visited)
                   || hasPathCore(matrix,rows,cols, row, col-1, str, pathLength, visited)
                   || hasPathCore(matrix,rows,cols, row, col+1, str, pathLength, visited);
            if(!hasPath)
            {
                --pathLength;
                visited[row*cols +col] = false;
            }
        }
        return hasPath;
    }

};

int main() {

    int rows = 3;
    int cols = 4;
    const char* stringMatrix = "ABTGCFCSJDEH";
    const char* str = "ABTCED";
//    for(int i=0; i<rows; i++)
//        for(int j=0; j<cols; j++)
//        {
//            matrix[i*rows+j] = stringMatrix[i*rows+j];
//        }
    Solution solution;
    bool flag = solution.hasPath(stringMatrix, rows, cols, str);

    flag ?  cout << "find path" : cout <<"can't find path";
    cout << endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 *
 *
 * ----------------------------------
 * 测试示例：
 * 3行4列   string=ABTCED   BFCF
// A B T G
// C F C S
// J D E H
 * *********************************************************
 */