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

template <typename E>
class Stack
{
public:
    E *stackArray;
    int stackSize;
    Stack(int size = 1000)
    {
        stackSize = 0;
        stackArray = new E[size];
    }

    ~Stack() { delete[] stackArray; };

    void push(E item)
    {
        stackArray[stackSize++] = item;
    }

    E pop()
    {
        if (stackSize != 0) {
            stackSize--;
            return stackArray[stackSize];
        }
        return '\0';
    }

    E peek()
    {
        if (stackSize != 0) {
            return stackArray[stackSize - 1];
        }
        return '\0';
    }
};

char open(char c) {
    if (c == ']') return '[';
    return '(';
}

int type(char c) {
    if (c == '(') return 0;
    if (c == '[') return 0;
    return 1;
}

void solve() {
    string s;
    getline(cin, s);
    Stack<char> stack;

    bool possible = true;
    for (char c: s) {
        if (type(c) == 0) {
            stack.push(c);
        } else {
            if (stack.stackSize != 0) {
                if (stack.peek() != open(c)) {
                    possible = false; break;
                } else {
                    stack.pop();
                }
            } else {
                possible = false; break;
            }
        }
    }

    if (stack.stackSize != 0 && s.size() > 0) possible = false;
    cout << (possible ? "Yes\n": "No\n");
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int tt = 1; cin >> tt;
    getline(cin, s);
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}