#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void findpath(int N, vector<int> &a)
{
 
    // If a[0] is 1
    if (a[0]) {
 
        // Printing path
        cout << N + 1;
        for (int i = 1; i <= N; i++)
            cout <<" " << i;
        return;
    }
 
    // Seeking for a[i] = 0 and a[i+1] = 1
    for (int i = 0; i < N - 1; i++) {
        if (!a[i] && a[i + 1]) {
 
            // Printing path
            for (int j = 0; j <= i; j++)
                cout << j + 1 << ' ';
            cout << N + 1;
            for (int j = i + 1; j < N; j++)
                cout << " "<< j + 1;
            return;
        }
    }
 
    // If a[N-1] = 0
    for (int i = 1; i <= N; i++)
        cout << i << ' ';
    cout << N + 1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        findpath(n, g);
        cout << '\n';
    }
}