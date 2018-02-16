//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "FirstNotRepeatingChar.h"


char FirstNotRepeatingChar(char* pString) {
    if (pString == NULL)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;

    char *pHashKey = pString;
    while (*pHashKey != '\0')
        hashTable[*(pHashKey++)]++;

    pHashKey = pString;
    while (*pHashKey != '\0') {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }

    return '\0';
}

void Test_FirstNotRepeatingChar(char* pString, char expected) {

    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

void Test_35_FirstNotRepeatingChar() {

    // 常规输入测试，存在只出现一次的字符
    Test_FirstNotRepeatingChar("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test_FirstNotRepeatingChar("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test_FirstNotRepeatingChar("abcdefg", 'a');

    // 鲁棒性测试，输入NULL
    Test_FirstNotRepeatingChar(NULL, '\0');
}