
#include <iostream>
using namespace std;

int main() {

    // Task 1
    int seconds;
    cin >> seconds;

    int hours = seconds / 3600;
    seconds = seconds % 3600;
    int minutes = seconds / 60;
    seconds = seconds % 60;

    cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;


    // Task 2
    double number;
    cin >> number;

    int hryvnia = number;
    int kopecks = (number - hryvnia) * 100;

    cout << hryvnia << " hryvnia " << kopecks << " kopecks" << endl;


    // Task 3
    double distance, time;
    cin >> distance;
    cin >> time;

    int min = time;
    int sec = (time - min) * 100;

    int totalSeconds = min * 60 + sec;

    double speed = distance / totalSeconds * 3.6;

    cout << "Distance: " << distance << " m" << endl;
    cout << "Time: " << min << " min " << sec << " sec = " << totalSeconds << " sec" << endl;
    cout << "Speed: " << speed << " km/h" << endl;


    // Task 4
    int days;
    cin >> days;

    int weeks = days / 7;
    int remainingDays = days % 7;

    cout << weeks << " weeks and " << remainingDays << " days" << endl;


    // Task 5
    double distance2, time2;
    cin >> distance2;
    cin >> time2;

    double speed2 = distance2 / time2;

    cout << "Speed: " << speed2 << " km/h" << endl;


    // Task 6
    double distance3, fuelConsumption;
    double price1, price2, price3;

    cin >> distance3;
    cin >> fuelConsumption;
    cin >> price1;
    cin >> price2;
    cin >> price3;

    double liters = distance3 * fuelConsumption / 100;

    cout << "Gasoline 1: " << liters * price1 << endl;
    cout << "Gasoline 2: " << liters * price2 << endl;
    cout << "Gasoline 3: " << liters * price3 << endl;


    // Task 7
    int daySeconds;
    cin >> daySeconds;

    int currentHours = daySeconds / 3600;
    daySeconds = daySeconds % 3600;
    int currentMinutes = daySeconds / 60;
    int currentSeconds = daySeconds % 60;

    cout << "Current time: "
         << currentHours << " hours "
         << currentMinutes << " minutes "
         << currentSeconds << " seconds" << endl;

    int remaining = 24 * 3600 -
                    (currentHours * 3600 + currentMinutes * 60 + currentSeconds);

    int remainingHours = remaining / 3600;
    remaining = remaining % 3600;
    int remainingMinutes = remaining / 60;
    int remainingSeconds = remaining % 60;

    cout << "Until midnight: "
         << remainingHours << " hours "
         << remainingMinutes << " minutes "
         << remainingSeconds << " seconds" << endl;


    // Task 8
    int workSeconds;
    cin >> workSeconds;

    int workDay = 8 * 3600;
    int workLeft = workDay - workSeconds;

    int workHours = workLeft / 3600;

    cout << "Hours left: " << workHours << endl;

}
