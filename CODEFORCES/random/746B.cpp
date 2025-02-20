#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    string word;

    cin >> word;
    // volga -- logva; _ _ l _ _
    // voga -- ogva _ o l _ _
    // vga -- gva  _ o l g _

    // baba -- abba  _ a _ _
    char letters[n];
    int middle = n % 2 == 0 ? (n - 1) / 2 : n / 2;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
    {
        if ((n - i) % 2 != 0)
        {
            letters[middle + right] = word[i];
            left++;
        }
        else
        {

            letters[middle - left] = word[i];
            right++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << letters[i];

    return 0;
}