//
// Created by ChanghuiN on 2018/1/4.
//

// 顺时针打印矩阵
#ifndef EXERCISE_PRINTMATRIX_H
#define EXERCISE_PRINTMATRIX_H


// 一圈一圈循环
void PrintMatrixClockwisely(int** numbers, int columns, int rows);

// 打印一圈
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);

void Test_PrintMatrix(int columns, int rows);

void Test_20_PrintMatrix();

#endif //EXERCISE_PRINTMATRIX_H
