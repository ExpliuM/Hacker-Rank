/**
 * @file c-tutorial-pointer.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <math.h>

void update(int *a, int *b)
{
    int absoluteDifference = abs(*a - *b);
    int sum = *a + *b;
    *a = sum;
    *b = absoluteDifference;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}