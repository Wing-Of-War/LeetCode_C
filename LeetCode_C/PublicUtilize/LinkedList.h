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

struct ListNode *newNode(int value) ;
void showLinkList(struct ListNode *head) ;
struct ListNode *createLinkList(int *nums, int size) ;

#endif /* LinkedList_h */
