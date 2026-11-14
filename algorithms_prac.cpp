#include <iostream>

void quickSort(int[], int, int);

int main()
{
    const int capacity = 100;
    int first[capacity], second[capacity], n;

    std::cout << "Enter array size (1-100): ";
    if (!(std::cin >> n)) return 0;

    while (n < 1 || n > capacity)
    {
        std::cout << "Enter size from 1 to 100: ";
        if (!(std::cin >> n)) return 0;
    }

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        if (!(std::cin >> first[i])) return 0;
        second[i] = first[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (first[j] < first[minIndex])
                minIndex = j;

        int temp = first[i];
        first[i] = first[minIndex];
        first[minIndex] = temp;
    }

    std::cout << "Selection sort: ";
    for (int i = 0; i < n; i++)
        std::cout << first[i] << ' ';
    std::cout << '\n';

    for (int i = 1; i < n; i++)
    {
        int number = second[i];
        int j = i - 1;
        while (j >= 0 && second[j] > number)
        {
            second[j + 1] = second[j];
            j--;
        }
        second[j + 1] = number;
    }

    std::cout << "Insertion sort: ";
    for (int i = 0; i < n; i++)
        std::cout << second[i] << ' ';
    std::cout << '\n';


    int grades[10], choice;
    std::cout << "\nEnter 10 grades (1-12): ";
    for (int i = 0; i < 10; i++)
    {
        if (!(std::cin >> grades[i])) return 0;
        while (grades[i] < 1 || grades[i] > 12)
        {
            std::cout << "Enter grade from 1 to 12: ";
            if (!(std::cin >> grades[i])) return 0;
        }
    }

    do
    {
        std::cout << "\n1 - Show grades\n2 - Retake exam\n3 - Check scholarship\n0 - Continue\nChoose: ";
        if (!(std::cin >> choice)) return 0;

        if (choice == 1)
        {
            for (int i = 0; i < 10; i++)
                std::cout << i + 1 << ": " << grades[i] << '\n';
        }
        else if (choice == 2)
        {
            int index, grade;
            std::cout << "Enter exam number (1-10): ";
            if (!(std::cin >> index)) return 0;
            while (index < 1 || index > 10)
            {
                std::cout << "Enter number from 1 to 10: ";
                if (!(std::cin >> index)) return 0;
            }

            std::cout << "Enter new grade (1-12): ";
            if (!(std::cin >> grade)) return 0;
            while (grade < 1 || grade > 12)
            {
                std::cout << "Enter grade from 1 to 12: ";
                if (!(std::cin >> grade)) return 0;
            }
            grades[index - 1] = grade;
        }
        else if (choice == 3)
        {
            int sum = 0;
            for (int i = 0; i < 10; i++)
                sum += grades[i];

            double average = sum / 10.0;
            std::cout << "Average: " << average << '\n';
            if (average >= 10.7)
                std::cout << "Scholarship: yes\n";
            else
                std::cout << "Scholarship: no\n";
        }
        else if (choice != 0)
        {
            std::cout << "Choose from 0 to 3\n";
        }
    } while (choice != 0);


    int arr[capacity];
    std::cout << "\nEnter array size (1-100): ";
    if (!(std::cin >> n)) return 0;
    while (n < 1 || n > capacity)
    {
        std::cout << "Enter size from 1 to 100: ";
        if (!(std::cin >> n)) return 0;
    }

    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
        if (!(std::cin >> arr[i])) return 0;

    quickSort(arr, 0, n - 1);
    std::cout << "Quick sort: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';


    std::cout << "\nEnter array size (1-100): ";
    if (!(std::cin >> n)) return 0;
    while (n < 1 || n > capacity)
    {
        std::cout << "Enter size from 1 to 100: ";
        if (!(std::cin >> n)) return 0;
    }

    long long sum = 0;
    std::cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        if (!(std::cin >> arr[i])) return 0;
        sum += arr[i];
    }

    int count;
    if (sum > 0)
        count = n * 2 / 3;
    else
        count = n / 3;

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    int left = count, right = n - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    std::cout << "Result: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
    return 0;
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[left + (right - left) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

