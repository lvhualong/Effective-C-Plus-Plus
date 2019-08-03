//
// Created by LAB540 on 2019/8/3.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


void Reverse(char* pStart, char* pEnd)
{
    if(pStart==NULL || pEnd == NULL)
        return;
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++; pEnd--;
    }
}

char* LeftRotateString(char* pDdat, unsigned int div)
{
    if(pDdat == NULL || div < 0)
        return pDdat;

    int length = strlen(pDdat);
    if(div > length)
        return NULL;

    char* pFirstStart = pDdat;
    char* pFirstEnd = pDdat + div - 1;
    char* pSecondStart = pDdat + div;
    char* pSecondEnd = pDdat + length -1;

    Reverse(pFirstStart, pFirstEnd);
    Reverse(pSecondStart, pSecondEnd);
    Reverse(pFirstStart, pSecondEnd);

    return  pDdat;
}

int main()
{
    char test[] = "abcdefg";
    char* result = LeftRotateString(test, 3);

    std::cout << "the result: "<< result << endl;
    return 0;
}
