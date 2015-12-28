//
//  Linked List Cycle II.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/28.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "Linked List Cycle II.h"
#include "LinkedList.h"
#include "stdbool.h"


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    do {
        if((p2 == NULL) || (p2->next == NULL)) {
            return NULL;
        }
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }while(p1 != p2);
    for(p1 = head; p1 != p2 ; p1 = p1 -> next, p2 = p2 -> next){
        
    }
    return p1;
}