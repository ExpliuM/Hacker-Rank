/*
 * Link:
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY batchSize
 *  2. INTEGER_ARRAY processingTime
 *  3. INTEGER_ARRAY numTasks
 */

long minTime(vector<int> batchSize, vector<int> processingTime, vector<int> numTasks)
{
    int numberOfQueues = batchSize.size();
    long maxTime = 0;
    for (size_t queueNumber = 0; queueNumber < numberOfQueues; ++queueNumber)
    {
        long double bs = batchSize[queueNumber];
        int pt = processingTime[queueNumber];
        long double nt = numTasks[queueNumber];
        maxTime = max(maxTime, (long)ceil(nt / bs) * pt);
    }
    return maxTime;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string batchSize_count_temp;
    getline(cin, batchSize_count_temp);

    int batchSize_count = stoi(ltrim(rtrim(batchSize_count_temp)));

    vector<int> batchSize(batchSize_count);

    for (int i = 0; i < batchSize_count; i++)
    {
        string batchSize_item_temp;
        getline(cin, batchSize_item_temp);

        int batchSize_item = stoi(ltrim(rtrim(batchSize_item_temp)));

        batchSize[i] = batchSize_item;
    }

    string processingTime_count_temp;
    getline(cin, processingTime_count_temp);

    int processingTime_count = stoi(ltrim(rtrim(processingTime_count_temp)));

    vector<int> processingTime(processingTime_count);

    for (int i = 0; i < processingTime_count; i++)
    {
        string processingTime_item_temp;
        getline(cin, processingTime_item_temp);

        int processingTime_item = stoi(ltrim(rtrim(processingTime_item_temp)));

        processingTime[i] = processingTime_item;
    }

    string numTasks_count_temp;
    getline(cin, numTasks_count_temp);

    int numTasks_count = stoi(ltrim(rtrim(numTasks_count_temp)));

    vector<int> numTasks(numTasks_count);

    for (int i = 0; i < numTasks_count; i++)
    {
        string numTasks_item_temp;
        getline(cin, numTasks_item_temp);

        int numTasks_item = stoi(ltrim(rtrim(numTasks_item_temp)));

        numTasks[i] = numTasks_item;
    }

    long result = minTime(batchSize, processingTime, numTasks);

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
