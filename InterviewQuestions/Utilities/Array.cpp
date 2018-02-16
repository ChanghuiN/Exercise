//
// Created by ChanghuiN on 2018/2/5.
//

#include <cstdlib>
#include "Array.h"


int RandomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int data[], int length, int start, int end) {

    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw "Invalid Parameters";

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; ++ index) {
        if (data[index] < data[end]) {
            small++;
            if (small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}