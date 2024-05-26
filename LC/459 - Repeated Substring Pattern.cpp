#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    unordered_set<string> mp;
    for (int i = 0; i < n / 2; i++)
    {
        mp.insert(s.substr(0, i + 1));
        for (int j = i + 1; j < n;)
        {
            if (mp.find(s.substr(j, i + 1)) != mp.end() && j + i + 1 == n)
            {
                return true;
            }
            else if (mp.find(s.substr(j, i + 1)) == mp.end())
            {
                return false;
            }
            else
            {
                j += i + 1;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string ans = repeatedSubstringPattern(s) ? "true" : "false";
    cout << ans;

    return 0;
}