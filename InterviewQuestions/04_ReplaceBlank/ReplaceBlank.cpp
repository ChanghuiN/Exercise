//
// Created by ChanghuiN on 17-11-15.
//

#include "ReplaceBlank.h"

#include <stdio.h>
#include <string.h>

/*length 为字符数组string的总容量*/
void ReplaceBlank(char str[], int length) {
    if (NULL == str)
        return;

    /*originalLength 为字符串string的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0') {
        originalLength++;
        if (str[i] == ' ') {
            numberOfBlank++;
        }
        i++;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (str[indexOfOriginal] == ' ') {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            str[indexOfNew--] = str[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}


void Test_ReplaceBlank(char *testName, char string[], int length, char expected[]) {
    if (testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if (expected == NULL && string == NULL)
        printf("passed.\n");
    else if (expected == NULL && string != NULL)
        printf("failed.\n");
    else if (strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1_ReplaceBlank() {
    const int length = 100;

    char string[length] = "hello world";
    Test_ReplaceBlank("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2_ReplaceBlank() {
    const int length = 100;

    char string[length] = " helloworld";
    Test_ReplaceBlank("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3_ReplaceBlank() {
    const int length = 100;

    char string[length] = "helloworld ";
    Test_ReplaceBlank("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4_ReplaceBlank() {
    const int length = 100;

    char string[length] = "hello  world";
    Test_ReplaceBlank("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5_ReplaceBlank() {
    Test_ReplaceBlank("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6_ReplaceBlank() {
    const int length = 100;

    char string[length] = "";
    Test_ReplaceBlank("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7_ReplaceBlank() {
    const int length = 100;

    char string[length] = " ";
    Test_ReplaceBlank("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8_ReplaceBlank() {
    const int length = 100;

    char string[length] = "helloworld";
    Test_ReplaceBlank("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9_ReplaceBlank() {
    const int length = 100;

    char string[length] = "   ";
    Test_ReplaceBlank("Test9", string, length, "%20%20%20");
}

void Test_4_ReplaceBlank() {
    Test1_ReplaceBlank();
    Test2_ReplaceBlank();
    Test3_ReplaceBlank();
    Test4_ReplaceBlank();
    Test5_ReplaceBlank();
    Test6_ReplaceBlank();
    Test7_ReplaceBlank();
    Test8_ReplaceBlank();
    Test9_ReplaceBlank();

}