#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

string dfs(int level) {
    if (level == 0) return "P";
    return "B" + dfs(level - 1) + "P" + dfs(level - 1) + "B";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << dfs(4);
    // começa e termina com n B's
}