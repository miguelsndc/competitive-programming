#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p = 0;
    int q = n - 1;
    unordered_set<char> frequency;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int r = 0; r < n; r++)
        {
            if (r != p && r != q && (line[r] == line[p] || line[r] == line[q]))
            {
                cout << "NO";
                return 0;
            }
            else
            {
                frequency.insert(line[r]);
            }
        }

        if (frequency.size() != 2)
        {
            cout << "NO";
            return 0;
        }

        if (line[p] == line[q])
        {
            p++, q--;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}