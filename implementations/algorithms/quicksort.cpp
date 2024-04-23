#include <iostream>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int list[], int l, int r)
{
    int pivot = list[l];
    int i = l;
    int j = r + 1;
    while (i < j) {
        do {
            i++;
        } while (list[i] < pivot && i < r);
        do {
            j--;
        } while (list[j] > pivot);
        swap(&list[i], &list[j]);
    }
    swap(&list[i], &list[j]);
    swap(&list[l], &list[j]);
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