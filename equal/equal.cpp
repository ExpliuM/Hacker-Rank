/**
 * @file equal.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <vector>
#include <string>
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int minimalSubOps(int n, vector<int> &pieces)
{
    int ops = 0;
    int pieceIndex = 0;

    while (n > 0)
    {
        while (pieces[pieceIndex] > n)
        {
            ++pieceIndex;
        }
        n -= pieces[pieceIndex];
        ++ops;
    }
    return ops;
}

int equal(vector<int> arr)
{
    if (arr[0] == arr[1] && arr[1] == arr[2])
    {
        return 0;
    }

    int minElm = *min_element(arr.begin(), arr.end());

    for (int &elm : arr)
    {
        elm -= minElm;
    }
    vector<int> p;
    p.push_back(5);
    p.push_back(2);
    p.push_back(1);

    int sum = 0;
    for (int elm: arr) {
        sum+=minimalSubOps(elm, p);
    }

    return sum;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
