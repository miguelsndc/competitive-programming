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

void solve() {
    // precedence: + -  * / ^ ()
    // operands: a..z
    // ((a+t)*((b+(a+c))^(c+d)))
    // opstack :
    // valstack: at+bac++cd+^*
    int n; cin >> n;
    vector<string> expr(n);
    for (int i = 0; i < n; i++) {
        cin >> expr[i];
    }
    int precedence[256];
    precedence['+'] = 0;
    precedence['-'] = 0;
    precedence['*'] = 1;
    precedence['/'] = 1;
    precedence['^'] = 2;
    for (string e: expr) {
        vector<char> op;
        string result;

        for (char c: e) {
            if (c == '(') op.push_back(c);
            else if (c == '+') op.push_back(c);
            else if (c == '-') op.push_back(c);
            else if (c == '*') op.push_back(c);
            else if (c == '/') op.push_back(c);
            else if (c == ')') {
                while(op.back() != '(') {
                    result += op.back();
                    op.pop_back();
                }
                op.pop_back();
            }
            else if (c == '^') op.push_back(c);
            else result += c;
        }
        if (sz(op) > 0) {
            vector<pair<int,char>>v;
            for (int i = 0; i < sz(op); i++) {
                v.push_back({op[i], i});
            }
            stable_sort(begin(v), end(v), [&precedence](auto a, auto b) {
                if (precedence[a.first] == precedence[b.first]) {
                    return a.second < b.second;
                }
                return precedence[a.first] > precedence[b.first];
            });
            for (auto c: v) {
                result += c.first;
            }
        }
        cout << result << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}