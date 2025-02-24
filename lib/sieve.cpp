#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vi divisores(int n) {
    vi d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    d.push_back(n);
    return d;
}

const int ms = 1e6;
bool is_prime[ms];
int big_prime[ms];
void sieve(){
    fill(is_prime, is_prime + ms, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<ms; i++){
        if(is_prime[i]){
            big_prime[i] = i;
            for(int j=i+i; j<ms; j+=i){
                big_prime[j] = i;
                is_prime[j] = false;
            }
        }
    }
}

vector<int> get_primes(int n){
    vector<int> primes;
    while(n > 1){
        primes.push_back(big_prime[n]);
        n/=big_prime[n];
    }
    return primes;
}

vector<pair<int, int>> prime_fact(int n) {
    vector<pair<int, int>> primes;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while(n % i == 0) n /= i, cnt++;
        if (cnt > 0) primes.push_back({i, cnt});
    }
    if (n > 1) primes.push_back({n, 1});
    return primes;
}

const int LIM = 1e6 + 5;
int divisors[LIM];
vector<int> sieve_raw(){
    memset(divisors, 0, sizeof(divisors));
    
    for(int i = 2; i < LIM; i++)
        for(int j = i; j < LIM; j += i)
            divisors[j]++;
            
    vector<int> primes;
    for(int i = 2; i < LIM; i++)
        if(divisors[i] == 1)
            primes.push_back(i);
            
    return primes;
}

const int LIM = 1e6 + 5;
bool isPrime[LIM];

vector<int> fast_sieve(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    
    vector<int> primes;
    for(int i = 2; i < LIM; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i*2; j < LIM; j += i){
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

long long sumDivisors[LIM];
void calc_sumdiv(){
    for(int i = 1; i < LIM; i++){
        for(int j = i; j < LIM; j += i){
            sumDivisors[j] += i;
        }
    }
}

long long numDivisors[LIM];
void calc_numdiv(){
    for(int i = 1; i < LIM; i++){
        for(int j = i; j < LIM; j += i){
            numDivisors[j]++;
        }
    }
}

// É só fazer x = x*c / gcd(a, b) e y = y*c / gcd(a, b)
