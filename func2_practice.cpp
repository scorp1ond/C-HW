#include <iostream>

int power(int, int);
void stars(int);
int sum(int, int);
int minSumPosition(int[], int, int, int);

int main()
{
    // Task 1
    int n, p;
    std::cout << "enter the number and its power: ";
    std::cin >> n >> p;
    std::cout << "result: " << power(n, p) << '\n';

    // Task 2
    int star_num;
    std::cout << "enter the number of stars: ";
    std::cin >> star_num;
    stars(star_num);
    std::cout << '\n';

    // Task 3
    int a, b;
    std::cout << "enter a and b: ";
    std::cin >> a >> b;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    std::cout << "sum: " << sum(a, b) << '\n';

    // Task 4
    int arr[100];
    unsigned int seed = 12345;

    for (int i = 0; i < 100; i++)
    {
        seed = seed * 1103515245 + 12345;
        arr[i] = (seed % 101) - 50;
    }

    std::cout << "array: ";
    for (int i = 0; i < 100; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    int position = minSumPosition(arr, 0, 0, 1000000);

    int total = 0;
    for (int i = position; i < position + 10; i++)
    {
        total += arr[i];
    }

    std::cout << "position: " << position + 1 << '\n';
    std::cout << "minimum sum: " << total << '\n';
}

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    return n * power(n, p - 1);
}

void stars(int n)
{
    if (n == 0)
    {
        return;
    }

    std::cout << "*";
    stars(n - 1);
}

int sum(int a, int b)
{
    if (a > b)
    {
        return 0;
    }

    return a + sum(a + 1, b);
}

int minSumPosition(int arr[], int pos, int min_pos, int min_sum)
{
    if (pos > 90)
    {
        return min_pos;
    }

    int current_sum = 0;

    for (int i = pos; i < pos + 10; i++)
    {
        current_sum += arr[i];
    }

    if (current_sum < min_sum)
    {
        min_sum = current_sum;
        min_pos = pos;
    }

    return minSumPosition(arr, pos + 1, min_pos, min_sum);
}