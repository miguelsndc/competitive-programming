#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmpfunc(pair<char, int> a, pair<char, int> b)
{
    return a.second <= b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dist[3];
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < 3; i++)
    {
        char a, sign, b;
        cin >> a >> sign >> b;
        if (sign == '>')
            dist[a % 65]++;
        else
            dist[b % 65]++;
    }
    vector<pair<char, int>> weights;
    for (int i = 0; i < 3; i++)
        weights.push_back(make_pair((char)i + 65, dist[i]));

    sort(weights.begin(), weights.end(), cmpfunc);
    bool impossible = false;
    for (int i = 0; i < 2; i++)
    {
        if (weights[i].second == weights[i + 1].second)
        {
            impossible = true;
            break;
        }
    }
    if (impossible)
    {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < 3; i++)
        cout << weights[i].first;

    return 0;
}