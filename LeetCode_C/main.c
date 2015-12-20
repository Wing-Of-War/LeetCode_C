//
//  main.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/11/28.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "linked-list.h"

#pragma mark - Leetcode
#include "zigzag-conversion.h"
#include "two-sum.h"
#include "add-two-numbers.h"
#include "longest-substring-without-repeating-characters.h"

#include "string.h"
//#include "median-of-two-sorted-arrays.h"
#include "move-zeroes.h"

#include "valid-anagram.h"

#include "compare-version-numbers.h"

#include "lowest-common-ancestor-of-a-binary-search-tree.h"

int countPrimes(int n) {
    if (n == 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    return 0;
}

int majorityElement(int* nums, int numsSize) {
    
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    
    
    
#pragma mark - Leetcode
    //    testZigzag();
    //    testAddTowNumber();
    //    testTwoSum();
    //    sortedArray(10);
    
//    testAnagram();
    
    
    
    //    moveZeroesTest();
    
    //    char *s = "anagram";
    //    char *t = "nagaram";
    //    char *s = "rat";
    //    char *t = "car";
//    testCompareVersion();
    testLowestCommonAncestor();
    return 0;
}
