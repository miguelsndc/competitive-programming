#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int n;
   int k = 0;
   cin >> n;

   for (int i = 0; i < n; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       if (a + b + c >= 2) {
           k++;
       }
   }
   cout << k;
    return 0;
}