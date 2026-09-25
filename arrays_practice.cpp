

#include <iostream>
using namespace std;

int main() {

    // Task 1
    double profit[12];
    double total = 0;
    double maxprofit, minprofit;
    int maxmonth = 0;
    int minmonth = 0;

   

    for (int i = 0; i < 12; i++) {
        cout << "Enter profit for month " << i + 1 << ": ";
        cin >> profit[i];
        total += profit[i];
    }

    maxprofit = profit[0];
    minprofit = profit[0];

    for (int i = 1; i < 12; i++) {
        if (profit[i] > maxprofit) {
            maxprofit = profit[i];
            maxmonth = i;
        }

        if (profit[i] < minprofit) {
            minprofit = profit[i];
            minmonth = i;
        }
    }

    cout << "Total profit: " << total << endl;
    cout << "Maximum profit: " << maxprofit << ", month: " << maxmonth + 1 << endl;
    cout << "Minimum profit: " << minprofit << ", month: " << minmonth + 1 << endl;
    cout << "Average profit: " << total / 12 << endl;


    // Task 2
    

    int arr1[10] = { 1, 5, 8, 3, 9, 2, 7, 4, 6, 10 };

    cout << "Array in reverse order: ";

    for (int i = 9; i >= 0; i--) {
        cout << arr1[i] << " ";
    }

    cout << endl;


    // Task 3
   

    double sides[5];
    double perimeter = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter side " << i + 1 << ": ";
        cin >> sides[i];

        perimeter += sides[i];
    }

    cout << "Perimeter: " << perimeter << endl;


    // Task 4
 

    int arr2[9] = { 0, -11, 0, 12, 54, 0, 0, -40, 11 };
    int index = 0;

    cout << "Array before: ";

    for (int i = 0; i < 9; i++) {
        cout << arr2[i] << " ";
    }

    for (int i = 0; i < 9; i++) {
        if (arr2[i] != 0) {
            arr2[index] = arr2[i];
            index++;
        }
    }

    while (index < 9) {
        arr2[index] = -1;
        index++;
    }

    cout << endl << "Array after: ";

    for (int i = 0; i < 9; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;


    // Task 5

    int first[5] = { 10, 0, 52, -10, -44 };
    int second[5] = { 54, 0, -100, 12, 4 };
    int result[10];
    index = 0;

    for (int i = 0; i < 5; i++) {
        if (first[i] > 0) {
            result[index] = first[i];
            index++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (second[i] > 0) {
            result[index] = second[i];
            index++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (first[i] == 0) {
            result[index] = first[i];
            index++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (second[i] == 0) {
            result[index] = second[i];
            index++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (first[i] < 0) {
            result[index] = first[i];
            index++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (second[i] < 0) {
            result[index] = second[i];
            index++;
        }
    }

    cout << "Result: ";

    for (int i = 0; i < 10; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}




