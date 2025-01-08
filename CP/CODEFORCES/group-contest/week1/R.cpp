#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> perm(n), in(n), out(n), loops;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; --x;
        perm[i] = x; 
        if (perm[i] != -1) { in[x]++; out[i]++; }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0 && out[i] == 0) {
            loops.push_back(i); cnt++;
        } 
    }

    if (loops.size() == 1) {
        int node = loops[0];
        for (int i = 0; i < n; i++) {
            if (i != node && in[i] == 0)  {
                perm[node] = i;
                out[node]++;
                in[i]++;
                break;
            }
        }
    }

    if (loops.size() > 1) {
        for (int i = 0; i < loops.size(); i++) {
            int cur = loops[i];
            int next = loops[(i + 1) % loops.size()];

            perm[cur] = next;

            out[cur]++;
            in[next]++;
        }
    }

    loops.clear();

    vector<int> zero_in, zero_out;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) zero_in.push_back(i);
        if (out[i] == 0) zero_out.push_back(i);
    }

    for (int i = 0; i < zero_out.size(); i++) {
        perm[zero_out[i]] = zero_in[i];
    }

    for (int i = 0; i < n; i++) {
        cout << perm[i] + 1 << ' ';
    }
}