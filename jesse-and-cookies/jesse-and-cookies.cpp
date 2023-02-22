/**
 * @file jesse-and-cookies.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/jesse-and-cookies/problem?isFullScreen=true
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
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

template <typename T>
typename std::vector<T>::iterator
insert_sorted(std::vector<T> &vec, T const &item)
{
    return vec.insert(
        std::upper_bound(vec.begin(), vec.end(), item),
        item);
}

int cookies(int k, vector<int> A)
{
    std::make_heap(A.begin(), A.end(), std::greater<int>());

    int iterationsCount = 0;

    pop_heap(A.begin(), A.end(), std::greater<int>());
    while (A[A.size()-1] < k && A.size() >= 2)
    {
        ++iterationsCount;

        int min1 = A[A.size()-1];
        A.pop_back();

        pop_heap(A.begin(), A.end(), std::greater<int>());
        int min2 = A[A.size()-1];
        A.pop_back();

        long long calc = min1 + 2 * min2;

        A.push_back((int)calc);
        push_heap(A.begin(), A.end(), std::greater<int>());

        pop_heap(A.begin(), A.end(), std::greater<int>());
    }

    if (A[0] >= k)
    {
        return iterationsCount;
    }
    return -1;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

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
