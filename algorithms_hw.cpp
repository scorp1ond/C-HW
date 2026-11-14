#include <iostream>

void flip(int[], int);
bool sorted(int[], int);
bool findFlips(int[], int, int, int[], int, int);

int main()
{
    long long mobile[100], home[100];
    int n;
    std::cout << "Enter number of users (1-100): ";
    if (!(std::cin >> n))
        return 0;

    while (n < 1 || n > 100)
    {
        std::cout << "Enter number from 1 to 100: ";
        if (!(std::cin >> n))
            return 0;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "User " << i + 1 << " (mobile and home numbers): ";
        if (!(std::cin >> mobile[i] >> home[i]))
            return 0;
        while (mobile[i] < 0 || home[i] < 0)
        {
            std::cout << "Enter two non-negative numbers: ";
            if (!(std::cin >> mobile[i] >> home[i]))
                return 0;
        }
    }

    for (int choice = 1; choice <= 2; choice++)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++)
            {
                bool wrongOrder;
                if (choice == 1)
                    wrongOrder = mobile[j] > mobile[j + 1];
                else
                    wrongOrder = home[j] > home[j + 1];

                if (wrongOrder)
                {
                    long long temp = mobile[j];
                    mobile[j] = mobile[j + 1];
                    mobile[j + 1] = temp;
                    temp = home[j];
                    home[j] = home[j + 1];
                    home[j + 1] = temp;
                }
            }
        if (choice == 1)
            std::cout << "Sorted by mobile:\n";
        else
            std::cout << "Sorted by home:\n";
        std::cout << "Mobile\tHome\n";
        for (int i = 0; i < n; i++)
            std::cout << mobile[i] << '\t' << home[i] << '\n';
    }


    int a[100];
    std::cout << "\nEnter array size (1-100): ";
    if (!(std::cin >> n))
        return 0;

    while (n < 1 || n > 100)
    {
        std::cout << "Enter size from 1 to 100: ";
        if (!(std::cin >> n))
            return 0;
    }

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
        if (!(std::cin >> a[i]))
            return 0;

    for (int i = 0; i < n - 1; i++)
    {
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swaps++;
            }
        }
        std::cout << "Swaps: " << swaps << '\n';
        if (swaps == 0)
            break;
    }
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';


    int radius[9], rank[9], path[18];
    std::cout << "\nEnter number of pancakes (1-9): ";
    if (!(std::cin >> n))
        return 0;

    while (n < 1 || n > 9)
    {
        std::cout << "Enter number from 1 to 9: ";
        if (!(std::cin >> n))
            return 0;
    }
    std::cout << "Enter distinct positive integer radii from TOP to BOTTOM.\n";
    for (int i = 0; i < n; i++)
    {
        bool valid;
        do
        {
            std::cout << "Radius: ";
            if (!(std::cin >> radius[i]))
                return 0;
            valid = radius[i] > 0;
            for (int j = 0; j < i; j++)
                if (radius[i] == radius[j])
                    valid = false;
            if (!valid)
                std::cout << "Use a positive radius different from the others.\n";
        } while (!valid);
    }
    for (int i = 0; i < n; i++)
    {
        rank[i] = 1;
        for (int j = 0; j < n; j++)
            if (radius[j] < radius[i])
                rank[i]++;
    }

    int count = 0;
    while (!findFlips(rank, n, count, path, 0, 0))
        count++;
    std::cout << "Minimum operations: " << count << '\n';
    for (int i = 0; i < count; i++)
    {
        std::cout << "Flip top " << path[i] << " pancakes.\n";
        flip(radius, path[i]);
    }
    std::cout << "Result from BOTTOM to TOP: ";
    for (int i = n - 1; i >= 0; i--)
        std::cout << radius[i] << ' ';
    std::cout << '\n';
    return 0;
}

void flip(int a[], int k)
{
    for (int i = 0; i < k / 2; i++)
    {
        int temp = a[i];
        a[i] = a[k - 1 - i];
        a[k - 1 - i] = temp;
    }
}

bool sorted(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

bool findFlips(int a[], int n, int left, int path[], int depth, int lastFlip)
{
    if (sorted(a, n))
        return true;
    if (left == 0)
        return false;

    int breaks = (a[n - 1] != n);
    for (int i = 0; i < n - 1; i++)
    {
        int difference = a[i] - a[i + 1];
        if (difference != 1 && difference != -1)
            breaks++;
    }
    if (breaks > left)
        return false;

    for (int k = 2; k <= n; k++)
    {
        if (k == lastFlip)
            continue;
        flip(a, k);
        path[depth] = k;
        bool found = findFlips(a, n, left - 1, path, depth + 1, k);
        flip(a, k);
        if (found)
            return true;
    }
    return false;
}

