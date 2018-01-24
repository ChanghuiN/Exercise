//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include <cassert>
#include "Fibonacci.h"


// 递归
long Fibonacci_Solution1(unsigned int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

// 循环
long Fibonacci_Solution2(unsigned n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    long fibNMinusOne = 0;
    long fibNMinusTwo = 1;
    long fibN = 0;
    for (int i = 2; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusOne = fibNMinusTwo;
        fibNMinusTwo = fibN;
    }
    return fibN;
}


struct Matrix2By2 {

    Matrix2By2(long m00 = 0, long m01 = 0, long m10 = 0, long m11 = 0)
            : m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}

    long m_00;
    long m_01;
    long m_10;
    long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2 &matrix1, const Matrix2By2 &matrix2) {
    return Matrix2By2(
            matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
            matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
            matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
            matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n) {
    assert(n > 0);

    Matrix2By2 matrix;
    if (n == 1) {
        matrix = Matrix2By2(1, 1, 1, 0);
    } else if (n % 2 == 0) {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    } else if (n % 2 == 1) {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

// 基于矩阵乘法
long Fibonacci_Solution3(unsigned int n) {
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

void Test_Fibonacci(int n, int expected) {

    if (Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if (Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if (Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

void Test_9_Fibonacci() {

    Test_Fibonacci(0, 0);
    Test_Fibonacci(1, 1);
    Test_Fibonacci(2, 1);
    Test_Fibonacci(3, 2);
    Test_Fibonacci(4, 3);
    Test_Fibonacci(5, 5);
    Test_Fibonacci(6, 8);
    Test_Fibonacci(7, 13);
    Test_Fibonacci(8, 21);
    Test_Fibonacci(9, 34);
    Test_Fibonacci(10, 55);

    Test_Fibonacci(40, 102334155);
}