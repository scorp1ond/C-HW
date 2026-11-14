#include <iostream>
using namespace std;

// Read an integer; repeat if the input is invalid.
int readNumber(const char* message)
{
    int number;
    while (true)
    {
        cout << message;
        if (cin >> number)
            return number;
        if (cin.eof())
            throw 0;
        cin.clear();
        char ch;
        while (cin.get(ch) && ch != '\n') {}
        cout << "Enter an integer.\n";
    }
}

int readSize(const char* message, int maximum)
{
    int n;
    do
    {
        n = readNumber(message);
    } while (n < 1 || n > maximum);
    return n;
}

// Task 1. Two one-dimensional arrays of phone numbers.
void task1()
{
    long long mobile[100], home[100];
    int n = readSize("Number of users (1-100): ", 100);
    for (int i = 0; i < n; i++)
    {
        cout << "User " << i + 1 << " (mobile and home numbers): ";
        // Enter digits only. Leading zeros are not stored in integer arrays.
        while (!(cin >> mobile[i] >> home[i]) || mobile[i] < 0 || home[i] < 0)
        {
            if (cin.eof()) throw 0;
            cin.clear();
            char ch;
            while (cin.get(ch) && ch != '\n') {}
            cout << "Enter two non-negative phone numbers: ";
        }
    }

    int choice;
    do
    {
        choice = readNumber("\n1. Sort by mobile\n2. Sort by home\n3. List users\n4. Exit\nChoice: ");
        if (choice == 1 || choice == 2)
        {
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - 1 - i; j++)
                {
                    bool wrongOrder;
                    if (choice == 1)
                        wrongOrder = mobile[j] > mobile[j + 1];
                    else
                        wrongOrder = home[j] > home[j + 1];

                    if (wrongOrder)
                    {
                        // Move both numbers together: they belong to one user.
                        long long temp = mobile[j];
                        mobile[j] = mobile[j + 1];
                        mobile[j + 1] = temp;
                        temp = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = temp;
                    }
                }
            cout << "Sorted.\n";
        }
        else if (choice == 3)
        {
            cout << "No.\tMobile\tHome\n";
            for (int i = 0; i < n; i++)
                cout << i + 1 << '\t' << mobile[i] << '\t' << home[i] << '\n';
        }
    } while (choice != 4);
}

// Task 2. Improved bubble sort.
void task2()
{
    int a[100];
    int n = readSize("Array size (1-100): ", 100);
    for (int i = 0; i < n; i++)
        a[i] = readNumber("Element: ");

    for (int i = 0; i < n - 1; i++)
    {
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swaps++;
            }
        }
        cout << "Swaps: " << swaps << '\n';
        if (swaps == 0)
            break;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

// Task 3. Index 0 is the TOP of the stack.
void flip(int a[], int k)
{
    for (int i = 0; i < k / 2; i++)
    {
        int temp = a[i];
        a[i] = a[k - 1 - i];
        a[k - 1 - i] = temp;
    }
}

bool sorted(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) return false;
    return true;
}

// Try every sequence with at most 'left' flips.
// Trying limits 0, 1, 2, ... guarantees the minimum number of operations.
// Ranks 1..n are used here, rather than the original radii.
bool findFlips(int a[], int n, int left, int path[], int depth, int lastFlip)
{
    if (sorted(a, n)) return true;
    if (left == 0) return false;

    // A flip can fix at most one broken neighbouring pair.
    // This check skips branches which cannot finish within the remaining flips.
    int breaks = (a[n - 1] != n);
    for (int i = 0; i < n - 1; i++)
    {
        int difference = a[i] - a[i + 1];
        if (difference != 1 && difference != -1) breaks++;
    }
    if (breaks > left) return false;

    for (int k = 2; k <= n; k++)
    {
        if (k == lastFlip) continue; // Two identical flips cancel each other.
        flip(a, k);
        path[depth] = k;
        bool found = findFlips(a, n, left - 1, path, depth + 1, k);
        flip(a, k); // Restore the stack before trying the next operation.
        if (found) return true;
    }
    return false;
}

void task3()
{
    int radius[9], rank[9], path[18];
    int n = readSize("Number of pancakes (1-9): ", 9);
    cout << "Enter distinct positive integer radii from TOP to BOTTOM.\n";
    for (int i = 0; i < n; i++)
    {
        bool valid;
        do
        {
            radius[i] = readNumber("Radius: ");
            valid = radius[i] > 0;
            for (int j = 0; j < i; j++)
                if (radius[i] == radius[j]) valid = false;
            if (!valid) cout << "Use a positive radius different from the others.\n";
        } while (!valid);
    }
    for (int i = 0; i < n; i++)
    {
        rank[i] = 1;
        for (int j = 0; j < n; j++)
            if (radius[j] < radius[i]) rank[i]++;
    }

    int count = 0;
    while (!findFlips(rank, n, count, path, 0, 0)) count++;
    cout << "Minimum operations: " << count << '\n';
    for (int i = 0; i < count; i++)
    {
        cout << "Flip top " << path[i] << " pancakes.\n";
        flip(radius, path[i]);
    }
    cout << "Result from BOTTOM to TOP: ";
    for (int i = n - 1; i >= 0; i--)
        cout << radius[i] << ' ';
    cout << '\n';
}

int main()
{
    try
    {
        int choice;
        do
        {
            choice = readNumber("\n1. Phone book\n2. Bubble sort\n3. Pancakes\n0. Exit\nTask: ");
            if (choice == 1) task1();
            if (choice == 2) task2();
            if (choice == 3) task3();
        } while (choice != 0);
    }
    catch (int)
    {
        cout << "\nInput ended.\n";
    }
    return 0;
}

