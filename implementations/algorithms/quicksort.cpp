#include <iostream>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int list[], int low, int high)
{
    int pivot = list[low];
    // expand bounds because do-while.
    int i = low - 1;
    int j = high + 1;

    while (i < j)
    {
        do
        {
            i++;
        } while (list[i] < pivot);
        do
        {
            j--;
        } while (list[j] > pivot);
        // avoid unnecessary swaps
        if (i <= j)
        {
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[low], &list[j]);
    return j;
}

void quick_sort_recursion(int list[], int low, int high)
{
    // we have margin to split
    if (low < high)
    {
        int split_pos = partition(list, low, high);
        // notice we don't include split_pos because it's a reserved position.
        quick_sort_recursion(list, low, split_pos);
        quick_sort_recursion(list, split_pos + 1, high);
    }
}

void quick_sort(int list[], int size)
{
    return quick_sort_recursion(list, 0, size - 1);
}

int main()

{
    int list[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size = sizeof(list) / sizeof(int);

    for (const auto &el: list)
    {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    quick_sort(list, size);
    for (const auto &el: list)
    {
        std::cout << el << ' ';
    }
    return 0;
}