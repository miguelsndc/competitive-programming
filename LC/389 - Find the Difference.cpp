#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char findTheDifference(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i = 0;
    while (i < s.size())
    {
        if (s[i] != t[i])
        {
            return (char)t[i];
        }
        i++;
    }
    return t[t.size() - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    cout << findTheDifference(a, b);

    return 0;
}