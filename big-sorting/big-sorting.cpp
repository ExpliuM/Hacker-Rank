/**
 * @file big-sorting.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/big-sorting/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

inline bool compare(const string &s1, const string &s2)
{
    int strCmp = s2.compare(s1);
    int lengthCmp = (s2.size() - s1.size());
    if (lengthCmp == 0)
    {
        return strCmp > 0 ? true : false;
    }
    return lengthCmp > 0 ? true : false;
};

vector<string> bigSorting(vector<string> unsorted)
{
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++)
    {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        // fout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
            // fout << "\n";
        }
    }

    cout << "\n";
    // fout << "\n";

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
