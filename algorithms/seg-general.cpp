#include <bits/stdc++.h>
using namespace std;

// Segment Tree for Range Sum
class SegmentTreeSum {
private:
    vector<int> tree;
    int size;

    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0; // Neutral element for sum
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    SegmentTreeSum(vector<int>& data) {
        size = data.size();
        tree.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }

    int get(int idx) {
        return query(1, 0, size - 1, idx, idx);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

// Segment Tree for Range Minimum
class SegmentTreeMin {
private:
    vector<int> tree;
    int size;

    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

        }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return INT_MAX; // Neutral element for min
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return min(left, right);
    }

public:
    SegmentTreeMin(vector<int>& data) {
        size = data.size();
        tree.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }

    int get(int idx) {
        return query(1, 0, size - 1, idx, idx);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

// Segment Tree for Range Maximum
class SegmentTreeMax {
private:
    vector<int> tree;
    int size;

    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return INT_MIN; // Neutral element for max
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return max(left, right);
    }

public:
    SegmentTreeMax(vector<int>& data) {
        size = data.size();
        tree.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }

    int get(int idx) {
        return query(1, 0, size - 1, idx, idx);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

// Segment Tree for Range XOR
class SegmentTreeXOR {
private:
    vector<int> tree;
    int size;

    void build(vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0; // Neutral element for XOR
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return left ^ right;
    }

public:
    SegmentTreeXOR(vector<int>& data) {
        size = data.size();
        tree.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }

    int get(int idx) {
        return query(1, 0, size - 1, idx, idx);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};

    SegmentTreeSum st_sum(data);
    SegmentTreeMin st_min(data);
    SegmentTreeMax st_max(data);
    SegmentTreeXOR st_xor(data);

    cout << "Sum of range [1, 4]: " << st_sum.query(1, 4) << endl; // Output: 24
    cout << "Min of range [1, 4]: " << st_min.query(1, 4) << endl; // Output: 3
    cout << "Max of range [1, 4]: " << st_max.query(1, 4) << endl; // Output: 9
    cout << "XOR of range [1, 4]: " << st_xor.query(1, 4) << endl; // Output: 10

    st_sum.update(2, 10);
    cout << "Updated Sum of range [1, 4]: " << st_sum.query(1, 4) << endl; // Output: 29

    return 0;
}