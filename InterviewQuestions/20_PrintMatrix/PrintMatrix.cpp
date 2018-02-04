//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "PrintMatrix.h"


// 一圈一圈循环
void PrintMatrixClockwisely(int **numbers, int columns, int rows) {
    if (numbers == NULL || columns <= 0 || rows <= 0)
        return;

    int start = 0;
    while (columns > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }
}

// 打印一圈
void PrintMatrixInCircle(int **numbers, int columns, int rows, int start) {

    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印一行
    for (int i = start; i <= endX; ++i) {
        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列
    if (start < endY) {
        for (int i = start + 1; i <= endY; ++i) {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if (start < endX && start < endY) {
        for (int i = endX - 1; i >= start; --i) {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一行
    if (start < endX && start < endY - 1) {
        for (int i = endY - 1; i >= start + 1; --i) {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void printNumber(int number) {
    printf("%d\t", number);
}

void Test_PrintMatrix(int columns, int rows) {

    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if (columns < 1 || rows < 1)
        return;

    int **numbers = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        numbers[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for (int i = 0; i < rows; ++i)
        delete[] (int *) numbers[i];

    delete[] numbers;
}

void Test_20_PrintMatrix() {

    /*
    1
    */
    Test_PrintMatrix(1, 1);

    /*
    1    2
    3    4
    */
    Test_PrintMatrix(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test_PrintMatrix(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test_PrintMatrix(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test_PrintMatrix(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test_PrintMatrix(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test_PrintMatrix(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test_PrintMatrix(4, 5);

    /*
    1    2    3    4    5
    */
    Test_PrintMatrix(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test_PrintMatrix(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test_PrintMatrix(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test_PrintMatrix(5, 4);
}