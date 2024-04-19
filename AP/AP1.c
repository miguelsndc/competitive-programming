// Implemente o algoritmo mergesort para ordenar um array de inteiros de forma não-decrescente.

// ENTRADA

// A entrada consiste de vários casos. A primeira linha contém o inteiro c (1 ≤ c ≤ 10), o número de casos.
// A primeira linha de cada caso contém o inteiro n (1 ≤ n ≤ 105), o tamanho do array que deve ser ordenado.
// A segunda linha de cada caso contém n inteiros separados por espaço, os elementos do array.

// 3
// 7
// 84 1 6 27 48 12 3
// 1
// 3
// 5
// 4 5 1 9 2

// SAÍDA

// Para cada caso, imprima uma linha com os elementos do array ordenados de forma não-decrescente
// separados por espaço.

// 1 3 6 12 27 48 84
// 3
// 1 2 4 5 9

#include <stdio.h>
#include <stdlib.h>

void merge(int *list, int l, int m, int r)
{
    int left_size = m - l + 1;
    int right_size = r - m;

    int *left = (int *)malloc(sizeof(int) * left_size);
    int *right = (int *)malloc(sizeof(int) * right_size);

    for (int i = 0; i < left_size; i++)
    {
        left[i] = list[l + i];
    }

    for (int i = 0; i < right_size; i++)
    {
        right[i] = list[m + 1 + i];
    }

    int i, j, k;
    // iterating over the full list and choosing which subitem to merge
    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if ((i < left_size) && (j >= right_size || left[i] <= left[j]))
        {
            list[k] = left[i++];
        }
        else
        {
            list[k] = right[j++];
        }
    }

    free(left);
    free(right);
}

void sort(int *list, int l, int r)
{
    // means we have margin to split
    if (l > r)
    {
        int m = (l + r) / 2;

        sort(list, l, m);
        sort(list, m + 1, r);

        merge(list, l, m, r);
    }
}

void merge_sort(int *list, int size)
{
    sort(list, 0, size - 1);
}

void print_list(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // number of cases
    int c;
    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {
        // array length
        int n;
        scanf("%d", &n);

        int *vec = (int *)malloc(sizeof(int) * n);

        // insert elements into vec
        for (int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            vec[j] = temp;
        }

        merge_sort(vec, n);
        print_list(vec, n);

        free(vec);
    }
}