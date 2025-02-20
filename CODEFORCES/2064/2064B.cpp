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

void solve() {
    int n; cin >> n;
    /*
        começa com um mapa de frequencia de cada caracter já que ai <= n
        queremos o maior subarray com ocorrencia de cada elemento 1
        len é o tam do maior subarray com todos c ocorrencia 1 terminando em i7
        o ultimo loop diz que, cheguei no mx, entao o array começa em i - len[i] + 2
        (1 based) e termina em i + 1 (1 based)
    */
    vi a(n), freq(n + 1);
    for (int &x: a) cin >> x;
    for (int &x: a) freq[x]++;
    vi len(n + 1);
    len[0] = freq[a[0]] == 1;
    for (int i = 1; i < n; i++) {
        if (freq[a[i]] == 1) {
            len[i] = len[i - 1] + 1;
        }
    }
    int mx = *max_element(begin(len), end(len));
    if (mx == 0) {
        cout << "0\n";
        return;
    } 
    for (int i = 0; i < n; i++) {
        if (len[i] == mx) {
            cout << i - len[i] + 2 << " " << i + 1 << '\n';
            return;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}