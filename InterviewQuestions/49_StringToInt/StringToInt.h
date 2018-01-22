//
// Created by ChanghuiN on 2018/1/10.
//

// 把字符串转换为整数
#ifndef EXERCISE_STRINGTOINT_H
#define EXERCISE_STRINGTOINT_H


long long StrToIntCore(const char* str, bool minus);

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str);

void Test_StringToInt(char* string);

void Test_49_StringToInt();

#endif //EXERCISE_STRINGTOINT_H
