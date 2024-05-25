#include <bits/stdc++.h>

using namespace std;

// Sorts an array by comparison counting
// Input: An array A[0..n − 1] of orderable elements
// Output: Array S[0..n − 1] of A’s elements sorted in nondecreasing order
void comparison_counting_sort(int *A, int size)
{
    int n = size;
    int count[n];
    int prev[n];
    for (int i = 0; i < size; i++)
        prev[i] = A[i];

    memset(count, 0, sizeof(int) * n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] < A[j])
                count[j]++;
            else
                count[i]++;
        }
    }

    for (int i = 0; i < n; i++)
        A[count[i]] = prev[i];
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int list[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    comparison_counting_sort(list, 9);
    for (int i = 0; i < 9; i++)
        cout << list[i];

    return 0;
}