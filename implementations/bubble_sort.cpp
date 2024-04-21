#include <iostream>

using namespace std;

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void bubble_sort(int *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // if j is bigger than j + 1 bring it forward
            if (list[j] > list[j + 1]) {
                swap(&list[j], &list[j + 1]);
            }
        }
    }
}

int main () {
    int list[] = {5,2,4,3, 10, 30, 20,60};
    int size = sizeof(list) / sizeof(int);
    bubble_sort(list, size);
    for (const auto &el: list) {
        cout << el << ' ';
    }
    return 0;
}
