#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 4e6 + 6;
vector<ll> bit(maxn);
void add(int pos, int val) {
	++pos; 
	while (pos <= maxn) {
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

/*
Dois times onde cada um escolhe o kesimo cara disponivel numa lista de [1, 4 * 10^6]
toda vez q eu escolho um cara x todos os y > x sao shiftados 1 pra esquerda

ou algo tipo

[1 2 3 4 5 6]
query(1) -> 1
[2 3 4 5 6 7]
query(2) -> 3
[2 4 5 6 7 8]
como todas as queries sao num range valido posso ignorar os mais a esquerda
bit de diff array
*/

void solve() {
    int n; cin >> n;
    vector<int> t1(n/2), t2(n/2);
    for (int i = 0; i < n / 2 ; i++) cin >> t1[i];
    for (int i = 0; i < n / 2 ; i++) cin >> t2[i];

    for (int i = 0; i <= maxn; i++) {
        int v = i + 1;
        add(i + 1, v);
        add(i + 2, -v);
    }

    vector<int> time1, time2;
    for (int i = 0; i < n / 2; i++) {
        int q1 = t1[i];
        int q2 = t2[i];

        int v = query(q1);
        int v2 = query(q1 + 1);
        time1.push_back(v);
        add(q1, v2 - v);
        add(q1 + 1, -(v2 - v) + 1);

        v = query(q2);
        v2 = query(q2 + 1);
        time2.push_back(v);
        add(q2, v2 - v);
        add(q2 + 1, -(v2 - v) + 1);
    }
    for (int x: time1) cout << x << ' ';
    cout << '\n';
    for (int x: time2) cout << x << ' ';
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