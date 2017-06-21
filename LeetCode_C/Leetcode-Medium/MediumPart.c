//
//  MediumPart.c
//  LeetCode_C
//
//  Created by Jue on 2017/6/21.
//  Copyright © 2017年 JUE DUKE. All rights reserved.
//

#include "MediumPart.h"


#pragma mark - 147. Insertion Sort List

//https://leetcode.com/submissions/detail/106806408/

struct ListNode* insertSortNode(struct ListNode *head, struct ListNode *node) {
    if (head == NULL) {
        return node;
    }
    if (node == NULL) {
        return head;
    }

    if (node->val < head->val) {
        node->next = head;
        return node;
    }

    struct ListNode *p = head;
    while (p) {
        if (p->next == NULL) {
            p->next = node;
            break;
        } else if (p->next->val > node->val) {
            node->next = p->next;
            p->next = node;
            break;
        }

        p = p->next;
    }
    return head;
}

//without space.
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    //initialize.
    struct ListNode* rest = head->next;
    head->next = NULL;
    
    while (rest) {
        struct ListNode* t = rest->next;
        rest->next = NULL;
        head = insertSortNode(head, rest);
        rest=t;
    }
    return head;
}

void run147() {
//    int input[] = {1,2,3,5,7,8};
    int *input = randomArray(6, 20);
    
    struct ListNode *head = createLinkList(input, 6);
    head = insertionSortList(head);
//    struct ListNode *node = createNode(3);
//    head = insertSortNode(head, node);
    printLinkList(head);
    
}

#pragma mark - GO

void runMediumPart() {
    run147();
}
