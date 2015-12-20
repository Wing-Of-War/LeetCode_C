//
//  reverse-linked-list.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "reverse-linked-list.h"
#include "LinkedList.h"
#include "stdlib.h"



void testReverseList(void) {
    const int size = 6;
    int input[size] = {1,2,3,4,5,6};
    struct ListNode *node = createLinkList(input, size);
    showLinkList(reverseList(node));
}


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