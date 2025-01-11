#include <iostream>
#include <cmath>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int *list = new int [n];

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        list[i] = t;
    }

    quick_sort(list, 0, n - 1);

    int l = 0;
    int r = 1;
    int sum = 0;
    while (r < n) {
        int diff = abs(list[l] - list[r]);
        if (diff > k) {
            l++;
        } else if (diff == k) {
            sum++;
            r++;
        } else {
            r++;
        }
    }
    // 1 2 3 4 5 6 -- k = 2

    cout << sum;

    return 0;
}