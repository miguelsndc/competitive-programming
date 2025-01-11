#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 0 0 1
// 0 0 1
// 0 1 0

void moveZeroes(vector<int> &nums)
{
    int last_non_zero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[last_non_zero++] = nums[i];
        }
    }

    for (int i = last_non_zero; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec = {0, 0, 1};
    moveZeroes(vec);
    for (const auto &i : vec)
    {
        cout << i << ' ';
    }

    return 0;
}