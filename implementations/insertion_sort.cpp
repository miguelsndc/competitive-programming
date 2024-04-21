#include <iostream>

using namespace std;

void insertion_sort(int *list, int size) {
    for (int i = 1; i < size; i++) {
        int v = list[i];
        int j = i - 1;
        while(j >= 0 && list[j] > v) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = v;
    }
}

int main() {
    int list[] = {9, 1, 4, 3, 5, 6, 7, 8, 6, 4};
    int size = sizeof(list) / sizeof(int);
    insertion_sort(list, size);
    for(const auto &el: list)  {
        cout << el << " ";
    }
    return 0;
}