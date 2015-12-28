//
//  Linked List Cycle.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/28.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "Linked List Cycle.h"
#include "LinkedList.h"
#include "stdbool.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    do {
        if((p2== NULL) || (p2->next == NULL)) {
            return false;
        }
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }while(p1 != p2);
    
    return true;
}