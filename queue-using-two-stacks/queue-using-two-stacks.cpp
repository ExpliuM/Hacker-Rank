/*
 * Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-queue-using-two-stacks/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-five
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class Queue
{
    stack<T> popUpStack;
    stack<T> pushInStack;

public:
    Queue() {}

    void enqueue(T x)
    {
        pushInStack.push(x);
    }

    void dequeue()
    {
        this->fillPopUpStackFromPushInStack();
        popUpStack.pop();
    }

    int head()
    {
        this->fillPopUpStackFromPushInStack();
        return popUpStack.top();
    }

private:
    void fillPopUpStackFromPushInStack()
    {
        if (popUpStack.empty())
        {
            while (!pushInStack.empty())
            {
                popUpStack.push(pushInStack.top());
                pushInStack.pop();
            }
        }
    }
};

enum ACTION
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    HEAD = 3
};

int main()
{
    Queue<int> queue;

    int numberOfQueries;
    cin >> numberOfQueries;

    for (; numberOfQueries > 0; --numberOfQueries)
    {
        int action;
        cin >> action;
        switch (action)
        {
        case ENQUEUE:
            int number;
            cin >> number;
            queue.enqueue(number);
            break;

        case DEQUEUE:
            queue.dequeue();
            break;

        default:
        case HEAD:
            cout << queue.head() << endl;
            break;
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
