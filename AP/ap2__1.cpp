#include <iostream>
#include <memory>

using namespace std;

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int hoare_partition(int *list, int left, int right) {
    int pivot = list[left]; // first
    int i = left - 1;
    int j = right + 1;

    while (i < j){// means we still have elements to check
        do {
            i++;
        } while (list[i] > pivot);
        do {
            j--;
        } while (list[j] < pivot);

        // avoid unnecessary swaps
        if (i <= j) {
            swap(&list[i], &list[j]);
        }
    }
    // when the loop is done, j is in the split position of pivot, swap.
    swap(&list[left], &list[j]);
    return j;
}

void qsort_recr(int *list, int left, int right) {
    if (left < right) {
        int split_pos = hoare_partition(list, left, right);

        qsort_recr(list, left, split_pos);
        qsort_recr(list, split_pos + 1, right);
    }
}

void qsort(int *list, int size) {
    return qsort_recr(list, 0, size - 1);
}

void print(int *list, int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i] << ' ';
    }
    cout << '\n';
}

int main () {
    int no_cases;
    cin >> no_cases;

    for (int i = 0; i < no_cases; i++) {
        int length;
        cin >> length;

        int *array = new int [length];

        for (int j = 0; j < length; j++) {
            int temp;
            cin >> temp;
            array[j] = temp;
        }

        qsort(array, length);
        print(array, length);

        delete[] array;

    }
    return 0;
}















