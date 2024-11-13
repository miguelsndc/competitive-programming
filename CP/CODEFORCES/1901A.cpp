#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> points(n);
    int max_neighbour_dist = -1, max_close_gas_station = -1;
    for (int i = 0; i < n; i++) cin >> points[i];
    for (int i = 0; i < n - 1; i++) {
      max_neighbour_dist = max(max_neighbour_dist, points[i + 1] - points[i]);
    }
    max_neighbour_dist = max(max_neighbour_dist, points[0]);
    max_close_gas_station = 2 * (x - points[n - 1]);
    cout << max(max_neighbour_dist, max_close_gas_station) << '\n';
  }
}