/**
 * @file palindrome-index.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/palindrome-index/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int isPalindrome(string s)
{
    for (size_t i = 0; i < (s.size() + 1) / 2; ++i)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int palindromeIndex(string s)
{
    size_t length = s.size();

    for (size_t i = 0; i < length - i - 1; ++i)
    {
        if (s[i] != s[length - i - 1])
        {
            if (isPalindrome(s.substr(i, length - 2 * i - 1)))
            {
                return length - i - 1;
            }
            if (isPalindrome(s.substr(i + 1, length - 2 * i - 1)))
            {
                return i;
            }
            return -1;
        }
    }
    return -1;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout << result << "\n";
        // fout << result << "\n";
    }

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
