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
#define v vector

struct op {
    ll left, right, val;
};

// works by seeing where the operations will happen, how many times and does the correct updates by subtracting
// at pos + 1 where the operation ends, making sure that previous operations don't affect the prefix sum and interfere on others
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vll elements(n + 1);
    for (int i = 1; i <= n; i++) cin >> elements[i];

    v<op> operations(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> operations[i].left >> operations[i].right >> operations[i].val;

    vll op_number(m + 2, 0);
    for (int i = 1; i <= k; i++) {
        // operation starts at x and ends ant y, then at y + 1 we must undo it
        int x, y;
        cin >> x >> y;
        op_number[x]++;
        op_number[y + 1]--;  // prefix sum removal
    }

    vll used(m + 1);
    for (int i = 1; i <= m; i++)
        // counts the number of operations of each cell
        used[i] = used[i - 1] + op_number[i];

    vll updates(n + 2);
    for (int i = 1; i <= m; i++) {
        // updates[left] adds (times used * the value of the operation)
        // assigning each position the value of updating
        // and of course when the operation ends we undo it for the next
        updates[operations[i].left] += used[i] * operations[i].val;
        updates[operations[i].right + 1] -= used[i] * operations[i].val;
    }

    vll add(n + 1);
    for (int i = 1; i <= n; i++) {
        // the prefix of additions, see that if operation Q was undone at position i
        // then at position i - 1 if K is the accumulated sum then we subtract K from i - 1
        add[i] = add[i - 1] + updates[i];
    }

    for (int i = 1; i <= n; i++) {
        elements[i] += add[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << elements[i] spe;
    }
    return 0;
}