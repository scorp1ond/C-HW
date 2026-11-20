#include <iostream>

int main()
{
    // Task 1
    const int size = 5;
    int numbers[size], copy[size];

    std::cout << "Enter " << size << " integers: ";
    for (int* p = numbers; p < numbers + size; p++)
    {
        if (!(std::cin >> *p))
            return 0;
    }

    int* p = numbers;
    int* q = copy;
    while (p < numbers + size)
    {
        *q = *p;
        p++;
        q++;
    }

    std::cout << "Copied array: ";
    for (q = copy; q < copy + size; q++)
        std::cout << *q << ' ';
    std::cout << '\n';


    // Task 2
    std::cout << "Array in reverse order: ";
    p = numbers + size;
    while (p != numbers)
    {
        p--;
        std::cout << *p << ' ';
    }
    std::cout << '\n';

    return 0;
}
