//
// Created by ChanghuiN on 2018/1/10.
//

#include <cstdio>
#include "StringToInt.h"


enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char *str) {
    g_nStatus = kInvalid;
    long long num = 0;

    if (str != NULL && *str != '\0') {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-') {
            str++;
            minus = true;
        }
        if (*str != '\0')
            num = StrToIntCore(str, minus);
    }
    return (int)num;
}

long long StrToIntCore(const char *digit, bool minus) {
    long long num = 0;
    while (*digit != '\0') {
        if (*digit >= '0' && *digit <= '9') {
            num = num * 10 + (*digit - '0');
            digit++;
        } else {
            num = 0;
            break;
        }
    }
    int flag = minus ? -1 : 1;
    num *= flag;
    if (*digit == '\0')
        g_nStatus = kValid;
    return num;
}

void Test_StringToInt(char *string) {

    int result = StrToInt(string);
    if (result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

void Test_49_StringToInt() {

    Test_StringToInt(NULL);
    Test_StringToInt("");
    Test_StringToInt("123");
    Test_StringToInt("+123");
    Test_StringToInt("-123");
    Test_StringToInt("1a33");
    Test_StringToInt("+0");
    Test_StringToInt("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test_StringToInt("+2147483647");
    Test_StringToInt("-2147483647");
    Test_StringToInt("+2147483648");

    //有效的最小负整数, 0x80000000
    Test_StringToInt("-2147483648");
    Test_StringToInt("+2147483649");
    Test_StringToInt("-2147483649");
    Test_StringToInt("+");
    Test_StringToInt("-");
}
