//
// Created by ChanghuiN on 2018/1/5.
//

#include <cstdio>
#include "StringPermutation.h"


void Permutation(char *pStr) {
    if (pStr == NULL)
        return;

    Permutation(pStr, pStr);
}

void Permutation(char *pStr, char *pBegin) {

    if (*pBegin == '\0')
        printf("%s\n", pStr);
    else
        for (char *pCh = pBegin; *pCh != '\0'; ++pCh) {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
}

void Test_StringPermutation(char *pStr) {

    if (pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

void Test_28_StringPermutation() {

    Test_StringPermutation(NULL);

    char string1[] = "";
    Test_StringPermutation(string1);

    char string2[] = "a";
    Test_StringPermutation(string2);

    char string3[] = "ab";
    Test_StringPermutation(string3);

    char string4[] = "abc";
    Test_StringPermutation(string4);
}