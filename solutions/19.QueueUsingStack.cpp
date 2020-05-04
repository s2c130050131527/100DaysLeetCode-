/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.
*/

#include "iostream"
#include "stack"

using namespace std;

class MyQueue
{
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                int a = inStack.top();
                inStack.pop();
                outStack.push(a);
            }
        }
        int returnNum = outStack.top();
        outStack.pop();
        return returnNum;
    }

    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                int a = inStack.top();
                inStack.pop();
                outStack.push(a);
            }
        }
        int returnNum = outStack.top();
        return returnNum;
    }

    bool empty()
    {
        if (outStack.empty() && inStack.empty())
            return true;
        return false;
    }
};

int main()
{
    MyQueue *q = new MyQueue();
}