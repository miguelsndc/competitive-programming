#include <stdio.h>

void merge(int *list, int l, int r, int size)
{
    int temp[size];
    for (int i = l; i <= r; i++)
    {
        temp[i] = list[i];
    }
    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;
    for (int curr = l; curr <= r; curr++)
    {
        if (i1 == m + 1)
        {
            list[curr] = temp[i2++];
        }
        else if (i2 > r)
        {
            list[curr] = temp[i1++];
        }
        else if (temp[i1] <= temp[i2])
        {
            list[curr] = temp[i1++];
        }
        else
        {
            list[curr] = temp[i2++];
        }
    }
}

void merge_sort(int *list, int l, int r, int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(list, l, m, size);
        merge_sort(list, m + 1, r, size);

        merge(list, l, r, size);
    }
}

void print_list(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main()
{

    int list[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size_list = sizeof(list) / sizeof(int);

    print_list(list, size_list);
    merge_sort(list, 0, size_list - 1, size_list);
    print_list(list, size_list);
    return 0;
}