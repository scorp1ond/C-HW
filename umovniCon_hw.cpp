#include <iostream>

int main()
{
    // Task 1
    int n, max;
    std::cout << "Enter 7 numbers: ";
    std::cin >> max;

    for (int i = 1; i < 7; i++)
    {
        std::cin >> n;
        if (n > max)
            max = n;
    }

    std::cout << "Max: " << max << '\n';


    // Task 2
    int ab, bc, weight, consumption;
    std::cout << "Enter AB, BC and weight: ";
    std::cin >> ab >> bc >> weight;

    if (weight > 2000 || weight < 0)
    {
        std::cout << "Flight is impossible\n";
    }
    else
    {
        if (weight <= 500)
            consumption = 1;
        else if (weight <= 1000)
            consumption = 4;
        else if (weight <= 1500)
            consumption = 7;
        else
            consumption = 9;

        if (ab < 0 || bc < 0 || ab * consumption > 300 || bc * consumption > 300)
            std::cout << "Flight is impossible\n";
        else
        {
            int fuel = bc * consumption - (300 - ab * consumption);

            if (fuel < 0)
                fuel = 0;

            std::cout << "Fuel needed at B: " << fuel << " liters\n";
        }
    }


    // Task 3
    int sales1, sales2, sales3;
    double salary1, salary2, salary3;
    std::cout << "Enter sales of 3 managers: ";
    std::cin >> sales1 >> sales2 >> sales3;

    if (sales1 < 0 || sales2 < 0 || sales3 < 0)
    {
        std::cout << "Invalid sales\n";
    }
    else
    {
        if (sales1 < 500)
            salary1 = 200 + sales1 * 0.03;
        else if (sales1 <= 1000)
            salary1 = 200 + sales1 * 0.05;
        else
            salary1 = 200 + sales1 * 0.08;

        if (sales2 < 500)
            salary2 = 200 + sales2 * 0.03;
        else if (sales2 <= 1000)
            salary2 = 200 + sales2 * 0.05;
        else
            salary2 = 200 + sales2 * 0.08;

        if (sales3 < 500)
            salary3 = 200 + sales3 * 0.03;
        else if (sales3 <= 1000)
            salary3 = 200 + sales3 * 0.05;
        else
            salary3 = 200 + sales3 * 0.08;

        std::cout << "Manager 1: " << salary1 << '\n';
        std::cout << "Manager 2: " << salary2 << '\n';
        std::cout << "Manager 3: " << salary3 << '\n';

        if (salary1 >= salary2 && salary1 >= salary3)
        {
            salary1 += 200;
            std::cout << "Best manager: 1\n";
        }
        else if (salary2 >= salary1 && salary2 >= salary3)
        {
            salary2 += 200;
            std::cout << "Best manager: 2\n";
        }
        else
        {
            salary3 += 200;
            std::cout << "Best manager: 3\n";
        }

        std::cout << "Final salaries:\n";
        std::cout << "Manager 1: " << salary1 << '\n';
        std::cout << "Manager 2: " << salary2 << '\n';
        std::cout << "Manager 3: " << salary3 << '\n';
    }


    // Task 4
    int choice, lines, delays;
    double income;

    std::cout << "Menu:\n";
    std::cout << "1 - Calculate required lines\n";
    std::cout << "2 - Calculate possible delays\n";
    std::cout << "3 - Calculate salary\n";
    std::cout << "Choose: ";
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Enter desired income and delays: ";
        std::cin >> income >> delays;

        if (income < 0 || delays < 0)
            std::cout << "Invalid input\n";
        else
        {
            int required = (income + (delays / 3) * 20) * 2;
            std::cout << "Required lines: " << required << '\n';
        }
    }
    else if (choice == 2)
    {
        std::cout << "Enter lines and desired income: ";
        std::cin >> lines >> income;

        if (lines < 0 || income < 0)
            std::cout << "Invalid input\n";
        else
        {
            int delaysAllowed = ((lines / 100) * 50 - income) / 20;
            if (delaysAllowed < 0)
                delaysAllowed = 0;

            std::cout << "Possible delays: " << delaysAllowed * 3 << '\n';
        }
    }
    else if (choice == 3)
    {
        std::cout << "Enter lines and delays: ";
        std::cin >> lines >> delays;

        if (lines < 0 || delays < 0)
            std::cout << "Invalid input\n";
        else
        {
            income = (lines / 100) * 50 - (delays / 3) * 20;

            if (income <= 0)
                std::cout << "Vasya will not receive a salary\n";
            else
                std::cout << "Salary: " << income << "\n";
        }
    }
    else
    {
        std::cout << "Invalid choice\n";
    }
}
