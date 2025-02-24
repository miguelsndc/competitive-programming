#include<bits/stdc++.h>

// This calculates B^P (mod m) as fast as lighting
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
        int a = (p >> i) & 1;
        if (a == 1)
            x = (x * power) % m;
        power = (power * power) % m;
    }
    return x;
}
