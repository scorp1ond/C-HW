#include <iostream>

int main()
{
    // Task 1
    int seconds;
    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    std::cout << seconds / 3600 << " hours, ";
    std::cout << seconds % 3600 / 60 << " minutes, ";
    std::cout << seconds % 60 << " seconds\n";


    // Task 2
    double money;
    int hryvnias, coins;

    std::cout << "Enter money: ";
    std::cin >> money;

    hryvnias = money;
    coins = (money * 100 + 0.5) - hryvnias * 100;

    std::cout << hryvnias << " UAH " << coins << " kopiyok\n";


    // Task 3
    double distance, time, speed;
    int minutes, secs;

    std::cout << "Running speed calculation\n";
    std::cout << "Enter distance (meters): ";
    std::cin >> distance;
    std::cout << "Enter time (min.sec): ";
    std::cin >> time;

    minutes = time;
    secs = (time * 100 + 0.5) - minutes * 100;
    time = minutes * 60 + secs;
    speed = distance / time * 3.6;

    std::cout << "Distance: " << distance << " m\n";
    std::cout << "Time: " << minutes << " min " << secs;
    std::cout << " sec = " << time << " sec\n";
    std::cout << "Speed: " << speed << " km/h\n";


    // Task 4
    int days;
    std::cout << "Enter days: ";
    std::cin >> days;

    std::cout << days / 7 << " weeks and ";
    std::cout << days % 7 << " days\n";


    // Task 5
    double airport_distance, hours;

    std::cout << "Enter distance to airport (km): ";
    std::cin >> airport_distance;
    std::cout << "Enter travel time (hours): ";
    std::cin >> hours;

    std::cout << "Required speed: ";
    std::cout << airport_distance / hours << " km/h\n";


    // Task 6
    double trip_distance, fuel, price1, price2, price3;

    std::cout << "Enter distance (km): ";
    std::cin >> trip_distance;
    std::cout << "Enter fuel consumption (liters per 100 km): ";
    std::cin >> fuel;
    std::cout << "Enter prices of 3 types of fuel: ";
    std::cin >> price1 >> price2 >> price3;

    std::cout << "\nFuel type\tCost\n";
    std::cout << "Fuel 1\t\t" << trip_distance / 100 * fuel * price1 << '\n';
    std::cout << "Fuel 2\t\t" << trip_distance / 100 * fuel * price2 << '\n';
    std::cout << "Fuel 3\t\t" << trip_distance / 100 * fuel * price3 << '\n';


    // Task 7
    int day_seconds;

    std::cout << "Enter seconds since midnight: ";
    std::cin >> day_seconds;

    if (day_seconds >= 0 && day_seconds < 86400)
    {
        std::cout << "Current time: ";
        std::cout << day_seconds / 3600 << ":";
        std::cout << day_seconds % 3600 / 60 << ":";
        std::cout << day_seconds % 60 << '\n';

        int remaining = 86400 - day_seconds;

        std::cout << "Time until midnight: ";
        std::cout << remaining / 3600 << " hours, ";
        std::cout << remaining % 3600 / 60 << " minutes, ";
        std::cout << remaining % 60 << " seconds\n";
    }
    else
        std::cout << "Invalid time\n";


    // Task 8
    int work_seconds;

    std::cout << "Enter seconds since workday started: ";
    std::cin >> work_seconds;

    if (work_seconds >= 0 && work_seconds < 28800)
    {
        std::cout << "Full hours remaining: ";
        std::cout << (28800 - work_seconds) / 3600 << '\n';
    }
    else if (work_seconds >= 28800)
        std::cout << "Full hours remaining: 0\n";
    else
        std::cout << "Invalid time\n";
}
