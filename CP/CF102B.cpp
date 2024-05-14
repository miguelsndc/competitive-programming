#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    int count = 0;

    if (s.size() < 2)
    {
        cout << 0;
        return 0;
    }

    int sum = 11;
    while (sum >= 10)
    {
        sum = 0;
        for (auto ch : s)
            sum += ch - '0';
        s = to_string(sum);
        count++;
    }

    cout << count;

    return 0;
}