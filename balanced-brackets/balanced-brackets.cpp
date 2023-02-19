/*
 * Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-balanced-brackets/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-five
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s)
{
    const char *sAsCharArr = s.c_str();
    size_t length = s.size();
    stack<char> bracketsStack;

    for (size_t i = 0; i < length; ++i)
    {
        switch (sAsCharArr[i])
        {
        case '(':
        case '[':
        case '{':
            bracketsStack.push(sAsCharArr[i]);
            break;

        case ')':
            if (bracketsStack.empty() || bracketsStack.top() != '(')
            {
                return "NO";
            }
            bracketsStack.pop();
            break;
        case ']':
            if (bracketsStack.empty() || bracketsStack.top() != '[')
            {
                return "NO";
            }
            bracketsStack.pop();
            break;
        case '}':
            if (bracketsStack.empty() || bracketsStack.top() != '{')
            {
                return "NO";
            }
            bracketsStack.pop();
            break;
        }
    }

    if (bracketsStack.empty())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
