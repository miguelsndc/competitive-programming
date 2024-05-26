#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

bool primality_test(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int next_prime = n;
    int is_prime = false;

    while (!is_prime)
    {
        next_prime++;
        is_prime = primality_test(next_prime);
    }

    string ans = m == next_prime ? "YES" : "NO";
    cout << ans;
    return 0;
}