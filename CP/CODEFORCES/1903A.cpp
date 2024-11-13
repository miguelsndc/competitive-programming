#include <bits/stdc++.h>

#include <iostream>

using namespace std;

#define vi vector<int>

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  // runs in linear time always
  // pass constraints n <= 100 
  // if k >= 1 means we can use the principle of bubble sort so it always works
  // if k = 1 then
  //    if already sorted then yes
  //    if not sorted then no


  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vi numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }
    if (k == 1) {
      if (n == 1)
        cout << "yes\n";
      else if (n >= 1) {
        bool no = false;
        for (int i = 0; i < numbers.size() - 1; i++) {
          if (numbers[i] > numbers[i + 1]) {
            cout << "no\n";
            no = true;
            break;
          }
        }
        if (!no) {
          cout << "yes\n";
        }
      }
    } else {
      cout << "yes\n";
    }
  }
}
