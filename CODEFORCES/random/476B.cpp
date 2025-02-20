#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;

    map<char, int> mp1;
    map<char, int> mp2;

    cin >> s1 >> s2;

    int s1pos = 0, s2pos = 0, unknown = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '+')
            s1pos++;
        else
            s1pos--;

        mp2[s2[i]]++;
        mp1[s1[i]]++;

        if (s2[i] == '+')
            s2pos++;
        else if (s2[i] == '-')
            s2pos--;
        else
            unknown++;
    }

    int plusdif = mp1['+'] - mp2['+'];
    int minusdif = mp1['-'] - mp2['-'];

    return 0;
}