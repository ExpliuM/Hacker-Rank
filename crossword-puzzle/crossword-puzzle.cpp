/**
 * @file tmp.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/crossword-puzzle/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iosfwd>

// #include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

vector<string> getWords(const string &words, char delim)
{
    stringstream wordsSS(words);
    vector<string> wordsVector;
    string buffer;

    while (getline(wordsSS, buffer, delim))
    {
        wordsVector.push_back(buffer);
    }

    return wordsVector;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words)
{
    vector<string> wordsVector = getWords(words, ';');
    crossword[0]=crossword[0];
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++)
    {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

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
