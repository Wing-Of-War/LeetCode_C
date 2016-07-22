//
//  remove-element.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/3/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "remove-element.h"
#include "NumberArray.h"

void testRemoveElement(void) {
    int nums[] = {1,2,3,4,5,6,6,7};
    int size = sizeof(nums) / sizeof(int);
    int length = removeElement(nums, size, 6);
    printArray(nums, size);
    printf("length %d", length);
}

int removeElement(int* nums, int numsSize, int val) {
    int duplicateCount = 0;
    for (int i = 0 ; i < numsSize - duplicateCount;) {
        if (nums[i] != val) {
            i++;
            continue;
        }
        for (int j = i; j < numsSize - duplicateCount - 1; j++) {
            nums[j] = nums[j+1];
        }
        duplicateCount++;
    }
    return numsSize - duplicateCount;
}