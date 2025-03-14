 #include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 5;

// caso tenha colisão use 1<<61 - 1 e 1<<31 -1 como mod e retorne um pair
 
const ll MOD1 = 188'888'881;
const ll MOD2 = 1e9 + 7;
const ll base = 137;
 
ll pow1[MAXN];
ll pow2[MAXN];
 
bool called = false;
void calc_pow()
{
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = (pow1[i - 1] * base) % MOD1,
        pow2[i] = (pow2[i - 1] * base) % MOD2;
}
 
struct PolyHash
{
    vector<pair<ll, ll>> pref;
    PolyHash(string &s)
    {
        if(!called) {
            calc_pow();
            called = true; // pra garantir q so chama uma vez por hash e q eu nao va esquecer essa bomba
        }

        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
            pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }
 
    ll operator()(int a, int b)
    {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return (h1 << 32LL) | h2;
    }
};
