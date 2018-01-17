//
// Created by ChanghuiN on 2018/1/5.
//

// 最小的k个数
#ifndef EXERCISE_KLEASTNUMBERS_H
#define EXERCISE_KLEASTNUMBERS_H

using namespace std;

#include <vector>
#include <set>


// 基于Partition函数的算法
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k);

// 通过红黑数实现
typedef multiset<int, greater<int> >            intSet;
typedef multiset<int, greater<int> >::iterator  setIterator;
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k);

void Test_KLeastNumbers(char* testName, int* data, int n, int* expectedResult, int k);

void Test_30_KLeastNumbers();

#endif //EXERCISE_KLEASTNUMBERS_H
