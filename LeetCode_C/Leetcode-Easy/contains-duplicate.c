//
//  contains-duplicate.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "contains-duplicate.h"
#include <stdbool.h>

//Slow.
bool containsDuplicate(int* nums, int numsSize) {
    int currentIndex = 0;
    while(currentIndex < numsSize) {
        for(int i = 0; i < currentIndex; i++) {
            if (nums[i] == nums[currentIndex]) {
                return true;
            }
        }
        currentIndex ++;
    }
    return false;
}