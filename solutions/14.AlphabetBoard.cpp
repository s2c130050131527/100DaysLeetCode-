#include "iostream"

using namespace std;

string alphabetBoardPath(string target)
{
    string c = "";
    int prevX = 0, prevY = 0;
    for (auto x : target)
    {
        int currX = (x - 'a') / 5;
        int currY = (x - 'a') % 5;
        if (currX == prevX && currY == prevY)
        {
            c += '!';
        }
        else
        {
            while (prevX > currX)
            {
                c += 'U';
                prevX--;
            }
            while (prevY > currY)
            {
                c += 'L';
                prevY--;
            }
            while (prevX < currX)
            {
                c += 'D';
                prevX++;
            }
            while (prevY < currY)
            {
                c += 'R';
                prevY++;
            }
            c += '!';
            prevX = currX;
            prevY = currY;
        }
    }
    return c;
}
int main()
{
    string target = "leet";
    string res = alphabetBoardPath(target);
    cout << res << endl;
    return 0;
}