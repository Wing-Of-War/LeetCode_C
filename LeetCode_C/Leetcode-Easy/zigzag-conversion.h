//
//  zigzag-conversion.h
//  LeetCode_C
//
//  Created by 张珏 on 15/12/3.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef zigzag_conversion_h
#define zigzag_conversion_h

#include <stdio.h>

/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

void testZigzag(void);
char* convert(char* s, int numRows);

#endif /* zigzag_conversion_h */
