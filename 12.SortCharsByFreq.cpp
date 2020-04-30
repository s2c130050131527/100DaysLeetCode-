#include "iostream"
#include "bits/stdc++.h"
using namespace std;

int compare(pair<char, int> &a, pair<char, int> &b)
{
    if (a.second > b.second)
    {
        return true;
    }
    return false;
}

string frequencySort(string s)
{
    string res = "";
    unordered_map<char, int> m;
    vector<pair<char, int>> v;

    for (auto a : s)
    {
        if (m[a])
        {
            m[a]++;
        }
        else
        {
            m[a] = 1;
        }
    }

    for (auto c : m)
    {
        v.push_back(make_pair(c.first, c.second));
    }

    sort(v.begin(), v.end(), compare);
    for (auto k : v)
    {
        int l = k.second;
        while (l--)
        {
            res += k.first;
        }
    }
    return res;
}

int main()
{
    string s = "abcee";
    string a = frequencySort(s);
    cout << a << endl;
    return 0;
}