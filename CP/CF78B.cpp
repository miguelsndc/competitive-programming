#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string colors = "ROYGBIV"; //
    for (int i = 0; i < (n / 7); i++)
        cout << colors;
    int start = 3;
    int end = 0;
    for (int i = 0; i < (n % 7); i++)
    {
        if (i % 3 == 2)
            start--;
    }
    cout << colors.substr(start, n % 7);
}