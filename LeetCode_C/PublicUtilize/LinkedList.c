//
//  LinkedList.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "LinkedList.h"
#include "stdlib.h"


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * result = NULL;
    struct ListNode * temp = head;
    while (temp) {
        struct ListNode *tt = temp->next;
        temp->next = result;
        result = temp;
        temp = tt;
    }
    return result;
}


struct ListNode *createNode(int value) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

void printLinkList(struct ListNode *head) {
    if (head == NULL) {
        return;
    }
    struct ListNode *t = head;
    printf("LinkList: ");
    do {
        printf("%d  ", t->val);
        t = t->next;
    } while (t);
    putchar('\n');
}


struct ListNode *createLinkList(int *nums, int size) {
    struct ListNode *previous = NULL;
    struct ListNode *head = NULL;
    for (int i = 0 ; i < size; i++) {
        struct ListNode *node = createNode(nums[i]);
        if (previous == NULL) {
            previous = node;
            head = node;
        } else {
            previous->next = node;
            previous = node;
        }
    }
    printLinkList(head);
    return head;
}
