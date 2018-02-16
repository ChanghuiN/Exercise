//
// Created by ChanghuiN on 2018/1/5.
//

#include "KLeastNumbers.h"
#include "../Utilities/Array.h"


// 基于Partition函数的算法
void GetLeastNumbers_Solution1(int *input, int n, int *output, int k) {

    if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = Partition(input, n, start, end);
        } else {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for (int i = 0; i < k; i++)
        output[i] = input[i];
}

// 通过红黑数实现
void GetLeastNumbers_Solution2(const vector<int> &data, intSet &leastNumbers, int k) {
    leastNumbers.clear();

    if (k < 1 || data.size() < k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); iter++) {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else {
            setIterator iterGreatest = leastNumbers.begin();

            if (*iter < *(leastNumbers.begin())) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }

}

void Test_KLeastNumbers(char *testName, int *data, int n, int *expectedResult, int k) {

    if (testName != NULL)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for (int i = 0; i < n; ++i)
        vectorData.push_back(data[i]);

    if (expectedResult == NULL)
        printf("The input is invalid, we don't expect any result.\n");
    else {
        printf("Expected result: \n");
        for (int i = 0; i < k; ++i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int *output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if (expectedResult != NULL) {
        for (int i = 0; i < k; ++i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test_KLeastNumbers("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test_KLeastNumbers("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = NULL;
    Test_KLeastNumbers("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test_KLeastNumbers("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = NULL;
    Test_KLeastNumbers("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6_KLeastNumbers() {
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test_KLeastNumbers("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7_KLeastNumbers() {
    int *expected = NULL;
    Test_KLeastNumbers("Test7", NULL, NULL, expected, 0);
}

void Test_30_KLeastNumbers() {

    Test1_KLeastNumbers();
    Test2_KLeastNumbers();
    Test3_KLeastNumbers();
    Test4_KLeastNumbers();
    Test5_KLeastNumbers();
    Test6_KLeastNumbers();
    Test7_KLeastNumbers();
}