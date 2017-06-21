//
//  LinkedList.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int value) ;
struct ListNode *createLinkList(int *nums, int size) ;
struct ListNode* reverseList(struct ListNode* head);

void printLinkList(struct ListNode *head) ;

#endif /* LinkedList_h */
