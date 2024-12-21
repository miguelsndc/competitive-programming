#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int dfs(int i, int count, int health, vector<int> &potions, bool take) {
    if (health < 0) {
        return count - 1;
    } else if (i >= potions.size()) {
        return count;
    }

    int left = dfs(i + 1, count + 1, health + potions[i], potions, true);
    int right = dfs(i + 1, count, health, potions, false);

    return max(left, right);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> potions(n);
    for(int i = 0; i < n; i++) {
        cin >> potions[i];
    }

}