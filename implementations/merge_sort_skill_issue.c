#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

int main()
{
    int array[] = {9, 1, 8, 2, 6, 3, 5, 4, 7, 11, 23, 24, 12, 66};
    int length = sizeof(array) / sizeof(array[0]);

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort(int *a, int length)
{
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        merge(a, l, m, r);
    }
}

void merge(int *a, int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    int *temp_left = (int *)malloc(left_length * sizeof(int));
    int *temp_right = (int *)malloc(right_length * sizeof(int));

    int i, j, k;

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = a[l + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = a[m + i + 1];
    }

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }

    free(temp_left);
    free(temp_right);
}
