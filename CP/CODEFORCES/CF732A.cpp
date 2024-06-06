#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, r;
    cin >> k >> r;

    int count = 1;
    int shovels = k;

    while((shovels % 10 != 0) && (shovels % 10 != r)) {
        count++;
        shovels+= k;
    }

    cout << count;

}