#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

int solve(int n, int row, int col, int ck, int k, vi&ldiag, vi&rdiag, vector<vi>& board) {
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return 0;
    }

    if (ck == k) {
        return 1;
    }

    int count = 0;

    for (int i = row; i < n; i++) {
        for (int j = col; j < n; j++) {
            if (rdiag[i - j + n] == 0 && ldiag[i + j] == 0 && board[i][j] == 0) {
                board[i][j] = 1;
                rdiag[i - j + n] = 1;
                ldiag[i + j] = 1;

                count += solve(n, i, j + 1, ck + 1, k, ldiag, rdiag, board);
                count += solve(n, i + 1, j, ck + 1, k, ldiag, rdiag, board);

                board[i][j] = 0;
                rdiag[i - j + n] = 0;
                ldiag[i + j] = 0;
            }
        }
    }

    return count;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> board(9, vi(9));
    vi rdiag(9);
    vi ldiag(9);
    int n = -1, k = -1; 

    while(1) {
        cin >> n >> k;
        if (n == 0 && k == 0) return 0;

        int ans =  solve(n, 0, 0, 0, k, ldiag, rdiag, board);
        cout << ans << '\n';
    }

    return 0;
}
