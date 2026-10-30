#include <iostream>

double powerNumber(double, int);
long long rangeSum(int, int);
void perfectNumbers(int, int);
void playingCard(int, char);
bool luckyNumber(int);
int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
long long binaryToDecimal(long long);
double arrayAverage(int[], int);

int main()
{
    // Task 1
    double base;
    int exponent;
    std::cout << "enter base and exponent: ";
    std::cin >> base >> exponent;

    if (base == 0 && exponent <= 0)
    {
        std::cout << "undefined power\n";
    }
    else
    {
        std::cout << "result: " << powerNumber(base, exponent) << '\n';
    }

    // Task 2
    int a, b;
    std::cout << "enter two boundaries (included in the sum): ";
    std::cin >> a >> b;
    std::cout << "sum: " << rangeSum(a, b) << '\n';

    // Task 3
    std::cout << "enter two boundaries: ";
    std::cin >> a >> b;
    std::cout << "perfect numbers: ";
    perfectNumbers(a, b);

    // Task 4
    int rank;
    char suit;
    std::cout << "enter rank (1 - ace, 2-10, 11 - jack, 12 - queen, 13 - king): ";
    std::cin >> rank;
    std::cout << "enter suit (H - hearts, D - diamonds, C - clubs, S - spades): ";
    std::cin >> suit;
    playingCard(rank, suit);

    // Task 5
    int number;
    std::cout << "enter a six-digit number: ";
    std::cin >> number;

    if (number < 100000 || number > 999999)
    {
        std::cout << "invalid number\n";
    }
    else if (luckyNumber(number))
    {
        std::cout << "the number is lucky\n";
    }
    else
    {
        std::cout << "the number is not lucky\n";
    }

    // Task 6
    int arr[5], key;
    std::cout << "enter 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "enter key: ";
    std::cin >> key;
    std::cout << "index (-1 if not found): " << linearSearch(arr, 5, key) << '\n';

    // Task 7
    int sorted[5];
    std::cout << "enter 5 numbers in ascending order: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> sorted[i];
    }

    bool ordered = true;
    for (int i = 1; i < 5; i++)
    {
        if (sorted[i] < sorted[i - 1])
        {
            ordered = false;
        }
    }

    if (ordered)
    {
        std::cout << "enter key: ";
        std::cin >> key;
        std::cout << "index (-1 if not found): " << binarySearch(sorted, 5, key) << '\n';
    }
    else
    {
        std::cout << "array must be sorted\n";
    }

    // Task 8
    long long binary;
    std::cout << "enter a binary number (up to 18 digits): ";
    std::cin >> binary;
    long long decimal = binaryToDecimal(binary);

    if (decimal == -1)
    {
        std::cout << "invalid binary number\n";
    }
    else
    {
        std::cout << "decimal: " << decimal << '\n';
    }

    // Task 9
    std::cout << "average of the array from task 6: " << arrayAverage(arr, 5) << '\n';
}

double powerNumber(double base, int exponent) {
    double result = 1;
    long long count = exponent;

    if (count < 0)
    {
        base = 1 / base;
        count = -count;
    }

    while (count > 0)
    {
        if (count % 2 != 0)
        {
            result *= base;
        }
        count /= 2;
        if (count > 0)
        {
            base *= base;
        }
    }

    return result;
}

long long rangeSum(int a, int b) {
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    long long sum = 0;
    for (long long i = a; i <= b; i++)
    {
        sum += i;
    }
    return sum;
}

void perfectNumbers(int a, int b) {
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a < 2)
    {
        a = 2;
    }

    bool found = false;
    for (long long number = a; number <= b; number++)
    {
        long long sum = 1;
        for (long long i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
            {
                sum += i;
                if (i != number / i)
                {
                    sum += number / i;
                }
            }
        }

        if (sum == number)
        {
            std::cout << number << ' ';
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "none";
    }
    std::cout << '\n';
}

void playingCard(int rank, char suit) {
    if (rank < 1 || rank > 13 ||
        (suit != 'H' && suit != 'D' && suit != 'C' && suit != 'S'))
    {
        std::cout << "invalid card\n";
        return;
    }

    std::cout << "+-------+\n";
    std::cout << "|";
    switch (rank)
    {
        case 1:
            std::cout << "A";
            break;
        case 11:
            std::cout << "J";
            break;
        case 12:
            std::cout << "Q";
            break;
        case 13:
            std::cout << "K";
            break;
        default:
            std::cout << rank;
    }

    if (rank == 10)
    {
        std::cout << "     |\n";
    }
    else
    {
        std::cout << "      |\n";
    }

    std::cout << "|       |\n";
    std::cout << "|   " << suit << "   |\n";
    std::cout << "|       |\n";
    std::cout << "+-------+\n";
}

bool luckyNumber(int number) {
    if (number < 100000 || number > 999999)
    {
        return false;
    }

    int first = number / 1000;
    int last = number % 1000;
    int first_sum = 0, last_sum = 0;

    for (int i = 0; i < 3; i++)
    {
        first_sum += first % 10;
        last_sum += last % 10;
        first /= 10;
        last /= 10;
    }

    return first_sum == last_sum;
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == key)
        {
            return middle;
        }
        if (arr[middle] < key)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}

long long binaryToDecimal(long long binary) {
    if (binary < 0)
    {
        return -1;
    }

    long long decimal = 0, place = 1;
    while (binary > 0)
    {
        int digit = binary % 10;
        if (digit != 0 && digit != 1)
        {
            return -1;
        }

        decimal += digit * place;
        place *= 2;
        binary /= 10;
    }
    return decimal;
}

double arrayAverage(int arr[], int size) {
    if (size <= 0)
    {
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}
