/**
 * @file solve-me-first.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solveMeFirst(int a, int b)
{
  return a + b;
}

int main()
{
  int num1, num2;
  int sum;
  cin >> num1 >> num2;
  sum = solveMeFirst(num1, num2);
  cout << sum;
  return 0;
}