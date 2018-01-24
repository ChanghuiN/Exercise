//
// Created by ChanghuiN on 2018/1/4.
//

// 旋转数组的最小值
#ifndef EXERCISE_MINNUMBERINROTATEDARRAY_H
#define EXERCISE_MINNUMBERINROTATEDARRAY_H

int Min(int* numbers, int length);

// 顺序查找
int MinInOrder(int* numbers, int index1, int index2);

void Test_MinNumberInRotatedArray(int* numbers, int length, int expected);

void Test_8_MinNumberInRotatedArray();

#endif //EXERCISE_MINNUMBERINROTATEDARRAY_H
