#include <stdio.h>
#include <assert.h>

/*

Requirements:
- Array must be sorted;

Two pointer method
- Start pointer and End pointer

Suppose arr = {10, 20, 30, 40, 50, 60, 70, 80}
low = 0
high = length of arr
middle = floor of (low + high) / 2
target: parameter

 0   1   2   3   4   5   6
{10, 20, 30, 40, 50, 60, 70}
             ^       __
             |
            mid: 3

search target = 60

is mid == target ?
    no it isn't

is mid > target ?
    not it isn't

is mid < target ?
    yes it is

then we conclude that the target must be in the right hand side
since the list is sorted, therefore:

low = mid + 1: 4
mid = floor of (low + high) / 2: (4 + 6) / 2 = 5

 0   1   2   3   4   5   6
{10, 20, 30, 40, 50, 60, 70}
                     ^
                     |
                    mid: 3
                    __


is mid == target?
    yes it is

then return target.
*/

int bsearch(int list[], int target, int size)
{
    int low = 0;
    int high = size;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (list[mid] == target)
        {
            return mid;
        }
        else if (list[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// compare
// figure out boundaries
// call function again with new boundaries
// base case:
// success -> list[mid] == target return mid
// fail high < low return -1
int bsearch_recursive(int list[], int low, int high, int target)
{
    if (high < low)
        return -1;

    int middle = (low + high) / 2;

    if (list[middle] == target)
        return middle;

    if (list[middle] > target)
    {
        high = middle - 1;
    }
    else
    {
        low = middle + 1;
    }

    return bsearch_recursive(list, low, high, target);
}

int main()
{
    int list[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(list) / sizeof(int);

    assert(bsearch(list, 10, size) == 0);
    assert(bsearch(list, 80, size) == 7);
    assert(bsearch(list, 83, size) == -1);

    assert(bsearch_recursive(list, 0, size, 10) == 0);
    assert(bsearch_recursive(list, 0, size, 80) == 7);
    assert(bsearch_recursive(list, 0, size, 23) == -1);
}