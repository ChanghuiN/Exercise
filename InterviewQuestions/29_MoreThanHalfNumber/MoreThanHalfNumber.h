//
// Created by ChanghuiN on 2018/1/5.
//

// 数组中出现次数超过一半的数组
#ifndef EXERCISE_MORETHANHALFNUMBER_H
#define EXERCISE_MORETHANHALFNUMBER_H


// 检查无效的数组
bool CheckInvalidArray(int* numbers, int length);

// 检查数字是否为超出一半
bool CheckMoreThanHalf(int* numbers, int length, int number);

// 基于Partition函数的算法
int MoreThanHalfNum_Solution1(int* numbers, int length);

// 基于数组特点
int MoreThanHalfNum_Solution2(int* numbers, int length);

void Test_MoreThanHalfNumber(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag);

void Test_29_MoreThanHalfNumber();

#endif //EXERCISE_MORETHANHALFNUMBER_H
