//
//  linked-list.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/1.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

typedef  struct linklist {
    int data;
    struct linklist *next;
} linknode, *linknodep;


void linklist_test(void);

linknodep insert_head(linknodep, linknodep);
linknodep insert_tail(linknodep, linknodep);
linknodep insert_local(linknodep, linknodep, int);

linknodep delnode(linknodep, int);

void output(linknodep head);
int size_of_linknode(linknodep head);
#endif /* linked_list_h */
