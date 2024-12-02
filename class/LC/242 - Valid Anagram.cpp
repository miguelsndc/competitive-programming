#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}