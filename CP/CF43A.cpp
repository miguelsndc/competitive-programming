#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> scores;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        scores[s]++;
    }

    pair<string, int> max_pair = make_pair("", INT_MIN);

    for (auto const &x : scores)
    {
        if (x.second > max_pair.second)
            max_pair = x;
    }

    cout << max_pair.first;

    return 0;
}