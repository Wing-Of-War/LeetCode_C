//
//  add-two-numbers.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/1.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "add-two-numbers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */


void testAddTowNumber(void) {
//    int input1[] = {2,4,3,-1};
//    int input2[] = {5,6,4,-1};
    int input1[] = {5,-1};
    int input2[] = {5,-1};

    struct ListNode *inputList1 = createByArray(input1);
    struct ListNode *inputList2 = createByArray(input2);
    showListNode(inputList1);
    putchar('\n');
    showListNode(inputList2);
    putchar('\n');

    
    struct ListNode *result = addTwoNumbers(inputList1, inputList2);
    showListNode(result);
    
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    
    int sum = l1->val + l2->val;
    int val = sum % 10;
    _Bool haveMore = sum / 10;

    
    struct ListNode *head =  (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = val;
    head->next = NULL;
    
    struct ListNode *temp = head;
    while (l1->next || l2 -> next || haveMore) {
        sum = 0;
        if (l1->next) {
            l1 = l1->next;
            sum += l1->val;
        }
        if (l2->next) {
            l2 = l2->next;
            sum += l2->val;
        }
        sum += haveMore;
        val = sum % 10;
        haveMore = sum / 10;
        struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = val;
        
        
        temp->next = node;
        temp = node;
    }
    return head;
}

void showListNode(struct ListNode *node) {
    struct ListNode *temp = node;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

struct ListNode * createByArray(int numbers[]){
    int *p = numbers;
    struct ListNode *head = NULL;
    struct ListNode *temp = head;
    while (*p>0) {
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val = *p;
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next=newnode;
            temp=newnode;
        }
        p++;
    }
    return head;
}