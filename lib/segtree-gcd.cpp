#include <bits/stdc++.h>
using namespace std;

class SegmentTreeGCDLCM {
private:
    vector<int> tree_gcd, tree_lcm;
    int size;

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree_gcd[node] = data[start];
            tree_lcm[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree_gcd[node] = gcd(tree_gcd[2 * node], tree_gcd[2 * node + 1]);
            tree_lcm[node] = lcm(tree_lcm[2 * node], tree_lcm[2 * node + 1]);
        }
    }

    int query_gcd(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0; // Neutral element for GCD
        if (l <= start && end <= r) return tree_gcd[node];
        int mid = (start + end) / 2;
        int left = query_gcd(2 * node, start, mid, l, r);
        int right = query_gcd(2 * node + 1, mid + 1, end, l, r);
        return gcd(left, right);
    }

    int query_lcm(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 1; // Neutral element for LCM
        if (l <= start && end <= r) return tree_lcm[node];
        int mid = (start + end) / 2;
        int left = query_lcm(2 * node, start, mid, l, r);
        int right = query_lcm(2 * node + 1, mid + 1, end, l, r);
        return lcm(left, right);
    }

public:
    SegmentTreeGCDLCM(vector<int>& data) {
        size = data.size();
        tree_gcd.resize(4 * size);
        tree_lcm.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    int get_gcd(int l, int r) {
        return query_gcd(1, 0, size - 1, l, r);
    }

    int get_lcm(int l, int r) {
        return query_lcm(1, 0, size - 1, l, r);
    }
};

int main() {
    vector<int> data = {4, 12, 6, 8, 10};
    SegmentTreeGCDLCM st(data);
    return 0;
}