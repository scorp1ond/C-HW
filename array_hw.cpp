#include <iostream>

int main()
{
    // Task 1
    const int size = 10;
    int numbers[size];
    int seed;

    std::cout << "Enter starting number (0-100): ";
    std::cin >> seed;

    while (seed < 0 || seed > 100)
    {
        std::cout << "Enter number from 0 to 100: ";
        std::cin >> seed;
    }

    std::cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        seed = (seed * 37 + 17) % 101;
        numbers[i] = seed - 50;
        std::cout << numbers[i] << ' ';
    }

    int min = numbers[0], max = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
        if (numbers[i] > max)
            max = numbers[i];
    }

    std::cout << "\nMin: " << min << '\n';
    std::cout << "Max: " << max << '\n';


    // Task 2
    double profit[12];
    int a, b;

    std::cout << "Enter profit for 12 months: ";
    for (int i = 0; i < 12; i++)
        std::cin >> profit[i];

    std::cout << "Enter two months (1-12): ";
    std::cin >> a >> b;

    while (a < 1 || a > 12 || b < 1 || b > 12)
    {
        std::cout << "Enter months from 1 to 12: ";
        std::cin >> a >> b;
    }

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int minMonth = a - 1, maxMonth = a - 1;

    for (int i = a; i < b; i++)
    {
        if (profit[i] < profit[minMonth])
            minMonth = i;
        if (profit[i] > profit[maxMonth])
            maxMonth = i;
    }

    std::cout << "Min profit month: " << minMonth + 1 << '\n';
    std::cout << "Max profit month: " << maxMonth + 1 << '\n';


    // Task 3
    const int capacity = 100;
    double arr[capacity];
    int n;

    std::cout << "Enter array size (1-100): ";
    std::cin >> n;

    while (n < 1 || n > capacity)
    {
        std::cout << "Enter size from 1 to 100: ";
        std::cin >> n;
    }

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    double sum = 0, product = 1, evenProduct = 1, betweenSum = 0;
    int minIndex = 0, maxIndex = 0;
    int first = -1, last = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
            if (first == -1)
                first = i;
            last = i;
        }

        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;

        if ((i + 1) % 2 == 0)
            evenProduct *= arr[i];
    }

    if (minIndex > maxIndex)
    {
        int temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }

    for (int i = minIndex + 1; i < maxIndex; i++)
        product *= arr[i];

    if (first != -1)
        for (int i = first + 1; i < last; i++)
            betweenSum += arr[i];

    std::cout << "Sum of negative numbers: " << sum << '\n';

    if (maxIndex - minIndex > 1)
        std::cout << "Product between min and max: " << product << '\n';
    else
        std::cout << "No elements between min and max\n";

    if (n > 1)
        std::cout << "Product at even positions: " << evenProduct << '\n';
    else
        std::cout << "No elements at even positions\n";

    std::cout << "Sum between first and last negative numbers: " << betweenSum << '\n';


    // Task 4
    int original[10], left[5], right[5];

    std::cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        std::cin >> original[i];

    for (int i = 0; i < 5; i++)
    {
        left[i] = original[i];
        right[i] = original[i + 5];
    }

    std::cout << "First array: ";
    for (int i = 0; i < 5; i++)
        std::cout << left[i] << ' ';

    std::cout << "\nSecond array: ";
    for (int i = 0; i < 5; i++)
        std::cout << right[i] << ' ';
    std::cout << '\n';


    // Task 5
    int arr1[5], arr2[5], result[5];

    std::cout << "Enter 5 numbers for first array: ";
    for (int i = 0; i < 5; i++)
        std::cin >> arr1[i];

    std::cout << "Enter 5 numbers for second array: ";
    for (int i = 0; i < 5; i++)
        std::cin >> arr2[i];

    for (int i = 0; i < 5; i++)
        result[i] = arr1[i] + arr2[i];

    std::cout << "Result: ";
    for (int i = 0; i < 5; i++)
        std::cout << result[i] << ' ';
    std::cout << '\n';
}
