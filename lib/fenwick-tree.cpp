#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 + 5;
vector<ll> bit(maxn);

int n;
void add(int pos, int val) {
	++pos; 
	while (pos <= n) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

int range_query(int l, int r) {
	return query(r) - query(l - 1);
}

void build(const vector<ll> &v) {
	for (int i = 0; i < v.size(); i++) {
		add(i, v[i]);
	}
}


int main() {
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build(arr);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << range_query(l, r) << '\n';
	}
}