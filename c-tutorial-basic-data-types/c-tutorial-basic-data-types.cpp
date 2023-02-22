/**
 * @file c-tutorial-basic-data-types.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true 
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdio>
#include <limits>

typedef std::numeric_limits<double> dbl;

using namespace std;

int main()
{
    int integerVar;
    long longVar;
    char charVar;
    float floatVar;
    double doubleVar;
    cin >> integerVar >> longVar >> charVar >> floatVar >> doubleVar;
    cout << integerVar << endl;
    cout << longVar << endl;
    cout << charVar << endl;


    cout.precision(3);
    cout << std::fixed << floatVar << endl;

    cout.precision(5);
    cout << doubleVar;

    return 0;
}