

#include <iostream>

using namespace std;

int main()
{
    // t1
    int num;
    cout << "enter a number: ";
    cin >> num;
    if (num % 2 == 0) {
        cout << "your number is even. \n";

    }
    else {
        cout << "your number is odd. \n";
    }

    // t2 
    int n1, n2;

    cout << "enter the first number: ";
    cin >> n1;

    cout << "enter the second number: ";
    cin >> n2;

    if (n1 < n2) {
        cout << "first number is smaller. \n";
    }
    else if (n1 > n2) {
        cout << "second number is smaller. \n";
    }
    else {
        cout << "numbers are equal. \n";
    }

    // t3
    int number;
    cout << "enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << "your number is negative \n";
    }
    else if (number > 0) {
        cout << "your number is positive \n";
    }
    else {
        cout << "your number is 0 \n";
    }

    //4
    float num1, num2;

    cout << "enter the first number: ";
    cin >> num1;

    cout << "enter the second number: ";
    cin >> num2;

    if (num1 == num2) {
        cout << "your numbers are equal \n";
    }
    else if (num1 < num2) {
        cout << num1 << " " << num2 << '\n';

    }
    else {
        cout << num2 << " " << num1 << '\n';
    }
    // t5 
    int g1, g2, g3, g4, g5;
    float gTot;

    cout << "enter the first grade: ";
    cin >> g1;

    cout << "enter the second grade: ";
    cin >> g2;

    cout << "enter the third grade: ";
    cin >> g3;

    cout << "enter the forth grade: ";
    cin >> g4;

    cout << "enter the 5th grade: ";
    cin >> g5;

    gTot = (g1 + g2 + g3 + g4 + g5) / 5;

    if (gTot >= 4) {
        cout << "student passed\n";
    }
    else {
        cout << "student failed\n";
    }

    // t6
    int number1;
    cout << "enter a number: ";
    cin >> number1;

    if (number1 % 2 == 0) {
        cout << number1 * 3 << '\n';

    }
    else {
        cout << number1 / 2 << '\n';

    }

    // t7 
    float op1, op2;
    char action;

    cout << "enter the first number: ";
    cin >> op1;
    cout << "enter the second number: ";
    cin >> op2;
    cout << "enter the action (+,-,*,/): ";
    cin >> action;

    switch (action) {
    case '+': cout << op1 + op2 << '\n';break;
    case '-': cout << op1 - op2 << '\n';break;
    case '*': cout << op1 * op2 << '\n';break;
    case '/': if (op2 != 0) { cout << op1 / op2 << '\n';break; }
            else {
        cout << "cant divide by zero\n";
    }
    default: cout << "wrong action\n";
    }

    // t8
    int n67, power;

    cout << "enter the number: ";
    cin >> n67;
    cout << "enter the power(0-7): ";
    cin >> power;

    switch (power) {
    case 0: cout << 1;break;
    case 1: cout << n67 << '\n';break;
    case 2: cout << n67 * n67 << '\n';break;
    case 3: cout << n67 * n67 * n67 << '\n';break;
    case 4: cout << n67 * n67 * n67 * n67 << '\n';break;
    case 5: cout << n67 * n67 * n67 * n67 * n67 << '\n';break;
    case 6: cout << n67 * n67 * n67 * n67 * n67 * n67 << '\n';break;
    case 7: cout << n67 * n67 * n67 * n67 * n67 * n67 * n67 << '\n';break;
    default: cout << "wrong power \n";

    // bonus

    }

    
    







    






}


