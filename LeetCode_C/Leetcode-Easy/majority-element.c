//
//  majority-element.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/3/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "majority-element.h"


int majorityElement(int* nums, int numsSize) {
    int result = 0;
    int count = 0;
    for(int i = 0; i<numsSize; i++) {
        if(count == 0) {
            result = nums[i];
            count ++;
        } else {
            int number = nums[i];
            if (number == result) {
                count ++;
            } else {
                count --;
            }
        }
    }
    return result;
}