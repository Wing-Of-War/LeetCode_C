//
//  two-sum.c
//  LeetCode_C
//
//  Created by 张珏 on 15/12/2.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "two-sum.h"
#include <stdlib.h>


void testTwoSum() {
    
    int numbers[3] = {3,2,4};
    int target = 6;
    //Expected: 2,3
    
//    int numbers[4] = {2,7,11,15};
//    int target = 9;
    //Expected: 1,2
    
    int *result = twoSum(numbers, 4, target);
    printf("index1 = %d, index2 = %d", result[0], result[1]);

}


int* twoSum(int* nums, int numsSize, int target) {
    int * reuslt = (int *)malloc(sizeof(int[2]));
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                reuslt[0] = i+1;
                reuslt[1] = j+1;
                break;
            }
        }
    }
    return reuslt;
}