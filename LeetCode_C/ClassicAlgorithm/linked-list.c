//
//  linked-list.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/1.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "linked-list.h"
#include <assert.h>
#include <stdlib.h>


void linklist_test(void) {
    linknodep node = NULL;
    
    int i = 0;
    
    
    printf("insert_head test \n");
    //insertHead
    for (i=0; i<10; i++) {
        linknodep newnode =(linknodep)malloc(sizeof(linknode));
        newnode->data = rand() % 100;
        newnode->next = NULL;
//        head =
        node = insert_head(node, newnode);
        output(node);
    }
    
    
    printf("insert_tail test \n");
    node = NULL;
    //insertTail
    for (i = 0; i< 10; i++) {
        linknodep newnode = (linknodep)malloc(sizeof(linknode));
        newnode->data = rand() % 100;
        newnode->next = NULL;
        node = insert_tail(node, newnode);
        output(node);
    }
    
    printf("insert_local test \n");
    node = NULL;
    for (i = 0; i< 10; i++) {
        linknodep newnode = (linknodep)malloc(sizeof(linknode));
        newnode->data = rand() % 100;
        newnode->next = NULL;
        int size = size_of_linknode(node);
        int index = size ? (rand() % size) + 1 : 0;
        node = insert_local(node, newnode, index);
        printf("insert index: %d ___", index);
        output(node);
    }
    
    int data = 0;
    printf("pls input need del data");
    scanf("%d", &data);
    linknodep temp = delnode(node, data);
    if (temp) {
        output(temp);
    } else {
        
    }
    
    
}

linknodep delnode(linknodep head, int data) {
    if (head == NULL) {
        return NULL;
    }
    linknodep temp = head;
    if (temp->data == data) {
        head = head->next;
        free(temp);
        return head;
    }

    linknodep pre = temp;
    //find the location of data.
    while (temp && temp->data != data) {
        pre = temp;
        temp = temp->next;
    }
    
    if (temp==NULL) {
        return NULL;
    }
    
    pre->next = temp->next;
    free(temp);
    
    return head;
}

void output(linknodep head) {
    linknodep temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int size_of_linknode(linknodep head) {
    int result = 0;
    linknodep temp = head;
    while (temp) {
        result ++;
        temp = temp->next;
    }
    return result;
}

linknodep insert_head(linknodep head, linknodep newnode) {
//    assert(head);
    assert(newnode);
    newnode->next = head;
    head = newnode;
    return head;

}
linknodep insert_tail(linknodep head, linknodep newnode) {
    assert(newnode);
    if (head==NULL) {
        return newnode;
    }
    linknodep temp = head;
    while (temp->next) {
        temp=temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return head;
}


linknodep insert_local(linknodep head, linknodep newnode, int index) {
    assert(newnode);
    //add to head.
    if (index == 0) {
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    
    //add in the mid.
    int currentIndex = 0;
    linknodep temp = head;
    while (temp->next) {
        currentIndex ++;
        if (currentIndex == index) {
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    
    //add to tail. currentIndex will never equal to index(Becasue it will add to the mid).
    if (currentIndex+1 == index) {
        temp->next = newnode;
    }
    
    return head;
}