//
// Created by changhuin on 18-1-6.
//

// 数组中只出现一次的数字(除了两个数字外，其他数字都出现了两次)
#ifndef EXERCISE_NUMBERSAPPEARONCE_H
#define EXERCISE_NUMBERSAPPEARONCE_H


// 寻找第一位bit为1的位数n
unsigned int FindFirstBitIs1(int num);

// 第n位是否为1
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2);

void Test_NumbersAppearOnce(char* testName, int data[], int length, int expected1, int expected2);

void Test_40_NumbersAppearOnce();

#endif //EXERCISE_NUMBERSAPPEARONCE_H
