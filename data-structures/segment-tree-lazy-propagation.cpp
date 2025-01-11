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

const int MAXN = 5;
int lazy[4 * MAXN], tree[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void range_update(int tree[], int lazy[], int v, int tl, int tr, int l, int r, int val) {
    if (lazy[v] != 0) {
        tree[v] += (tr - tl + 1) * lazy[v];

        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }

        lazy[v] = 0;
    }

    if (tl > tr || tl > r || tr < l) return;

    if (tl >= l && tr <= r) {
        tree[v] += (tr - tl + 1) * val;
        if (tl != tr) {
            lazy[v * 2] += val;
            lazy[v * 2 + 1] += val;
        }
        return;
    }

    int tm = (tl + tr) / 2;
    range_update(tree, lazy, v * 2, tl, tm, l, r, val);
    range_update(tree, lazy, v * 2 + 1, tm + 1, tr, l, r, val);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int range_sum_query(int tree[], int lazy[], int v, int tl, int tr, int l, int r) {
    if (tl > tr || tl > r || tr < l) return 0;
    if (lazy[v] != 0) {
        tree[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (tl >= l && tr <= r) {
        return tree[v];
    }

    int tm = (tl + tr) / 2;
    int m = range_sum_query(tree, lazy, v * 2, tl, tm, l, r);
    int n = range_sum_query(tree, lazy, v * 2 + 1, tm + 1, tr, l, r);

    return m + n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(lazy, 0, 4 * MAXN * sizeof(ll));



    return 0;
}