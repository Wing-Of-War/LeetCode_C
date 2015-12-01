//
//  add-two-numbers.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/1.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef add_two_numbers_h
#define add_two_numbers_h

//https://leetcode.com/problems/add-two-numbers/

/*
    You are given two linked lists representing two non-negative numbers. 
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

    Subscribe to see which companies asked this question
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void testAddTowNumber(void);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode * createByArray(int numbers[]);
void showListNode(struct ListNode *node);
#endif /* add_two_numbers_h */
