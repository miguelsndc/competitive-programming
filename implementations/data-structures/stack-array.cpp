#include <iostream>

template <typename E>
class Stack
{
private:
    E *stackArray;
    int stackSize;
    int maxSize;

    void increaseCapacity()
    {
        int newSize = maxSize * 2;
        int *newStackArray = new E[maxSize];
        for (int i = 0; i < stackSize; i++)
        {
            newStackArray[i] = stackArray[i];
        }
        delete[] stackArray;
        maxSize = newSize;
        stackArray = newStackArray;
    }

public:
    Stack(int size = 1)
    {
        stackSize = 0;
        maxSize = size;
        stackArray = new E[size];
    }

    ~Stack() { delete[] stackArray; };

    void push(E item)
    {
        if (stackSize >= maxSize)
        {
            increaseCapacity();
        }
        stackArray[stackSize++] = item;
    }

    E pop()
    {
        if (stackSize == 0)
        {
            throw std::runtime_error("Can't pop empty stack");
        }
        stackSize--;
        return stackArray[stackSize];
    }

    E peek()
    {
        if (stackSize == 0)
        {
            throw std::runtime_error("Can't peek empty stack");
        }
        return stackArray[stackSize - 1];
    }
};

int main()
{
    auto stack = new Stack<int>();

    std::cout << stack->pop();
}