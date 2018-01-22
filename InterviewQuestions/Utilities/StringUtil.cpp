//
// Created by ChanghuiN on 2018/1/22.
//

#include <cstdlib>
#include "StringUtil.h"

void Reverse(char *pBegin, char *pEnd){
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    while(pBegin < pEnd) {
        char* tmp = pBegin;
        pBegin = pEnd;
        pEnd = tmp;
        pBegin++, pEnd--;
    }
}