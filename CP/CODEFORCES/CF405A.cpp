#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    int *list = new int[c];
    for (int i = 0; i < c; i++) {
        int a;
        cin >> a;
        list[i] = a;
    }

    for (int i = 0; i < c - 1; i++) {
        int min = i;
        for (int j = i + 1; j < c; j++) {
            if(list[j] < list[min]) {
                min = j;
            }
        }
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }

    for (int i = 0; i < c; i++) {
        cout << list[i] << ' ';
    }

    delete[] list;
    return 0;
}