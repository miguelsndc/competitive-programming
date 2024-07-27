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
#define ss second
#define sp << " " <<
#define spe << " "

void solve() {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;

    map<char, int> mt;
    for (auto c : t) mt[c]++;

    int yay = 0, whoops = 0;
    for (int c = 0; c < s.size(); c++) {
        if (mt[s[c]] > 0) {
            yay++;
            mt[s[c]]--;
            s[c] = '-';
        }
    }

    for (int c = 0; c < s.size(); c++) {
        char b = s[c] >= 97 ? s[c] - 32 : s[c] + 32;
        if (s[c] != '-' && mt[b] > 0) {
            whoops++;
            mt[b]--;
        }
    }

    std::cout << yay << ' ' << whoops;

    return 0;
}