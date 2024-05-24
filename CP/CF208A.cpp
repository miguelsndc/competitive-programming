#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    /// WUB WUB WUB AND WUB WUB I WUB LOVE WUB YOU

    int wubbing = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.substr(i, 3) == "WUB")
        {
            i += 2;
            if (wubbing)
            {
                wubbing = false;
                cout << " ";
            }
        }
        else
        {
            wubbing = true;
            cout << s[i];
        }
    }

    return 0;
}