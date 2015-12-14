//
//  median-of-two-sorted-arrays.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/8.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "median-of-two-sorted-arrays.h"
#include "stdlib.h"
#include "PublicUtilize.h"

void median_of_two_sorted_arrays_test() {
    int nums1Size = arc4random()%20;
    int nums2Size = arc4random()%20;
    int * nums1 = sortedArray(nums1Size);
    int * nums2 = sortedArray(nums2Size);
    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("median_of_two_sorted_arrays_test %lf", result);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int midIndex = (nums1Size + nums2Size)/2;
    
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