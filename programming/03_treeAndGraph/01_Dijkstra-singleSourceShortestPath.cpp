//
// Created by hualong on 2019/4/26.
//

/*
 *  Dijstra算法要解决的问题： M个点，N条边的， 指定从A到B的单源最短路径问题 O(n^2)
 *
 *  求有向图G的 v0顶点到其余顶点v最短路径P[v]及带权长度D[v]
 *  P[v]的值为前驱顶点下标， D[v]表示v0到v的最短路径长度和。
 *
 *  算法流程：
    由邻接矩阵表示各点之间的距离。
    初始化dis数组，表示目标点dis[0]到其他点的最短距离
    具体步骤：
    1.找到当前离dis[0]最近的点d[i]。
    2.根据dis[i]的出边，更新所有能够从0->i->n这样路径到达n的距离。
    3.根据dis[i]的所有出边更新过后，再从i+1~n中找出离dis[0]最近的点，重复以上步骤。
    4.所有的点都遍历过后，结束。
 * 注意：这里面的下标都是从1开始， 包括邻接矩阵，边和点
 */

#include <iostream>
using namespace std;


const int maxnum = 10;    //最大顶点的数量
const int maxint = INT16_MAX; //

// 输入： 顶点数量，存储边的邻接矩阵
void Dijkstra(int vertexes, int adjacent[][maxnum], int source, int *shortestDist, int *prev)
{
    bool status[maxnum];    // 表示每个顶点到source最短路径的状态 status[5]=1  表示Vsource 到 V5的最短路径可求
    for(int i=1; i<=vertexes; ++i)
    {
        shortestDist[i] = adjacent[source][i]; //源点到所有点的权值
        status[i] = 0;     // 全部顶点初始化为 未知最短路径状态
        if(shortestDist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = source;   //prev 表示前驱节点的下标
    }
    shortestDist[source] = 0; //到自身的距离为0  其实在初始化时候，已经做了
    status[source] = true; // 把自己加入集合

    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    for(int i=2; i<=vertexes; ++i)
    {
        int tmp = maxint;
        int u = source;  //u是G的某一个顶点，把从源到u且中间只经过s中顶点的路称为从源到u的特殊路径
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=vertexes; ++j)
            if((!status[j]) && shortestDist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = shortestDist[j];
            }
        status[u] = true;    // 表示u点已存入S集合中

        // 更新dist
        for(int j=1; j<=vertexes; ++j)
            if((!status[j]) && adjacent[u][j]<maxint)
            {
                int newdist = shortestDist[u] + adjacent[u][j];
                if(newdist < shortestDist[j])
                {
                    shortestDist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

// 前驱顶点 下标矩阵， 起点，终点
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}

int main()
{

    // 各数组都从下标1开始
    int shortestDist[maxnum];     // 表示当前点到源点的最短路径长度
    int prev[maxnum];                 // 记录当前点的前一个结点
    int adjacent[maxnum][maxnum];    //邻接矩阵 记录图的两点间路径长度

    int vertexes=5, edges=7;             // 图的结点数和路径数

    // 输入顶点和边
    cin >> vertexes >> edges;


    // 输入的起点，终点以及其路径长度
    int start, end, len;

    // 初始化邻接矩阵
    for(int i=1; i<=vertexes; ++i)
        for(int j=1; j<=vertexes; ++j) {
            if (i == j) adjacent[i][j] = 0;
            else adjacent[i][j] = maxint;  //无穷
        }
    // 邻接矩阵赋值
    for(int i=1; i<=edges; ++i)
    {
        int p, q, weight;
        cin >> p >> q >> weight;
        if(weight < adjacent[p][q])   // 有重边
        {
            adjacent[p][q] = weight;      // p指向q
            adjacent[q][p] = weight;      // q指向p，这样表示无向图
        }
    }

    //每一个顶点到源点最短距离初始化
    for(int i=1; i<=vertexes; ++i)
        shortestDist[i] = maxint;

    //打印邻接矩阵
    for(int i=1; i<=vertexes; ++i)
    {
        for(int j=1; j<=vertexes; ++j)
            cout << adjacent[i][j] << "\t";
        cout << endl;
    }

    Dijkstra(vertexes, adjacent, 2, shortestDist, prev);

    // 最短路径长度
    cout << "the source vertex to the last vertex path distance is : " << shortestDist[5] << endl;

    // 路径
    cout << "the shortest path is:  ";
    searchPath(prev, 2, 5);
}

/*
 * 测试用例：
 * 5 7
 * 1 2 10
 * 1 4 30
 * 1 5 100
 * 2 3 50
 * 3 5 10
 * 4 3 20
 * 4 5 60
 *
 * 输出：
0       10      32767   30      100
10      0       10      32767   32767
32767   10      0       20      10
30      32767   20      0       60
100     32767   10      60      0
the source vertex to the last vertex path distance is : 30
the shortest path is:  1 -> 2 -> 3 -> 5
 *
 */