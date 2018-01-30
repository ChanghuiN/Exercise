//
// Created by ChanghuiN on 2018/1/4.
//

// 数值的整数次方，不考虑大数问题
#ifndef EXERCISE_POWER_H
#define EXERCISE_POWER_H


double Power(double base, int exponent);

double PowerWithUnsignedExponent(double base, unsigned int exponent);

bool equal(double num1, double num2);

void Test_Power(double base, int exponent, double expectedResult, bool expectedFlag);

void Test_11_Power();

#endif //EXERCISE_POWER_H
