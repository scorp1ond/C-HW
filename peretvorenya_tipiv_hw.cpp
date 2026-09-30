#include <iostream>

int main() {

    // task 1

    double r1, r2, r3, r0;

    std::cin >> r1 >> r2 >> r3;

    r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);

    std::cout << r0 << '\n';


    // task 2

    double l, r, s;
    double pi = 3.14;

    std::cin >> l;

    r = l / (2 * pi);
    s = pi * r * r;

    std::cout << s << '\n';


    // task 3

    double v, t, a, distance;

    std::cin >> v >> t >> a;

    distance = v * t + (a * t * t) / 2;

    std::cout << distance << '\n';


    // task 4

    std::cout << "Nothing else matters\n";
    std::cout << "Metallica\n";


    // task 5

    std::cout << "Every hunter wants\n";
    std::cout << "    Green\n";
    std::cout << "        Blue\n";
    std::cout << "            Red\n";
    std::cout << "                Orange\n";
    std::cout << "                    Yellow\n";
    std::cout << "                        Violet\n";
}
