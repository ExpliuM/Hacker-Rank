
/*
 * Link: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true
 */

#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

TEST(test, c_tutorial_basic_data)
{
    vector<string> filesToTest{
        "abstract-classes-polymorphism",
        "c-tutorial-basic-data-types",
        "c-tutorial-conditional-if-else",
        "c-tutorial-for-loop",
        "c-tutorial-functions",
        "one-week-preparation-kit-plus-minus",
    };

    for (const string fileName : filesToTest)
    {
        string pathToInputFiles = "../input";

        stringstream pathSS;
        pathSS << pathToInputFiles << "/" << fileName;
        string path = pathSS.str();

        for (const auto &entry : filesystem::directory_iterator(path))
        {
            string testNumber = entry.path().stem();
            string pathToInputFile = entry.path();

            string pathToResult = "../result";
            string pathToExpected = "../expected";

            stringstream pathToOutputFileSS;
            pathToOutputFileSS << pathToResult << "/" << fileName << "/" << testNumber << ".out";
            string pathToOutputFile = pathToOutputFileSS.str();

            stringstream commandSS;
            commandSS << "./" << fileName << " <" << pathToInputFile << " >" << pathToOutputFile;
            string command = commandSS.str();

            system(command.c_str());

            stringstream pathToExpectedFileSS;
            pathToExpectedFileSS << pathToExpected << "/" << fileName << "/" << testNumber << ".out";
            string pathToExpectedFile = pathToExpectedFileSS.str();

            ifstream expectedIFS(pathToExpectedFile);
            string expectedContent((istreambuf_iterator<char>(expectedIFS)),
                                   (istreambuf_iterator<char>()));

            ifstream resultIFS(pathToOutputFile);
            string resultContent((istreambuf_iterator<char>(resultIFS)),
                                 (istreambuf_iterator<char>()));

            ASSERT_EQ(expectedContent, resultContent);
        }
    }
}