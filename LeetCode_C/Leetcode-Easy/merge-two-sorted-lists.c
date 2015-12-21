//
//  merge-two-sorted-lists.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "merge-two-sorted-lists.h"
#include "LinkedList.h"
#include "NumberArray.h"

void testMergeTwoLists() {
    int *nums1 = sortedArray(4);
    int *nums2 = sortedArray(6);
    struct ListNode *node1 = createLinkList(nums1, 4);
    struct ListNode *node2 = createLinkList(nums2, 6);
    struct ListNode *node3 = mergeTwoLists(node1, node2);
    showLinkList(node3);
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode *result = NULL;
    struct ListNode *head = NULL;
    
    while (p1 && p2) {
        int value1 = p1->val;
        int value2 = p2->val;
        struct ListNode *t =  value1 > value2 ? p2 : p1;
        if (value1 > value2) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }

        if (result) {
            result->next = t;
            result = result->next;
        } else {
            result = t;
            head = t;
        }
        
    }
    if (p1 == NULL) {
        result->next = p2;
    } else {
        result->next = p1;
    }
    
    return head;
}