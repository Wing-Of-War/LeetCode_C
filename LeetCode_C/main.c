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



bool isAnagram(char* s, char* t) {
    if (s == NULL && t == NULL ){
        return true;
    }
    
    size_t l1 = strlen(s);
    size_t l2 = strlen(t);
    
    if (l1 == 0 && l2 == 0) {
        return true;
    }
    if (l1 != l2) {
        return false;
    }
    char result[l1];
    for (int i = 0 ; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s[i] == t[j]) {
                result[j] = '1';
                break;
            }
        }
    }
    
    for (int i = 0; i < l2; i++) {
        if (result[i] != '1') {
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    //    linklist_test();
    char *s = "anagram";
    char *t = "nagaram";
    
    isAnagram(s, t);
    
#pragma mark - Leetcode
    //    testZigzag();
    //    testAddTowNumber();
    //    testTwoSum();
    //    sortedArray(10);
    
    
    
    
    
    //    moveZeroesTest();
    
    //    char *s = "anagram";
    //    char *t = "nagaram";
    //    char *s = "rat";
    //    char *t = "car";
    
    
    return 0;
}
