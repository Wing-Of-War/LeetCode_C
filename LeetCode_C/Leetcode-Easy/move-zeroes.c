//
//  move-zeroes.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "move-zeroes.h"
#include "NumberArray.h"

void moveZeroesTest(void) {
    int arraySize = 10;
    int *input = randomArray(arraySize);
    
    input[1] = 0;
    input[5] = 0;
    outputArray(input, arraySize);
    moveZeroes(input, arraySize);
    outputArray(input, arraySize);
}

void moveZeroes(int* nums, int numsSize) {
    int currentZeroCount = 0;
    int currentIndex = 0;
    while (currentIndex < numsSize) {
        if (nums[currentIndex]) {
            nums[currentIndex-currentZeroCount] = nums[currentIndex];
        } else {
            currentZeroCount ++;
        }
        currentIndex++;
    }
    currentIndex = numsSize - currentZeroCount;
    while (currentIndex < numsSize) {
        nums[currentIndex]=0;
        currentIndex++;
    }
}