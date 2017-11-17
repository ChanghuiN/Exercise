//
// Created by ChanghuiN on 17-11-15.
//

#include "FindInPartiallySortedMatrix.h"

#include <stdio.h>
#include <stdbool.h>

// 二维数组matrix中，每一行都从左到右递增排序，
// 每一列都从上到下递增排序
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if (NULL != matrix && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            int value = matrix[row * columns + column];
            if (value == number) {
                found = true;
                break;
            } else if (value > number) {
                --column;
            } else {
                ++row;
            }
        }
    }
    return found;
}

// ====================测试代码====================
void Test_FindInPartiallySortedMatrix(char *testName, int *matrix, int rows, int columns, int number, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    bool result = Find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test1", (int *) matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test2", (int *) matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test3", (int *) matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test4", (int *) matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test5", (int *) matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6_FindInPartiallySortedMatrix()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test_FindInPartiallySortedMatrix("Test6", (int *) matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7_FindInPartiallySortedMatrix()
{
    Test_FindInPartiallySortedMatrix("Test7", NULL, 0, 0, 16, false);
}

void Test_3_FindInPartiallySortedMatrix()
{
    Test1_FindInPartiallySortedMatrix();
    Test2_FindInPartiallySortedMatrix();
    Test3_FindInPartiallySortedMatrix();
    Test4_FindInPartiallySortedMatrix();
    Test5_FindInPartiallySortedMatrix();
    Test6_FindInPartiallySortedMatrix();
    Test7_FindInPartiallySortedMatrix();

}