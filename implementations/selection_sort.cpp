#include <iostream>

using namespace std;

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selection_sort(int *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        swap(&list[i], &list[min]);
    }
}

int main () {
    int list[] = {9, 1, 8, 2, 7, 3,6, 4 , 5, 45, 7, 44, 23, 78};
    int size = sizeof(list) / sizeof(int);
    selection_sort(list, size);
    for (const auto &el: list) {
        cout << el << ' ';
}
    return 0;
}