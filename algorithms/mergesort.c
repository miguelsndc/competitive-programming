#include <stdio.h>
#include <stdlib.h>

/* the idea is to split the array into tiny subarray recursively
and then merge them through a per item comparison <this part is where the actual sort happens>

let A be a big array of size n

the base case is n = 1, so do this only if n > 1

let A be the array to be sorted with length n
let B be a subarray from 0 to floor n / 2
let C be a subarray from floor n / 2 to floor n - 1

call merge sort on B
call merge sort on C

this will split B and C until they become unitary

call merge(B, C, A)

this will merge the arrays and sort them

let k = 0;
let i and j be pointers to the beginning of B and C respectively
let p and q be pointers to the end of B and C respectively

if B[i] < C[j]
    place B[i] at A[k]
    i += 1
else
    place C[j] at A[k]
    j += 1

k += 1

do that until *one* of the subarrays is fully covered

if one of them is fully covered <whether i = p or j = q>
suppose i = p
then you must copy the rest of C to A
this means copy C[j to q - 1] to A[k to p + q - 1]
looks ugly asf but youre just filling the gaps.


merge sorts works by subdividing the arrays until they are sufficiently small
so comparation and sorting can be executed trivially. Mergesort uses the divide-and-conquer
approach, so intuitively if a list of size n is sorted in k steps, a list of size 2n
will be sorted in k + 1 steps (takes one step to go from 2n to n)
*/

// sorts array A[0..n-1] by recursive mergesort
// input: array A[0..n-1] of orderable elements
// outputs: array A[0..n-1] sorted in increasing order

void merge(int *list, int l, int m, int r)
{
    int B_length = m - l + 1;
    int C_length = r - m;

    int *B = (int *)malloc(B_length * sizeof(int));
    int *C = (int *)malloc(C_length * sizeof(int));

    if (B == NULL || C == NULL)
    {
        printf("Only god knows what to do here");
        return;
    }

    // copy data to new arrays
    for (int i = 0; i < B_length; i++)
    {
        B[i] = list[l + i];
    }

    for (int i = 0; i < C_length; i++)
    {
        C[i] = list[m + i + 1];
    }

    int i, j;
    i = j = 0;
    int k = l;

    while (i < B_length && j < C_length)
    {
        list[k] = (B[i] <= C[j]) ? B[i++] : C[j++];
        k++;
    }

    // Copy the stuff left in C to *list;

    while (i < B_length)
    {
        list[k] = B[i];
        k++;
        i++;
    }

    while (j < C_length)
    {
        list[k] = C[j];
        k++;
        j++;
    }

    free(B);
    free(C);
}

void sort(int *list, int l, int r)
{
    if (l < r)
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

void print_list(int *list, int size)
{
    printf("arr: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
}

int main()
{
    int list[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size_list = sizeof(list) / sizeof(int);
    print_list(list, size_list);
    merge_sort(list, size_list);
    print_list(list, size_list);
    return 0;
}
