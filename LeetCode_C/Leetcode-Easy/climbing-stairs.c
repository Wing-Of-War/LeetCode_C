//
//  climbing-stairs.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "climbing-stairs.h"
#include "stdlib.h"


void testClimbStairs() {
    for (int i = 1 ; i < 45; i++) {
        int result = climbStairs(i);
        printf("input %d result %d \n", i, result);
    }
    
}
int climbStairs(int n) {
    if (n<3) {
        return n;
    }
    
    int *keep = (int *)malloc(sizeof(int) * n);
    keep[0] = 1;
    keep[1] = 2;
    
    int i = 2;
    int sum = 0;
    while (i < n) {
        sum = keep[i-1] + keep[i-2];
        keep[i] = sum;
        i++;
    }
    return sum;
}
