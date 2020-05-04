#include "iostream"
#include "stack"
#include "vector"
#include "string"

#define VS vector<string>
using namespace std;

int evalRPN(VS &tokens)
{
    stack<int> st;
    int extract_int;
    for (string s : tokens)
    {
        if (s == "*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a * b);
        }
        else if (s == "+")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a + b);
        }
        else if (s == "-")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        }
        else if (s == "/")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b / a);
        }
        else
        {
            extract_int = stoi(s);
            st.push(extract_int);
        }
    }
    return st.top();
}

int main()
{
    vector<string> a = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int res = evalRPN(a);
    cout << res << endl;
    return 0;
}