#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Sorts an array of integers from a limited range by distribution counting
// Input: An array A[0..n − 1] of integers between l and u (l ≤ u)
// Output: Array S[0..n − 1] of A’s elements sorted in nondecreasing order
void distribution_counting_sort(int *A, int size, int l, int u)
{
    if (l >= u)
        throw runtime_error("Lower bound must must be strictly less than upper bound");

    int S[size];
    int D[u - l + 1];
    memset(D, 0, (u - l + 1) * sizeof(int)); // initialize frequencies
    for (int i = 0; i < size; i++)           // compute frequencies and copy A to S;
    {
        D[A[i] - l]++;
        S[i] = A[i];
    }
    for (int j = 1; j < (u - l + 1); j++)
        D[j] = D[j - 1] + D[j]; // accumulate distributions

    for (int i = size - 1; i >= 0; i--) // put each value into its sorted position
    {
        int j = S[i] - l;
        A[D[j] - 1] = S[i];
        D[j]--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int list[] = {1, 2, 2, 3, 1, 3, 2, 3, 1};
    distribution_counting_sort(list, 9, 1, 3);
    for (int i = 0; i < 9; i++)
        cout << list[i];

    return 0;
}