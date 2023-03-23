/**
 * @file tmp.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/the-power-sum/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <iostream>
#include <cmath>
// #include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int powerSumAux(int X, int N, int i)
{
    if (X == 0)
    {
        return 1;
    }

    int iPowN = pow(i, N);
    if (iPowN > X)
    {
        return 0;
    }
    
    return powerSumAux(X - iPowN, N, i + 1) + powerSumAux(X, N, i + 1);
}

int powerSum(int X, int N)
{
    return powerSumAux(X, N, 1);
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    cout << result << "\n";
    // fout << result << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
