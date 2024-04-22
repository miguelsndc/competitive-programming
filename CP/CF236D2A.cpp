#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    vector<char> ch_list;
    for (char &i: s) {
        bool found = false;
        for (char &j: ch_list) {
            if (i == j) {
                found = true;
            }
        }
        if(!found) {
            ch_list.push_back(i);
        }
    }

    if (ch_list.size() % 2 != 0) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }

    return 0;
}