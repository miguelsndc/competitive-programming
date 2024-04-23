#include <iostream>
#include <memory>

void merge(int list[], int l, int r)
{
    int *temp = new int [l + r];
    for (int i = l; i <= r; i++) {
        temp[i] = list[i];
    }
    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;
    for (int curr = l; curr <= r; curr++) {
        if (i1 == m + 1) {
            list[curr] = temp[i2++];
        } else if (i2 > r) {
            list[curr] = temp[i1++];
        } else if (temp[i1] <= temp[i2]) {
            list[curr] = temp[i1++];
        } else {
            list[curr] = temp[i2++];
        }
    }

    delete[] temp;
}

void _sort(int list[], int left, int right)
{
    // there's margin to split
    if (left < right)
    {
        int middle = (left + right) / 2;
        _sort(list, left, middle);
        _sort(list, middle + 1, right);

        merge(list, left, right);
    }
}

void merge_sort(int list[], int size)
{
    _sort(list, 0, size - 1);
}

int main()
{
    int list[] = { 9, 12,2, 1, 79, 14, 1, 3, 2,5, 4, 6, 3, 7, 6, 9};
    int size = sizeof(list) / sizeof(int);
    merge_sort(list, size);
    for (const auto el : list)
    {
        std::cout << el << ' ';
    }
    return 0;
}