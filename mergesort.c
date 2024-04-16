#include <stdio.h>

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

void merge(int B[], int l, int m, int r);

int main()
{
    int list[8] = {9, 1, 8, 2, 7, 3, 6, 8};
    int size_list = sizeof(list) / sizeof(int);

    merge_sort(list, size_list);

    return 0;
}

void merge_sort(int list[], int size)
{
    int m = size / 2;
    merge_recursion(list, 0, m, size - 1);
}

void merge_recursion(int list[], int l, int m, int r)
{
}