#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

// count in how many possible ways i can reach point E from point S 
// if i can move either 1, 2 or 3 steps at a time

// assume that if pass over E it doesnt count

int s = 0, e = 0, c = 0;
void f(int from) {
    if (from == e) {
        c++;
        return;
    }
    if (from > e) {
        return;
    }

    f(from + 1);
    f(from + 2);
    f(from + 3);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> e;
    f(s);    
    cout << c;
}