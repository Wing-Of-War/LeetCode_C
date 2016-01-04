//
//  remove-duplicates-from-sorted-array.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/4/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "remove-duplicates-from-sorted-array.h"
#include "NumberArray.h"
void testRemoveDuplicatesFromSortedArray(void) {
//    int *nums = sortedArray(10);
    const int size = 10;
    int nums[size] = {1,1,1,2,2,2,3,3,3,3};
    outputArray(nums, size);
    int length = removeDuplicates(nums, size);
    outputArray(nums, length);
}



int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }
    
    int duplicateCount = 0;
    int lastNum = nums[0];
//    for (int i = 1 ; i < numsSize; i++) {
//        if(nums[i] == lastNum) {
//            duplicateCount++;
//            continue;
//        }
//        nums[i-duplicateCount] = nums[i];
//        lastNum = nums[i];
//    }

    //Faster than continue.
    for (int i = 1 ; i < numsSize; i++) {
        if(nums[i] == lastNum) {
            duplicateCount++;
        } else {
            nums[i-duplicateCount] = nums[i];
            lastNum = nums[i];
        }
    }

    
    return numsSize - duplicateCount;
}