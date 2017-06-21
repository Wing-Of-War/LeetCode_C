//
//  LeetcodeHardPart.c
//  LeetCode_C
//
//  Created by Jue on 2016/10/31.
//  Copyright © 2016年 JUE DUKE. All rights reserved.
//

#include "HardPart.h"
#include <stdlib.h>


#pragma mark - 4. Median of Two Sorted Arrays
//https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1[nums1Size-1] <= nums2[0]) {
        return (nums1[nums1Size-1] + nums2[0])/2.0;
    }
    if (nums2[nums2Size-1] <= nums1[0]) {
        return (nums2[nums2Size-1] + nums1[0])/2.0;
    }
    
    
    
    return 0;
}

void run4() {
    int nums1Size = arc4random()%6;
    int nums2Size = arc4random()%6;
    int * nums1 = sortedArray(nums1Size);
    int * nums2 = sortedArray(nums2Size);
    
    printArray(nums1, nums1Size);
    printArray(nums2, nums2Size);
    
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("median_of_two_sorted_arrays_test %lf", result);
}

#pragma mark - Go

void runHardPart() {
    run4();
}
