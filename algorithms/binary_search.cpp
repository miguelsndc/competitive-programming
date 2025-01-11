#include <iostream>

int binary_search_iterative(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] > target)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1;
}

int _binary_search_recursion_fn(int arr[], int low, int high, int target)
{
    if (high < low)
        return -1;

    int middle = (low + high) / 2;

    if (arr[middle] == target)
    {
        return middle;
    }
    else if (arr[middle] > target)
    {
        return _binary_search_recursion_fn(arr, low, middle - 1, target);
    }
    else
    {
        return _binary_search_recursion_fn(arr, low + 1, high, target);
    }
}
int binary_search_recursion(int arr[], int size, int target)
{
    return _binary_search_recursion_fn(arr, 0, size - 1, target);
}

int main()
{
    int list[] = {3, 0, 2, 4, 1};
    int size = sizeof(list) / sizeof(int);

    int i_target = binary_search_recursion(list, size, 2);

    std::cout << i_target << "\n";
    return 0;
}