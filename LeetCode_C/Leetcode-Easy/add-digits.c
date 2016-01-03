//
//  add-digits.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/4/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "add-digits.h"


int addDigits(int num) {
    
    if (num) {
        int result = num % 9;
        return result ? result : 9;
    }
    return 0;
}