#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> table{
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}};

    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        sum += table[t];
    }

    cout << sum;

    return 0;
}