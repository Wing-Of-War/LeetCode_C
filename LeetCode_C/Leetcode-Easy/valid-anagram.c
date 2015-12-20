//
//  valid-anagram.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "valid-anagram.h"
#include "string.h"


void testAnagram(void) {
    
//    char *s = "anagram";
//    char *t = "nagaram";

    char *s = "";
    char *t = "";
    bool result = isAnagram(s, t);
    printf("result %d", result);
}

bool isAnagram(char* s, char* t) {
    int count1[26] = {0};
    int count2[26] = {0};
    
    char *p = s;
    while (*p != '\0') {
        count1[*p - 'a']++;
        p++;
    }
    p = t;
    while (*p != '\0') {
        count2[*p - 'a']++;
        p++;
    }
    for (int i = 0 ; i < 26 ; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    
    return true;
}