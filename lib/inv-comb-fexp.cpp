#define ll long long
const int MOD =1e9 + 7;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a, ll p){ // inverso modular mod p primo
    return fexp(a, p - 2);
}
ll fact[1000000]; // computar fatoriais
ll comb(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}