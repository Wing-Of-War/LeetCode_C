//
//  excel-sheet-column-title.c
//  LeetCode_C
//
//  Created by 张珏 on 15/12/16.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "excel-sheet-column-title.h"
#include <stdlib.h>


char* convertToTitle(int n) {
    int length = 0;
    int t = n;
    while (t>0) {
        length ++;
        t = (t-1)/26;
    }
    char *p = (char *)malloc(sizeof(char) * length);
    char *tt = p + (sizeof(char) * (length-1));
    while(n > 0) {
        *tt = (n-1) % 26 + 'A';
        n = (n-1) / 26;
        tt--;
    }
    return p;
}