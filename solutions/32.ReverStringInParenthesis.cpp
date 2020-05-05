// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.

#include "iostream"
#include "stack"
#include "algorithm"
using namespace std;

string reverseParentheses(string s)
{
    string ans = "";
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            int j = st.top();
            st.pop();
            reverse(s.begin() + j + 1, s.begin() + i);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    string s = "(u(love)i)";
    string res = reverseParentheses(s);
    cout << res << endl;
    return 1;
}