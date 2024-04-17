#include <iostream>

void _partition(int list[], int low, int high)
{
    int pivot = list[0];
    int i = low;
    int j = high;
}

void partition(int list[], int size)
{
    return _partition(list, 0, size - 1);
}

int main() {
    int example_list[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int size_ex = sizeof(example_list) / sizeof(int);
    partition(example_list, size_ex);
    return 0; 
}