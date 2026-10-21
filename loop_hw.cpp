#include <iostream>

int main()
{
    // Task 1
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;

    for (int i = 0; i <= n; i++)
        std::cout << i << ' ';
    std::cout << '\n';


    // Task 2
    int a, b;
    std::cout << "Enter two boundaries: ";
    std::cin >> a >> b;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    std::cout << "All numbers: ";
    for (int i = a; i <= b; i++)
        std::cout << i << ' ';

    std::cout << "\nEven numbers: ";
    for (int i = a; i <= b; i++)
        if (i % 2 == 0)
            std::cout << i << ' ';

    std::cout << "\nOdd numbers: ";
    for (int i = a; i <= b; i++)
        if (i % 2 != 0)
            std::cout << i << ' ';

    std::cout << "\nMultiples of 7: ";
    for (int i = a; i <= b; i++)
        if (i % 7 == 0)
            std::cout << i << ' ';
    std::cout << '\n';


    // Task 3
    int x, y, sum = 0;
    std::cout << "Enter two boundaries: ";
    std::cin >> x >> y;

    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    for (int i = x; i <= y; i++)
        sum += i;

    std::cout << "Sum: " << sum << '\n';


    // Task 4
    int number, total = 0;

    std::cout << "Enter numbers (0 to stop): ";
    std::cin >> number;

    while (number != 0)
    {
        total += number;
        std::cin >> number;
    }

    std::cout << "Sum: " << total << '\n';


    // Task 5
    int secret = 237, guess, attempts = 0;

    std::cout << "Guess the number (1-500, 0 to quit): ";
    std::cin >> guess;

    while (guess != 0 && guess != secret)
    {
        attempts++;

        if (guess < secret)
            std::cout << "The number is greater\n";
        else
            std::cout << "The number is smaller\n";

        std::cout << "Enter guess: ";
        std::cin >> guess;
    }

    if (guess == secret)
    {
        attempts++;
        std::cout << "Correct! Attempts: " << attempts << '\n';
    }
    else
        std::cout << "Game ended. Attempts: " << attempts << '\n';


    // Task 6
    int choice;
    double amount, result;

    while (true)
    {
        std::cout << "\nCurrency converter\n";
        std::cout << "1 - UAH to USD\n";
        std::cout << "2 - USD to UAH\n";
        std::cout << "3 - UAH to EUR\n";
        std::cout << "4 - EUR to UAH\n";
        std::cout << "5 - USD to EUR\n";
        std::cout << "6 - EUR to USD\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 0)
            break;

        std::cout << "Enter amount: ";
        std::cin >> amount;

        switch (choice)
        {
            case 1:
                result = amount / 42;
                std::cout << "USD: " << result << '\n';
                break;

            case 2:
                result = amount * 42;
                std::cout << "UAH: " << result << '\n';
                break;

            case 3:
                result = amount / 49;
                std::cout << "EUR: " << result << '\n';
                break;

            case 4:
                result = amount * 49;
                std::cout << "UAH: " << result << '\n';
                break;

            case 5:
                result = amount * 42 / 49;
                std::cout << "EUR: " << result << '\n';
                break;

            case 6:
                result = amount * 49 / 42;
                std::cout << "USD: " << result << '\n';
                break;

            default:
                std::cout << "Invalid choice\n";
        }
    }
}
