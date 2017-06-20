//
//  Utilize.c
//  LeetCode_C
//
//  Created by Jue on 2017/6/20.
//  Copyright © 2017年 JUE DUKE. All rights reserved.
//

#include "Utilize.h"


int cmpfunc(const void *a, const void *b) {
    if (*(int *)b > *(int *)a) {
        return -1;
    } else if (*(int *)b < *(int *)a ) {
        return 1;
    }
    return 0;  //I can't figure out.
}
