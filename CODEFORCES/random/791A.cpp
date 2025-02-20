#include <bits/stdc++.h>

using namespace std;

int main () {
    float a, b;
    cin >> a >> b;
    float n = float((log(b/a)/log(3.0/2.0)))+ 1;
    cout << (int)n;
    return 0;
}
