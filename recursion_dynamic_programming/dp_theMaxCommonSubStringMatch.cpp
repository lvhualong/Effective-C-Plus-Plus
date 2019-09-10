//
// Created by LAB540 on 2019/8/27.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int lastSubString(string s1, string s2, string& sub_str) {


  string temp_str;
  string max_str;
  for(int i=0; i<s1.length(); i++){
    for(int j=0; j<s2.length(); j++){
      while(s1[i] == s2[j]){
//        cout << "s1: " << s1[i] << "s2: "<<s2[j] << endl;
        temp_str.push_back(s1[i]);
        if(i<s1.length()-1 && j<s2.length()-1)
          i++; j++;
      }
//      cout << "temp: "<< temp_str << " max: " << max_str << endl;
      if(temp_str.length() > max_str.length())
        max_str = temp_str;

      temp_str.clear();
    }
  }
  sub_str = max_str;
  return  max_str.length();
}





int main() {
    string s1 = "you should not";
    string s2 = "thou shalt not";


    string subStr;
    lastSubString(s1, s2, subStr);
    cout << "the sub string: " << subStr << endl;
}
