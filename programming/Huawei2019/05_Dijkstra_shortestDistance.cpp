//单源最短路径
/*
    由邻接矩阵表示各点之间的距离。
    初始化dis数组，表示目标点dis[0]到其他点的最短距离
    具体步骤：
    1.找到当前离dis[0]最近的点d[i]。
    2.根据dis[i]的出边，更新所有能够从0->i->n这样路径到达n的距离。
    3.根据dis[i]的所有出边更新过后，再从i+1~n中找出离dis[0]最近的点，重复以上步骤。
    4.所有的点都遍历过后，结束。
*/

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
int inf = INT64_MAX;
vector<int> Dijkstra_shortestDistance(vector<vector<int> >& matrix , int src)
{
    int rows = matrix.size();
    int min = 0;
    int cur = 0;
    vector<int> res(rows, 0);
    vector<int> book(rows, 0);
    for (int i=1;i<rows;i++)
        res[i] = matrix[src][i];

    for (int i=1; i<rows-1; i++)
    {
        min = inf;
        for (int j=1; j<rows; j++)
        {
            if(book[j] == 0 && res[j] < min)
            {
                min = res[j];
                cur = j;
            }
        }
        book[cur] = 1;
        for (int v=1; v< rows; v++)
        {
            if (matrix[cur][v]<inf)
            {
                if(res[v]>res[cur]+matrix[cur][v])
                    res[v] = res[cur] + matrix[cur][v];
            }
        }
    }
    return res;
}

int main()
{
    int  n=0,m=0, t1,t2,t3,t0;

    cin >> n >> m; //

    vector<vector<int> > e(n+1, vector<int>(n+1));

    for(int i=1;i<n+1;i++)
        for (int j=1;j<n+1;j++)
        {
            if (i==j) e[i][j] = 0;
            else e[i][j] = inf;
        }

    for (int i=1;i<m+1;i++)
    {
        cin >>t0>> t1>>t2>>t3;
        e[t1][t2] = t3;

    }
    cin>>t0>>t1;

    vector<int> res = Dijkstra_shortestDistance(e,t0);

    if (res[t1]<inf)
        cout<<res[t1]<<endl;
    else cout<<"NA"<<endl;
    return 0;
}