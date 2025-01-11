#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int strStr(string haystack, string needle)
{
    if (haystack == needle)
        return 0;

    for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); i++)
        if (haystack.substr(i, needle.size()) == needle)
            return i;

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    cout << strStr(a, b);

    return 0;
}