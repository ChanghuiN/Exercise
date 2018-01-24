//
// Created by ChanghuiN on 2018/1/4.
//

// 斐波那契数列
// f(n) = 0                 n = 0
//      = 1                 n = 1
//      = f(n-1)+f(n-2)     n > 1
#ifndef EXERCISE_FIBONACCI_H
#define EXERCISE_FIBONACCI_H


// 递归
long Fibonacci_Solution1(unsigned int n);

// 循环
long Fibonacci_Solution2(unsigned n);

// 基于矩阵乘法
long Fibonacci_Solution3(unsigned int n);

void Test_Fibonacci(int n, int expected);

void Test_9_Fibonacci();


#endif //EXERCISE_FIBONACCI_H
