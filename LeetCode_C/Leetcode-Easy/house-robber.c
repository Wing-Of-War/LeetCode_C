//
//  house-robber.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/4/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "house-robber.h"
#include <stdio.h>

void testHouseRobber(void) {
    int nums[100] = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    
    int size = 0;
    while (1) {
        if (nums[size] == 124) {
            break;
        }
        size ++;
    }

//    int size = sizeof(nums)/sizeof(int);
    int result = rob(nums, size);
    printf("result %d", result);
}


int rob(int* nums, int numsSize) {
    int odd = 0,even = 0;
    for (int i = 0 ; i < numsSize ; i++) {
        if (i%2) {
            int value = odd + nums[i];
            odd = value > even ? value : even;
        } else {
            int value = even + nums[i];
            even = value > odd ? value : odd;
        }
    }
    return odd>even?odd:even;
}