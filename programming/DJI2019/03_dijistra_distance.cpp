//
// Created by LAB540 on 2019/8/4.
//

/*
 * 问题描述： 机器人寻路问题
 *  有N个路标点，编号0~N-1  机器人只能沿着直线在两个路标点之间移动
 *  机器人从编号0的路标点出发，裁判随机给出一个路标，要求机器人尽可能快的到达路标位置，每一轮过后都重新开始，总时间最短者获胜
 *
 *  其中会确保每两个路标点之间至少有一条路径可以到达
 *
 *  输入包含多组测试数据，每组数据如下：
 *  第一行 N P C  路标数目 可以移动的路标通路数目 以及裁判进行比赛的轮数
 *  接下来P行输入三个正整数， A B T 从A-B所需要的时间
 *  然后接下来C行表示每轮指定的要到达的路标点
 * 测试用例：
 *  2 1 1
 *  0 1 10
 *  1
 * 输出10
 *
 * 4 5 3
 * 0 1 15
 * 1 2 15
 * 0 3 50
 * 1 3 30
 * 2 3 10
 * 2
 * 1
 * 3
 *
 * 输出结果 85
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


unordered_map<int, int> dijistra_distance(unordered_map<int,vector<vector<int >>>& grapgh, int vertex, int src, int targ = 1){
  unordered_set<int> visited;
  unordered_map<int, int> distancemap;
  for (int i = 0; i < vertex; ++i) {
    if(i!=src){
      distancemap[i] = INT32_MAX;
    }
  }
  visited.insert(src);
  for(auto edge:grapgh[src]){
    distancemap[edge[0]] = edge[1];
  }

  for (int j = 0; j < vertex; ++j) {
    if(j == src)
      continue;
    int mindisfromstart = INT32_MAX;
    int mindisindex = -1;
    if(!visited.count(j) && distancemap[j]<mindisfromstart){
      mindisfromstart = distancemap[j];
      mindisindex = j;
    }

    if(mindisindex == -1)
      break;

    visited.insert(mindisindex);
    for(auto edge:grapgh[mindisindex]){
      if(visited.count(edge[0]))
        continue;
      int predis = distancemap[edge[0]];
      if(edge[1]!=INT32_MAX && mindisfromstart+edge[1]-1<predis){
        distancemap[edge[0]] = mindisfromstart+edge[1]-1;
      }
    }
  }
  return distancemap;
}


int main() {
  int n, p, c;
  cin >> n >> p >> c;

  unordered_map<int, vector<vector<int>>> graph_s1;
  vector<int> destination;
  for (int i = 0; i < p; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    graph_s1[a].push_back({b, t});
    graph_s1[b].push_back({a, t});
  }

  for (int j = 0; j < c; ++j) {
    int des;
    cin>>des;
    destination.push_back(des);
  }

  auto res = dijistra_distance(graph_s1, n, 0);

  int res_sum = 0;
  for(int des: destination){
    res_sum+=res[des];
  }
  cout<<res_sum<<endl;

  return 0;
}

/*
 * 测试用例：
 *  2 1 1
 *  0 1 10
 *  1
 * 输出10
 *
 * 4 5 3
 * 0 1 15
 * 1 2 15
 * 0 3 50
 * 1 3 30
 * 2 3 10
 * 2
 * 1
 * 3
 *
 * 输出结果 85
 */