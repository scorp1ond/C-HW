#include <iostream>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(a) ((a) * (a))
#define POWER(a, b) powerNumber((a), (b))
#define EVEN(a) ((a) % 2 == 0)
#define ODD(a) ((a) % 2 != 0)

double powerNumber(double number, int degree)
{
    double result = 1;
    int count = degree;

    if (count < 0)
        count = -count;

    for (int i = 0; i < count; i++)
        result *= number;

    if (degree < 0)
        result = 1 / result;

    return result;
}

int main()
{
    int a, b;
    std::cout << "enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "min: " << MIN(a, b) << '\n';
    std::cout << "max: " << MAX(a, b) << '\n';
    std::cout << "square: " << SQUARE(a) << '\n';

    int degree;
    std::cout << "enter degree: ";
    std::cin >> degree;

    if (a == 0 && degree < 0)
        std::cout << "power is undefined\n";
    else
        std::cout << "power: " << POWER(a, degree) << '\n';

    std::cout << "even: " << EVEN(a) << '\n';
    std::cout << "odd: " << ODD(a) << '\n';
}
