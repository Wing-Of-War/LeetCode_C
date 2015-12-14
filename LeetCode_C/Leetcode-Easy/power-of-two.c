//
//  power-of-two.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "power-of-two.h"
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if(n==0 || n < 0) {
        return false;
    }
    if(n==1 || n==2) {
        return true;
    }
    int t = n;
    while(t>2) {
        int rest = t % 2;
        if (rest) {
            return false;
        }
        t=t/2;
    }
    
    return true;
}