#include <iostream>

using namespace std;

int binary_search(int *list, int size, int target);

int main () {
    int length;
    cin >> length;

    int *array = new int [length];

    for (int i = 0; i < length; i++) {
       int temp;
       cin >> temp;
       array[i] = temp;
    }

    int no_elements;
    cin >> no_elements;

    for (int i = 0; i < no_elements; i++) {
        int temp;
        cin >> temp;

        int index = binary_search(array, length, temp);

        if (index > 0) {
            cout << index << '\n';
        } else {
            cout << 'x' << '\n';
        }
    }

    delete[] array;
    return 0;
}

int b_search_recursive_step(int *list, int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int middle = (low + high) / 2;

    if (list[middle] == target) {
        return middle;
    } else if (list[middle] < target) {
       return b_search_recursive_step(list, middle + 1, high, target);
   }

    return b_search_recursive_step(list, low, middle - 1, target);
}

int binary_search(int *list, int size, int target) {
    return b_search_recursive_step(list, 0, size - 1, target);
}
