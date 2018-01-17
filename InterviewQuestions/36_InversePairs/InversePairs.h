//
// Created by changhuin on 18-1-6.
//

// 数组中的逆序对
#ifndef EXERCISE_INVERSEPAIRS_H
#define EXERCISE_INVERSEPAIRS_H


int InversePairs(int* data, int length);

int InversePairsCore(int* data, int* copy, int start, int end);

void Test_InversePairs(char* testName, int* data, int length, int expected);

void Test_36_InversePairs();

#endif //EXERCISE_INVERSEPAIRS_H
