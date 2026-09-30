#include <iostream>

int main() {

    // task 1

    int year;
    std::cin >> year;

    int days = 365 + (year % 4 == 0);

    std::cout << days << '\n';


    // task 2

    int hryvnia, kopiyky;

    std::cin >> hryvnia >> kopiyky;

    hryvnia = hryvnia + kopiyky / 100;
    kopiyky = kopiyky % 100;

    std::cout << hryvnia << " hryvnias " << kopiyky << " kopiyky\n";


    // task 3

    double a, b, c;

    std::cin >> a >> b >> c;

    double volume = a * b * c;

    std::cout << volume << '\n';

    // task 4


    // task 5

    double r;
    double pi = 3.14;

    std::cin >> r;

    double volume_sphere = (4.0 / 3.0) * pi * r * r * r;

    std::cout << volume_sphere << '\n';
}
