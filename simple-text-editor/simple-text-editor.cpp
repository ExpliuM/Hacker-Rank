/**
 * @file simple-text-editor.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/simple-text-editor/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

enum ACTION
{
    APPEND = 1,
    DELETE = 2,
    PRINT = 3,
    UNDO = 4
};

int main()
{
    string s;
    string stringToAppend;
    stack<string> history;

    int length;

    int numberOfQueries;
    cin >> numberOfQueries;

    for (; numberOfQueries > 0; --numberOfQueries)
    {
        int action;
        cin >> action;
        switch (action)
        {
        case APPEND:
            history.push(s);
            cin >> stringToAppend;
            s.append(stringToAppend);
            break;

        case DELETE:
            history.push(s);
            cin >> length;
            s.resize(s.size() - length);
            break;

        case PRINT:
            cin >> length;
            cout << s.c_str()[length - 1] << endl;
            break;

        case UNDO:
            if (!history.empty())
            {
                s = history.top();
                history.pop();
            }
            break;

        default:
            cout << "error" << endl;
            return -1;
        }
    }

    return 0;
}