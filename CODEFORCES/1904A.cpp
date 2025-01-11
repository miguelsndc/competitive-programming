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
#define vii vector<pii>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
#define MOD 1000000007

int main() {
  int t, a, b, xk, yk, xq, yq;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;

    set<pii> mva;
    set<pii> mvb;

    int dx[] = {-1, 1, -1, 1};
    int dy[] = {-1, -1, 1, 1};

    for (int j = 0; j < 4; j++) {
      mva.insert({xk + dx[j] * a, yk + dy[j] * b});
      mvb.insert({xq + dx[j] * a, yq + dy[j] * b});

      mva.insert({xk + dx[j] * b, yk + dy[j] * a});
      mvb.insert({xq + dx[j] * b, yk + dy[j] * a});
    }

    int c = 0;
    for (auto i : mva) {
      if (mvb.find(i) != mvb.end()) {
        c++;
      }
    }

    cout << c << '\n';
  }
}