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
