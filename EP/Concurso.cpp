#include <iostream>

using namespace std;

struct Candidate
{
    char name[31];
    int score;
    int age;
};

bool compare_scores(Candidate *cd1, Candidate *cd2)
{
    return cd1->score >= cd2->score;
}

bool compare_ages(Candidate *cd1, Candidate *cd2)
{
    return cd1->age >= cd2->age;
}

void merge(Candidate *list, int l, int r, int size, bool (*compare)(Candidate *, Candidate *))
{
    Candidate temp[size];
    for (int i = l; i <= r; i++)
    {
        temp[i] = list[i];
    }

    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;

    for (int curr = l; curr <= r; curr++)
    {
        if (i1 == m + 1)
        {
            list[curr] = temp[i2++];
        }
        else if (i2 > r)
        {
            list[curr] = temp[i1++];
        }
        else if (compare(&temp[i1], &temp[i2]))
        {
            list[curr] = temp[i1++];
        }
        else
        {
            list[curr] = temp[i2++];
        }
    }
}

void merge_sort(Candidate *list, int l, int r, bool (*compare)(Candidate *, Candidate *), int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(list, l, m, compare, size);
        merge_sort(list, m + 1, r, compare, size);
        merge(list, l, r, size, compare);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    for (int k = 0; k < c; k++)
    {
        int n, v;
        cin >> n >> v;
        Candidate list[n];

        for (int j = 0; j < n; j++)
        {
            cin >> list[j].name >> list[j].score >> list[j].age;
        }

        merge_sort(list, 0, n - 1, compare_ages, n);
        merge_sort(list, 0, n - 1, compare_scores, n);

        cout << "cargo " << k + 1 << ':' << '\n';

        for (int z = 0; z < min(n, v); z++)
        {
            cout << list[z].name << '\n';
        }

        for (int z = 0; z < v - n; z++)
        {
            cout << 'x' << '\n';
        }
    }

    return 0;
}