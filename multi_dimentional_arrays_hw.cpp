#include <iostream>

int main()
{
    const int rows = 2, cols = 6;

    // Task 1
    double arr1[rows][cols], number;

    std::cout << "Enter number: ";
    std::cin >> number;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            arr1[i][j] = number;
            number *= 2;
        }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr1[i][j] << ' ';
        std::cout << '\n';
    }


    // Task 2
    double arr2[rows][cols];

    std::cout << "Enter number: ";
    std::cin >> number;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            arr2[i][j] = number;
            number++;
        }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr2[i][j] << ' ';
        std::cout << '\n';
    }


    // Task 3
    int arr3[rows][cols], result[rows][cols];
    int seed, shifts, direction;

    std::cout << "Enter starting number (0-100): ";
    std::cin >> seed;

    while (seed < 0 || seed > 100)
    {
        std::cout << "Enter number from 0 to 100: ";
        std::cin >> seed;
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            seed = (seed * 37 + 17) % 101;
            arr3[i][j] = seed % 10;
        }

    std::cout << "Array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr3[i][j] << ' ';
        std::cout << '\n';
    }

    std::cout << "Enter number of shifts: ";
    std::cin >> shifts;

    while (shifts < 0)
    {
        std::cout << "Enter a non-negative number: ";
        std::cin >> shifts;
    }

    std::cout << "1 - Left\n";
    std::cout << "2 - Right\n";
    std::cout << "3 - Up\n";
    std::cout << "4 - Down\n";
    std::cout << "Choose: ";
    std::cin >> direction;

    while (direction < 1 || direction > 4)
    {
        std::cout << "Choose from 1 to 4: ";
        std::cin >> direction;
    }

    if (direction == 1 || direction == 2)
        shifts %= cols;
    else
        shifts %= rows;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            switch (direction)
            {
                case 1:
                    result[i][(j - shifts + cols) % cols] = arr3[i][j];
                    break;

                case 2:
                    result[i][(j + shifts) % cols] = arr3[i][j];
                    break;

                case 3:
                    result[(i - shifts + rows) % rows][j] = arr3[i][j];
                    break;

                case 4:
                    result[(i + shifts) % rows][j] = arr3[i][j];
                    break;
            }
        }

    std::cout << "Result:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << result[i][j] << ' ';
        std::cout << '\n';
    }
}
