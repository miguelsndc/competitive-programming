#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<char> distinct;

    char ch;
    while (cin >> ch)
    {
        if (ch != '{' && ch != '}' && ch != ',')
        {
            distinct.insert(ch);
        }
    }

    cout << distinct.size();

    return 0;
}