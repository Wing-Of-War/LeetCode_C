//
//  longest-substring-without-repeating-characters.c
//  LeetCode_C
//
//  Created by 张珏 on 15/12/9.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "longest-substring-without-repeating-characters.h"
#include "string.h"
#include "stdlib.h"


int lengthOfLongestSubstring(char* s) {
    long length = strlen(s);
    if (length < 2) {
        return (int)length;
    }
    long start=0, end=1, result=1;
    long temp;
    while (end < length) {
        int containt = 0;
        temp = start;
        while (temp < end) {
            if (s[temp] ==  s[end]) {
                containt = 1;
                break;
            }
            temp++;
        }
        if (containt) {
            start = temp + 1;
        }
        temp = end - start + 1;
        result = temp > result ? temp : result;
        end++;
    }
    return (int)result;
}