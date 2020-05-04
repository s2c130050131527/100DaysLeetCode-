#include "iostream"
#include "vector"
using namespace std;

string reorganizeString(string S)
{
    string res = "";
    int hash[26] = {0};
    for (auto s : S)
    {
        hash[s - 'a']++;
    }
    int letter = 0, max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max)
        {
            max = hash[i];
            letter = i;
        }
    }
    if (max > (S.length() + 1) / 2)
    {
        return res;
    }
    string resArr = S;
    int index = 0;
    while (hash[letter] > 0)
    {
        if (index >= resArr.length())
            index = 1;
        resArr[index] = (char)(letter + 'a');
        index += 2;
        hash[letter]--;
    }
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            if (index >= resArr.length())
                index = 1;
            resArr[index] = (char)(i + 'a');
            hash[i]--;
            index += 2;
        }
    }
    return resArr;
}
int main()
{
    string s = "aab";
    string a = reorganizeString(s);
    cout << a << endl;
    return 0;
}