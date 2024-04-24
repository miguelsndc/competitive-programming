#include <iostream>

using namespace std;

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition (int *list, int l, int r) {
    int pivot = list[l];
    int i = l;
    int j = r + 1;
    while (i < j) {
        do {
            i++;
        } while (list[i] < pivot && i < r);
        do {
            j--;
        } while (list[j] > pivot);
        swap(&list[i], &list[j]);
    }
    swap(&list[i], &list[j]);
    swap(&list[l], &list[j]);
    return j;
}

void quick_sort(int *list, int l, int r) {
    if (l < r) {
        int s = partition(list, l, r);

        quick_sort(list, l, s - 1);
        quick_sort(list, s + 1, r);
    }
}

// -----------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int *a = new int [n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
        sum += temp;
    }

    quick_sort(a, 0, n - 1);

    int m;
    cin >> m;

    // 10 8 7 4 3 1 1
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << sum - a[n - q] << ' ';
    }

    return 0;
}