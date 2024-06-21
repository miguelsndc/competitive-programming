#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // count the number of non-empty prefixes of an array
    // plan 1 will be:
    //  sort the array
    //  do a prefix sum
    //  if the prefix sum up to i - 1 is equal to i (not summed yet)
    //  we add 1
    //  there's some base cases however
    //  [0] is a good array because 0 + 0 = 0
    //  [1] is not good because 1 + 1 = 1
    //  assuming that arrays of length 1 whose element != 0 are bad.
    //  [0, 1,1, 2, 4]
    // 0 ok
    // 0 + 1 = 1 ok
    // 0 + 1 + 1 = 2 ok
    // 0 + 1+1+2 = 4 ok
    // we can have up to n - 1 prefix sums
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi numbers(n);
        for (int i = 0; i < n; i++) cin >> numbers[i];
        ll max_so_far = INT_MIN;
        ll sum = 0;
        ll good = 0;
        for (int j = 0; j < n; j++) {
            sum += numbers[j];
            max_so_far = max(max_so_far, (ll)numbers[j]);
            if ((sum - max_so_far) == max_so_far) {
                good++;
            }
        }
        cout << good << '\n';
    }

    return 0;
}