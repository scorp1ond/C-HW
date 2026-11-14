#include <iostream>

int main()
{
    int a;
    std::cout << "Enter a (a <= 500): ";
    if (!(std::cin >> a)) return 0;
    while (a > 500)
    {
        std::cout << "Enter a not greater than 500: ";
        if (!(std::cin >> a)) return 0;
    }

    long long sum = 0;
    for (long long i = a; i <= 500; i++)
        sum += i;
    std::cout << "Sum: " << sum << '\n';


    int x, y;
    std::cout << "\nEnter x and y: ";
    if (!(std::cin >> x >> y)) return 0;

    if (x == 0 && y <= 0)
        std::cout << "Undefined power\n";
    else
    {
        double base = x, power = 1;
        long long count = y;
        if (count < 0)
        {
            base = 1 / base;
            count = -count;
        }

        while (count > 0)
        {
            if (count % 2 != 0)
                power *= base;
            count /= 2;
            if (count > 0)
                base *= base;
        }
        std::cout << "Power: " << power << '\n';
    }


    sum = 0;
    for (int i = 1; i <= 1000; i++)
        sum += i;
    std::cout << "\nAverage: " << sum / 1000.0 << '\n';


    std::cout << "\nEnter a (1-20): ";
    if (!(std::cin >> a)) return 0;
    while (a < 1 || a > 20)
    {
        std::cout << "Enter a from 1 to 20: ";
        if (!(std::cin >> a)) return 0;
    }

    long long product = 1;
    for (int i = a; i <= 20; i++)
        product *= i;
    std::cout << "Product: " << product << '\n';


    int k;
    std::cout << "\nEnter k: ";
    if (!(std::cin >> k)) return 0;
    for (int i = 1; i <= 10; i++)
        std::cout << k << " * " << i << " = " << (long long)k * i << '\n';


    int number;
    std::cout << "\nEnter A: ";
    if (!(std::cin >> number)) return 0;
    long long absolute = number;
    if (absolute < 0)
        absolute = -absolute;

    bool found = false;
    std::cout << "Values of B: ";
    for (long long b = 2; b * b <= absolute; b++)
    {
        if (number % (b * b) == 0 && (number / (b * b)) % b != 0)
        {
            std::cout << -b << ' ' << b << ' ';
            found = true;
        }
    }
    if (!found)
        std::cout << "none";
    std::cout << '\n';


    std::cout << "\nEnter number: ";
    if (!(std::cin >> number)) return 0;
    absolute = number;
    if (absolute < 0)
        absolute = -absolute;

    std::cout << "Divisors: ";
    if (number == 0)
        std::cout << "all non-zero integers";
    else
    {
        for (long long i = 1; i * i <= absolute; i++)
        {
            if (absolute % i == 0)
            {
                std::cout << -i << ' ' << i << ' ';
                long long other = absolute / i;
                if (other != i)
                    std::cout << -other << ' ' << other << ' ';
            }
        }
    }
    std::cout << '\n';


    int first, second;
    std::cout << "\nEnter two numbers: ";
    if (!(std::cin >> first >> second)) return 0;

    long long firstAbsolute = first, secondAbsolute = second;
    if (firstAbsolute < 0)
        firstAbsolute = -firstAbsolute;
    if (secondAbsolute < 0)
        secondAbsolute = -secondAbsolute;

    long long limit = firstAbsolute;
    if (limit == 0 || (secondAbsolute != 0 && secondAbsolute < limit))
        limit = secondAbsolute;

    std::cout << "Common divisors: ";
    if (limit == 0)
        std::cout << "all non-zero integers";
    else
    {
        for (long long i = 1; i * i <= limit; i++)
        {
            if (limit % i == 0)
            {
                if (first % i == 0 && second % i == 0)
                    std::cout << -i << ' ' << i << ' ';
                long long other = limit / i;
                if (other != i && first % other == 0 && second % other == 0)
                    std::cout << -other << ' ' << other << ' ';
            }
        }
    }
    std::cout << '\n';


    char symbol;
    int choice, height, width;
    std::cout << "\nEnter symbol: ";
    if (!(std::cin >> symbol)) return 0;
    std::cout << "1 - Square\n2 - Rectangle\n3 - Triangle\nChoose: ";
    if (!(std::cin >> choice)) return 0;
    while (choice < 1 || choice > 3)
    {
        std::cout << "Choose from 1 to 3: ";
        if (!(std::cin >> choice)) return 0;
    }

    std::cout << "Enter height: ";
    if (!(std::cin >> height)) return 0;
    while (height < 1)
    {
        std::cout << "Enter positive height: ";
        if (!(std::cin >> height)) return 0;
    }

    width = height;
    if (choice == 2)
    {
        std::cout << "Enter width: ";
        if (!(std::cin >> width)) return 0;
        while (width < 1)
        {
            std::cout << "Enter positive width: ";
            if (!(std::cin >> width)) return 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        int columns = width;
        if (choice == 3)
            columns = i + 1;
        for (int j = 0; j < columns; j++)
            std::cout << symbol;
        std::cout << '\n';
    }
    return 0;
}

