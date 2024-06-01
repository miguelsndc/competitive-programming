#include <bits/stdc++.h>

using namespace std;

int h(string K, int capacity) {
    int len = K.length() / 4;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        string sub = K.substr(i * 4, (i * 4) + 4);
        int mult = 1;
        for (int j = 0; j < 4; j++) {
            sum += sub[j] * mult;
            mult *= 256;
        }
    }
    string sub = K.substr(len * 4);
    int mult = 1;
    int s_len = sub.length();
    for (int j = 0; j < s_len; j++) {
        sum += sub[j] * mult;
        mult *= 256;
    }
    return abs(sum) % capacity;
}
