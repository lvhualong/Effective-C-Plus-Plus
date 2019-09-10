//
// Created by LAB540 on 2019/8/27.
//

/*
 *  对于序列S和T，它们之间距离定义为：对二者其一进行几次以下的操作
 *  (1)删去一个字符；(2)插入一个字符；(3)改变一个字符。
 *  每进行一次操作，计数增加1。
 *  将S和T变为同一个字符串的最小计数即为它们的距离。给出相应算法。

 */

/*
 * 解题思路：采用动态规划
 *
 */
#include <stdio.h>
#include <string.h>
#include <iostream>

using  namespace std;
#define MAXLEN 20
#define MATCH 0
#define INSERT 1
#define DELETE 2

typedef struct {
    int cost;
    int parent;
} cell;

cell m[MAXLEN+1][MAXLEN+1];

int match(char a,char b)
{
    //cost of match
    //match:    0
    //not match:1
    return (a==b)?0:1;
}

int string_compare(char *s,char *t)
{
    int i,j,k;
    int opt[3];

    //row_init(i);
    for(i=0;i<=MAXLEN;i++) {
        m[i][0].cost = i;
        if(i==0)
            m[i][0].parent = -1;
        else
            m[i][0].parent = INSERT;
    }

    //column_init(i);
    for(i=0;i<=MAXLEN;i++) {
        m[0][i].cost = i;
        if(i==0)
            continue;
        else
            m[0][i].parent = INSERT;
    }

    char m_s[MAXLEN+1] = " ",m_t[MAXLEN+1] =" ";
    strcat(m_s,s);
    strcat(m_t,t);

    for(i=1;i<=strlen(s);i++)
    {
        for(j=1;j<=strlen(t);j++) {
            opt[MATCH] = m[i-1][j-1].cost + match(m_s[i],m_t[j]);
            opt[INSERT] = m[i][j-1].cost + 1;
            opt[DELETE] = m[i-1][j].cost + 1;
            m[i][j].cost = opt[MATCH];
            m[i][j].parent = MATCH;
            for(k=INSERT;k<=DELETE;k++)
                if(opt[k]<m[i][j].cost)
                {
                    m[i][j].cost = opt[k];
                    m[i][j].parent = k;
                }
        }
    }
    i--,j--;
    return m[i][j].cost;
}

int main() {
    char t[] = "you should not";
    char p[] = "thou shalt not";

    int n = string_compare(t,p);
    cout << n << endl;
}
