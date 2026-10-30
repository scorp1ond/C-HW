#include <iostream>

void hanoi(int, char, char, char);

int main()
{
    int n;
    std::cout << "enter number of disks: ";
    std::cin >> n;

    if (n < 1)
    {
        std::cout << "invalid number of disks\n";
    }
    else
    {
        hanoi(n, 'A', 'C', 'B');
    }
}

void hanoi(int n, char source, char target, char auxiliary) {
    if (n <= 0)
    {
        return;
    }

    hanoi(n - 1, source, auxiliary, target);

    std::cout << "Move disk " << n << " from " << source << " to " << target << '\n';

    hanoi(n - 1, auxiliary, target, source);
}
