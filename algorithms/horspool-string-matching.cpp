#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P[0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and
//  filled with shift sizes computed by formula m - 1 - j;
const int ALPHABET_LENGTH = 256;
array<int, ALPHABET_LENGTH> create_shift_table(string &pattern)
{
    array<int, ALPHABET_LENGTH> table;
    for (int i = 0; i < ALPHABET_LENGTH; i++)
        table[i] = pattern.length();
    for (int i = 0; i < pattern.length() - 2; i++)
        table[pattern[i]] = pattern.length() - 1 - i;
    return table;
}

int horspool_matching(string pattern, string text)
{
    auto table = create_shift_table(pattern);
    int m = pattern.length();
    int n = text.length();
    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table[text[i]];
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t = "JIM_SA W_ME_IN_A_BARBERSHOP";
    string p = "BARBER";

    cout << horspool_matching(p, t);

    return 0;
}