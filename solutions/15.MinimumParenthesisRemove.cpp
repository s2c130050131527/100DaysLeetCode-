#include "iostream"
#include "stack"
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> st;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            res += s[i];
            st.push(res.size() - 1);
        }
        else if (s[i] == ')')
        {

            if (!st.empty())
            {
                st.pop();
                res += s[i];
            }
        }
        else
        {
            res += s[i];
        }
    }
    while (!st.empty())
    {
        int b = st.top();
        res = res.replace(b, 1, "");
        st.pop();
    }

    return res;
}

int main()
{
    string target = "lee(t(c)o)de)";
    string res = minRemoveToMakeValid(target);
    cout << res << endl;
    return 0;
}