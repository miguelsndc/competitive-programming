#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> numbers;
    while (cin >> n)
    {
        numbers.push_back(n);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i];
        if (i != numbers.size() - 1)
        {
            cout << '+';
        }
    }

    return 0;
}