//
//  move-zeroes.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef move_zeroes_h
#define move_zeroes_h

//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
//
//Note:
//You must do this in-place without making a copy of the array.
//Minimize the total number of operations.

//https://leetcode.com/problems/move-zeroes/

#include <stdio.h>


void moveZeroesTest(void);
void moveZeroes(int* nums, int numsSize);

#endif /* move_zeroes_h */
