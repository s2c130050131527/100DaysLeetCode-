/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Implement Stack using Queues.
*/
#include "iostream"
#include "queue"
using namespace std;

class MyStack
{
    queue<int> inQ;

public:
    /** Push element x onto stack. */
    void push(int x)
    {
        inQ.push(x);
        for (int i = 0; i < inQ.size() - 1; i++)
        {
            int a = inQ.front();
            inQ.pop();
            inQ.push(a);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int a = inQ.front();
        inQ.pop();
        return a;
    }

    /** Get the top element. */
    int top()
    {
        return inQ.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return inQ.empty();
    }
};
