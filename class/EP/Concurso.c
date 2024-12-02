#include <stdlib.h>
#include <stdio.h>

struct candidate
{
    char name[31];
    int score;
    int age;
};

typedef struct candidate Candidate;

int compare_scores(Candidate *cd1, Candidate *cd2)
{
    return cd1->score >= cd2->score ? 1 : 0;
}

int compare_ages(Candidate *cd1, Candidate *cd2)
{
    return cd1->age >= cd2->age ? 1 : 0;
}

int min(int i, int j)
{
    return i < j ? i : j;
}

void merge(Candidate *list, int l, int r, int size, int (*compare)(Candidate *, Candidate *))
{
    Candidate *temp = (Candidate *)malloc(size * sizeof(Candidate));

    if (temp == NULL)
    {
        printf("FAILED ALLOCATING MEMORY");
        exit(EXIT_FAILURE);
    }
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

    free(temp);
}

void merge_sort(Candidate *list, int l, int r, int size, int (*compare)(Candidate *, Candidate *))
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(list, l, m, size, compare);
        merge_sort(list, m + 1, r, size, compare);
        merge(list, l, r, size, compare);
    }
}

int main()
{
    int c;
    scanf("%d", &c);
    for (int i = 1; i <= c; i++)
    {
        int n, v;
        scanf("%d %d", &n, &v);
        Candidate *list = (Candidate *)malloc(n * sizeof(Candidate));

        for (int j = 0; j < n; j++)
        {
            scanf("%s %d %d", list[j].name, &list[j].score, &list[j].age);
        }

        merge_sort(list, 0, n - 1, n, compare_ages);
        merge_sort(list, 0, n - 1, n, compare_scores);

        printf("cargo %d:\n", i);
        for (int k = 0; k < min(v, n); k++)
        {
            printf("%s\n", list[k].name);
        }

        for (int k = 0; k < v - n; k++)
        {
            printf("x\n");
        }

        free(list);
    }
}