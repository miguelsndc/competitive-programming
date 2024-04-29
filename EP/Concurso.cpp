#include <iostream>

using namespace std;

struct Candidate
{
    char *name;
    int score;
    int age;

    Candidate(char *name, int score, int age)
    {
        name = name;
        score = score;
        age = age;
    }
    Candidate()
    {
        name = new char[31];
        score = age = 0;
    }
};

bool compare(Candidate *cd1, Candidate *cd2, char *key)
{
    if (key == "score")
    {
        return cd1->score >= cd2->score;
    }
    else
    {
        return cd1->age >= cd2->age;
    }
}

void merge(Candidate *list, int l, int r, char *key, int size)
{
    Candidate *temp = new Candidate[size];
    for (int i = 0; i < size; i++)
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
        else if (compare(&temp[i1], &temp[i2], key))
        {
            list[curr] = temp[i1++];
        }
        else
        {
            list[curr] = temp[i2++];
        }
    }
}

void merge_sort(Candidate *list, int l, int r, char *key, int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(list, 0, m, key, size);
        merge_sort(list, m + 1, r, key, size);
        merge(list, l, r, key, size);
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
        int i, v;
        cin >> i >> v;
        Candidate *list = new Candidate[i];

        for (int j = 0; j < i; j++)
        {
            char name[31];
            int score;
            int age;

            cin >> list[j].name >> list[j].score >> list[j].age;
        }

        merge_sort(list, 0, i - 1, "score", i);
        merge_sort(list, 0, i - 1, "age", i);

        cout << "cargo " << k + 1 << ':' << '\n';

        for (int z = 0; z < v; z++)
        {
            if (z >= i)
            {
                cout << 'x' << '\n';
            }
            else
            {
                cout << list[z].name << '\n';
            }
        }
    }

    return 0;
}