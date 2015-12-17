//
//  ugly-number.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "ugly-number.h"
#include <stdbool.h>

bool isUgly(int num) {
    if (num <= 0) {
        return false;
    }
    
    if (num % 2 == 0) {
        return isUgly(num/2);
    }
    if (num % 3 == 0) {
        return isUgly(num/3);
    }
    if (num % 5 == 0) {
        return isUgly(num/5);
    }
    if (num == 1) {
        return true;
    } else {
        return false;
    }
}