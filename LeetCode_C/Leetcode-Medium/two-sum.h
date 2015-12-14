//
//  two-sum.h
//  LeetCode_C
//
//  Created by 张珏 on 15/12/2.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef two_sum_h
#define two_sum_h

#include <stdio.h>

//https://leetcode.com/problems/two-sum/

/*
     Given an array of integers, find two numbers such that they add up to a specific target number.
     
     The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
     
     You may assume that each input would have exactly one solution.
     
     Input: numbers={2, 7, 11, 15}, target=9
     Output: index1=1, index2=2
     
     Subscribe to see which companies asked this question
 */

void testTwoSum();

int* twoSum(int* nums, int numsSize, int target);

#endif /* two_sum_h */
