#include <iostream>

using namespace std;

void merge(int list[], int l, int r, int size)
{
    int *temp = new int [size];
    for (int i = l; i <= r; i++) {
        temp[i] = list[i];
    }
    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;
    for (int curr = l; curr <= r; curr++) {
        if (i1 == m + 1) {
            list[curr] = temp[i2++];
        } else if (i2 > r) {
            list[curr] = temp[i1++];
        } else if (temp[i1] <= temp[i2]) {
            list[curr] = temp[i1++];
        } else {
            list[curr] = temp[i2++];
        }
    }

    delete[] temp;
}

void _sort(int list[], int left, int right, int size)
{
    // there's margin to split
    if (left < right)
    {
        int middle = (left + right) / 2;
        _sort(list, left, middle, size);
        _sort(list, middle + 1, right, size);

        merge(list, left, right, size);
    }

}

void merge_sort(int list[], int size)
{
    _sort(list, 0, size - 1, size);
}

int main()
{
    int n;
    cin >> n;
    int *list = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    merge_sort(list, n);
    for (int i = 0; i < n; i++) {
        cout << list[i];
    }
    return 0;
}