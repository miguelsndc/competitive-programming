#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<pii>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define ff first
#define ss second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, limit;
    cin >> s >> limit;
    vi limits;
    int sum = 0;
    for (int i = 1; i <= limit; i++) {
        int lowbit = i & (-i);
        sum += lowbit;
        limits.push_back(i);
    }

    return 0;
}