#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

// f (k) k tamanho da string
// retorna se existe caracter k dominante
// monotonica pois sempre true a partir de um certo k (k <= tam da string)
// passa em nlogn checagem + binsearch

bool ok(int k, string &s) {

    int c = 0;
    map<pair<char, int>, int> mp;
    for (int i = 0; i <= s.size() - k; i++) {
        c++;
        string sub = s.substr(i, k);
        for (int j = 0; j < sub.size(); j++) {
            if (mp.find({i, sub[j]}) == mp.end()){
                mp[{0, sub[j]}]++;
                mp[{i, sub[j]}]++;
            }
        }
    }
    int maxc = -1;
    for(auto [k, v]: mp) {
        maxc = max(maxc, v);
    }

    return maxc >= c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int x = 0;
    for (int b = s.size(); b >= 1; b /= 2) {
        while(!ok(x + b, s)) x += b;
    }
    cout << x + 1;
}