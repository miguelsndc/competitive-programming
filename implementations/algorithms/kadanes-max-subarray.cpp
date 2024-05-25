#include <iostream>
#include <vector>

using namespace std;

int maxSumSubarray(vector<int> &A)
{
    int n = A.size();
    int local_max = 0;
    int global_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        local_max = max(A[i], A[i] + local_max);
        global_max = max(global_max, local_max);
    }
    return global_max;
}

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSumSubarray(vec);
}
