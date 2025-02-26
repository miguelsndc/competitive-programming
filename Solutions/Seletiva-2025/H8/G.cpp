#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5 + 5;

int n;
vector<int> a(maxn);
struct SegmentTree {
    vector<int> tree;
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    int join(int a, int b) {
    }

    void build(int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = a[l];
            return;
        } else {
            int mid = l + (r - l) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, int val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 1);
            }
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    int query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return (1e9 + 9);
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        int left = query(a, b, l, mid, v * 2);
        int right = query(a, b, mid + 1, r, v * 2 + 1);
        return join(left, right);
    }
};


const int maxn = 2e5 + 5;
vector<int> a(maxn);

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while(q--) {
        char t; cin >> t;
        if (t == '!') {
            int k, x; cin >> k >> x;
            // mudar salario do cara k pra x
            // n da pra ter 10⁹ caras na seg
            a[k] = x;
        }
        else {
            int l, r; cin >> l >> r; // quantos salario tem entre a e b
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] >= l && a[i] <= r) {
                    cnt++;
                }
            }
            cout << cnt << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}