//
// 有一个很大的文本文件，里面包含许多英文单词。给出两个单词，找到它们的最短距离
//
// 例如 What is your name My name is Judy
// name 和 is的距离最近

#include <string>
#include <iostream>

using namespace std;


int ShortestDist(string text[], int n, string word1, string word2){
  int min = INT16_MAX / 2;
  int pos1 = -min;
  int pos2 = -min;

  for(int pos=0; pos<n; ++pos)
  {
    if(text[pos] == word1){
      pos1 = pos;
      int dist = pos1 - pos2;
      if(dist < min)
        min = dist;
    }
    else if(text[pos] == word2){
      pos2 = pos;
      int dist = pos2 - pos1;
      if(dist < min)
        min = dist;
    }
  }
  return min;
}

int main()
{
  string input[] = {"What", "is",  "your",  "name", "My",  "name", "is", "Judy"};

  string word1 = "is";
  string word2 = "My";

  int result = ShortestDist(input, 8, word1, word2);
  cout  << "the shortest dist: " << result << endl;
}