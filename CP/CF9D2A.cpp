#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int y, w;
    cin >> y >> w;

    int max = y >= w ? y : w;
    int chances = 6 - max + 1;

    int total = 6;

    if (chances == 6) {
        chances = total = 1;
    } 
    else if (chances == 0) {
        chances = 0;
        total = 1;
    } 
    else if (chances % 2 == 0) {
            chances /= 2;
            total /= 2;
    }
    else if (chances % 3 == 0) {
            chances /= 3;
            total /= 3;
    }
    
    cout << chances << '/' << total;
        
    return 0;
}