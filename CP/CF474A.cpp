#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string layout = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char direction;
    cin >> direction;

    char c;
    string final = "";
    while (cin >> c)
    {
        int i = layout.find_first_of(c);

        if (direction == 'R')
        {
            i--;
        }
        else
        {
            i++;
        }

        cout << layout[i];
    }
    return 0;
}