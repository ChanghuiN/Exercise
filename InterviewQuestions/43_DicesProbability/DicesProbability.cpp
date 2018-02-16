//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include <cmath>
#include "DicesProbability.h"

int g_maxValue = 6;

void PrintProbability_Solution2(int number) {

    if (number < 1)
        return;

    int *pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for (int i = 0; i < g_maxValue * number + 1; ++i) {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i)
        pProbabilities[flag][i] = 1;

    for (int k = 2; k <= number; ++k) {
        for (int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) {
            pProbabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= g_maxValue; ++j)
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }

        flag = 1 - flag;
    }

    double total = pow((double) g_maxValue, number);
    for (int i = number; i <= g_maxValue * number; ++i) {
        double ratio = (double) pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

void Test_DicesProbability(int n) {

    printf("Test for %d begins:\n", n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

void Test_43_DicesProbability() {

    Test_DicesProbability(1);
    Test_DicesProbability(2);
    Test_DicesProbability(3);
    Test_DicesProbability(4);

    Test_DicesProbability(11);

    Test_DicesProbability(0);
}