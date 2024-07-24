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

// A Segment tree can be defined implictly, similar to the implementation of a binary heap
// this assumes range sum query problems
// i'll cover the rest as i progress in competitive programming
// We let the index i hold the root, and indexes 2i and 2i + 1 hold their children
// We use 1-based indexing to allow computing children as i <</>> 1

// A segment tree needs at most 4N vertices, might be less, but for convenience allocate the maximum space
const int MAXN = 10;
int n, t[4 * MAXN];

// procedure for building a segment tree, this has the following assumptions:
// a[] is the array we build the tree upon
// v is the current vertex
// tl and tr are the lower and upper indices, at first, tl = 0 and tr = n - 1
// 1-based !!

// procedure works as follows
// if tl == tr we set the position i in a to t
// otherwise we split in the middle and call build recursively on both branches of the tree
// then we backtrack setting the positions in t to the sums of the values of the right and left branches
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

// the range sum query function, parameters are:
// v <- current vertex
// tl, tr <- the low and upper boundaries of the TREE
// l, r <- the range of the query we want the sum of

// works by traversing the tree and collecting the necessary branches to form the sum
// we again split in the middle and perform two recursive calls
// one to the left, and other to the right, if boundaries match we're done
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;  // trivial case;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(tm, r)) + sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}

// finally the update function, traverse the tree and set tree[pos] to newval
// then we backtrack updating the sums
void update(int v, int tl, int tr, int pos, int newval) {
    if (tl == tr) {
        t[v] = newval;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, newval);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, newval);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v[10 + 1] = {-1, 1, 2, 3, 44, 5, 6, 7, 8, 9, 10};
    build(v, 1, 0, 9);
    int r = sum(1, 0, 9, 3, 5);
    cout << r;
}