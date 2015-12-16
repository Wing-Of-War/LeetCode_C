//
//  excel-sheet-column-number.c
//  LeetCode_C
//
//  Created by 张珏 on 15/12/16.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "excel-sheet-column-number.h"


int titleToNumber(char* s) {
    int result = 0;
    while(*s != '\0') {
        int value = *s - 'A' + 1;
        result = result * 26 + value;
        s++;
    }
    return result;
}