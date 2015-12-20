//
//  valid-anagram.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef valid_anagram_h
#define valid_anagram_h


//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//Note:
//You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <stdio.h>
#include "stdbool.h"

void testAnagram(void);
bool isAnagram(char* s, char* t);

#endif /* valid_anagram_h */
