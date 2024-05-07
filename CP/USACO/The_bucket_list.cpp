#include <bits/stdc++.h>

using namespace std;

void setIO(string name)
{
    if (name.size() > 0)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("blist");
    int n;
    cin >> n;

    vector<int> change(1001);

    for (int i = 0; i < n; i++)
    {
        int start, end, amount;
        cin >> start >> end >> amount;

        change[start] += amount;
        change[end] -= amount;
    }

    int max_buckets = 0;
    int curr_buckets = 0;
    for (int c = 0; c < 1000; c++)
    {
        curr_buckets += change[c];
        max_buckets = max(max_buckets, curr_buckets);
    }

    cout << max_buckets;

    return 0;
}