#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void knight_explore(int r, int c, vector<vi>& board, int depth, int* max_d) {
    if (board[r][c] == -1) return;

    board[r][c] = -1;  // visited
    max_d[0] = max(max_d[0], depth);
    for (int i = 0; i < 8; i++) {
        int x = r + dx[i];
        int y = c + dy[i];
        knight_explore(x, y, board, depth + 1, max_d);
    }
    board[r][c] = 1;  // unmark
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 1;
    while (cin >> n, n) {
        int a, b;
        vector<vi> board(14, vi(14, -1));
        int reachable = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            for (int j = a; j < a + b; j++) {
                board[i + 2][j + 2] = 1;
                reachable++;
            }
        }
        int max_d[] = {1};
        knight_explore(2, 2, board, 0, max_d);
        int not_reached = reachable - max_d[0] - 1;
        cout << "Case " << i << ", " << not_reached << " square" << (not_reached != 1 ? "s" : "") << " can not be reached." << '\n';
        i++;
    }

    return 0;
}