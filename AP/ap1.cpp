#include <iostream>
#include <memory>

void _merge(int list[], int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    std::unique_ptr<int[]> temp_left(new int[left_length]);
    std::unique_ptr<int[]> temp_right(new int[right_length]);

    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = list[left + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        temp_right[i] = list[middle + i + 1];
    }

    int i, j, k;
    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            list[k] = temp_left[i];
            i++;
        }
        else
        {
            list[k] = temp_right[j];
            j++;
        }
    }
}

void _sort(int list[], int left, int right)
{
    // theres margin to split
    if (left < right)
    {
        int middle = (left + right) / 2;
        _sort(list, left, middle);
        _sort(list, middle + 1, right);

        _merge(list, left, middle, right);
    }
}

void merge_sort(int list[], int size)
{
    _sort(list, 0, size - 1);
}

int main()
{
    int no_cases;
    std::cin >> no_cases;

    for (int i = 0; i < no_cases; i++)
    {
        int no_elements;
        std::cin >> no_elements;

        int array[no_elements]; // why is this not complaing of non-constant array size ?? 

        for (int j = 0; j < no_elements;  j++)
        {
            std::cin >> array[j];
        }

        merge_sort(array, no_elements);

        for (const auto &el: array) {
            std::cout << el << ' ';
        }
    }
}
