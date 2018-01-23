//
// Created by ChanghuiN on 17-11-15.
//

// 二维数组matrix中，每一行都从左到右递增排序，
// 每一列都从上到下递增排序
// 查找一个数字是否在该数组
#ifndef EXERCISE_FINDINPARTIALLYSORTEDMATRIX_H
#define EXERCISE_FINDINPARTIALLYSORTEDMATRIX_H

bool Find(int *matrix, int rows, int columns, int number);

void Test_FindInPartiallySortedMatrix(char *testName, int *matrix, int rows, int columns, int number, bool expected);

void Test_3_FindInPartiallySortedMatrix();

#endif //EXERCISE_FINDINPARTIALLYSORTEDMATRIX_H
