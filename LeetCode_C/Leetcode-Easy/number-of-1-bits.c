//
//  number-of-1-bits.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "number-of-1-bits.h"


int hammingWeight(uint32_t n) {
    int result = 0;
    while (n > 0) {
        int temp = n % 2;
        if (temp == 1) {
            result ++;
        }
        n = n/2;
    }
    return result;
}