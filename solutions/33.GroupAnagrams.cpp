// Runtime: 136 ms, faster than 33.20% of C++ online submissions for Group Anagrams.
// Memory Usage: 80.5 MB, less than 5.97% of C++ online submissions for Group Anagrams.

#include "iostream"
#include "vector"
#include "map"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> m;
    vector<vector<string>> res;
    for (auto c : strs)
    {
        vector<int> hash(26, 0);
        for (int i = 0; i < c.length(); i++)
            hash[c[i] - 'a']++;

        string s;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > 0)
            {
                s = s.append(s.append(hash[i], (char)i + 'a'));
            }
        }

        m[s].push_back(c);
    }
    for (auto k : m)
    {
        res.push_back(k.second);
    }
    return res;
}

int main()
{
    vector<string> s = {"cat", "rye", "aye", "cud", "cat", "old", "fop", "bra"};
    vector<vector<string>> res = groupAnagrams(s);
    for (auto k : res)
    {
        for (auto c : k)
        {
            cout << c << "\t";
        }
        cout << endl;
    }
    return 1;
}