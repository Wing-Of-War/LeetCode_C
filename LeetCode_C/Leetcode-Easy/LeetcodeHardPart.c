//
//  LeetcodeHardPart.c
//  LeetCode_C
//
//  Created by Jue on 2016/10/31.
//  Copyright © 2016年 JUE DUKE. All rights reserved.
//

#include "LeetcodeHardPart.h"
#include <stdlib.h>

#pragma mark - 4. Median of Two Sorted Arrays
//https://leetcode.com/problems/median-of-two-sorted-arrays/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    int midIndex = (nums1Size + nums2Size)/2;
    
    double result = 0;
    int vm1 = nums1[nums1Size/2];
    int vm2 = nums2[nums2Size/2];
    
    int *p;
    int t;
    if (vm1 > vm2) {
        p = nums1;
        nums1 = nums2;
        nums2 = p;
        t = nums1Size;
        nums1Size = nums2Size;
        nums2Size = t;
    }
    vm1 = nums1[nums1Size/2];
    vm2 = nums2[nums2Size/2];
    while (vm1 < vm2) {
        
    }
    
    return result;
}

void run4() {
    int nums1Size = arc4random()%20;
    int nums2Size = arc4random()%20;
    int * nums1 = sortedArray(nums1Size);
    int * nums2 = sortedArray(nums2Size);
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("median_of_two_sorted_arrays_test %lf", result);
}
