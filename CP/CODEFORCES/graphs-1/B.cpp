#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int r[50003][5];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) cin >> r[i][j];
        }

        int winner = 1;
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            for (int k = 0; k < 5; k++) {
                if (r[winner][k] < r[i][k]) cnt++;
            }
            if (cnt < 3) {
                winner = i;
            }
        }

        int answer = winner;
        for (int i = 1; i <= n; i++) {
            if (i == answer) continue;
            int cnt = 0;
            for (int k = 0; k < 5; k++) {
                if (r[winner][k] < r[i][k]) cnt++;
            }
            if (cnt < 3) {
                answer = -1;
                break;
            }
        }

        cout << (answer) << '\n';
    }
}