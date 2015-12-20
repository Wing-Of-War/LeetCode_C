//
//  remove-duplicates-from-sorted-list.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "remove-duplicates-from-sorted-list.h"
#include "LinkedList.h"
#include "stdlib.h"

void testDeleteDuplicates() {
    
    int nums[] = {1,1,2,3,3};
    struct ListNode *list = createLinkList(nums, 5);
    showLinkList(deleteDuplicates(list));
    
//    int nums[] = {1};
//    struct ListNode *list = createLinkList(nums, 1);
//    showLinkList(deleteDuplicates(list));

//    int nums[] = {};
//    struct ListNode *list = createLinkList(nums, 0);
//    showLinkList(deleteDuplicates(list));

//    int nums[] = {1,1,1,1,1};
//    struct ListNode *list = createLinkList(nums, 5);
//    showLinkList(deleteDuplicates(list));

}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;
    if (temp == NULL) {
        return NULL;
    }
    while (temp->next) {
        struct ListNode *t = NULL;
        if (temp->val == temp->next->val) {
            t = temp->next;
            temp->next = t->next;
        } else {
            temp = temp->next;
        }
        
        
        //with free 8.00ms. without 4.00ms
        if (t) {
            free(t);
        }
    }
    
    return head;
}