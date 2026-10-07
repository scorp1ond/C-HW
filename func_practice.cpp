#include <iostream>
void rectangle(int, int);
void factorial(int);
void primeNumber(int);
void cubeNumber(int);
void biggerNumberFinder(int, int);
bool positiveNumber(int);
void minMaxFinder(int[], int);
void reverseArray(int[], int);
int primeNumbersCount(int[], int);

int main()
{
    // Task 1
    std::cout << "enter (height, width): ";
    int n, k;
    std::cin >> n >> k;
    rectangle(n, k);

    // Task 2
    int ract_num;
    std::cout << "enter the number you want to know the factorial of: ";
    std::cin >> ract_num;
    factorial(ract_num);

    // Task 3
    int prime_num;
    std::cout << "enter the number you want to check: ";
    std::cin >> prime_num;
    primeNumber(prime_num);

    // Task 4
    int cube_num;
    std::cout << "enter the number you want cubed: ";
    std::cin >> cube_num;
    cubeNumber(cube_num);

    // Task 5
    int n1, n2;
    std::cout << "enter 2 numbers: ";
    std::cin >> n1 >> n2;
    biggerNumberFinder(n1, n2);

    // Task 6
    int positive_num;
    std::cout << "enter a number: ";
    std::cin >> positive_num;

    if (positiveNumber(positive_num))
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }

    // Task 7
    int arr[5];

    std::cout << "enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr[i];
    }

    minMaxFinder(arr, 5);

    // Task 8
    std::cout << "reversed array: ";
    reverseArray(arr, 5);

    // Task 9
    std::cout << "number of prime numbers: " << primeNumbersCount(arr, 5) << '\n';
}

void rectangle(int n, int k) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::cout << "s";
        }
        std::cout << '\n';
    }
}

void factorial(int n) {
    int fact = 1;
    for (int i = n; i > 0; i--) {
        fact = fact * i;
    }
    std::cout << "the factorial is " << fact << '\n';
}

void primeNumber(int n) {
    bool prime = true;

    if (n < 2)
    {
        prime = false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            prime = false;
        }
    }

    if (prime)
    {
        std::cout << "the number is prime\n";
    }
    else
    {
        std::cout << "the number is not prime\n";
    }
}

void cubeNumber(int cube_num) {
    std::cout << "the cube of " << cube_num << " is " << cube_num * cube_num * cube_num << '\n';
}

void biggerNumberFinder(int n1, int n2) {
    if (n1 > n2) {
        std::cout << n1 << " number is bigger";
    }
    else {
        std::cout << n2 << " number is bigger";
    }
}

bool positiveNumber(int n) {
    if (n > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void minMaxFinder(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }

        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }

    std::cout << "minimum: " << min << ", number: " << min_index + 1 << '\n';
    std::cout << "maximum: " << max << ", number: " << max_index + 1 << '\n';
}

void reverseArray(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int primeNumbersCount(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        bool prime = true;

        if (arr[i] < 2)
        {
            prime = false;
        }

        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                prime = false;
            }
        }

        if (prime)
        {
            count++;
        }
    }

    return count;
}