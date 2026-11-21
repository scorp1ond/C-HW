#include <iostream>

int* createArray(int size)
{
    return new int[size];
}

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

void deleteArray(int*& arr)
{
    delete[] arr;
    arr = nullptr;
}

void addElement(int*& arr, int& size, int value)
{
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = arr[i];
    temp[size] = value;
    delete[] arr;
    arr = temp;
    size++;
}

void insertElement(int*& arr, int& size, int index, int value)
{
    if (index < 0 || index > size)
        return;

    int* temp = new int[size + 1];
    for (int i = 0; i < index; i++)
        temp[i] = arr[i];
    temp[index] = value;
    for (int i = index; i < size; i++)
        temp[i + 1] = arr[i];
    delete[] arr;
    arr = temp;
    size++;
}

void removeElement(int*& arr, int& size, int index)
{
    if (index < 0 || index >= size)
        return;

    int* temp = new int[size - 1];
    for (int i = 0; i < index; i++)
        temp[i] = arr[i];
    for (int i = index + 1; i < size; i++)
        temp[i - 1] = arr[i];
    delete[] arr;
    arr = temp;
    size--;
}

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i <= num / i; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!isPrime(arr[i]))
            count++;
    }

    int* temp = new int[count];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!isPrime(arr[i]))
        {
            temp[j] = arr[i];
            j++;
        }
    }
    size = count;
    return temp;
}

void splitArray(int* arr, int size, int*& positive, int& p, int*& negative, int& n, int*& zeros, int& z)
{
    p = 0;
    n = 0;
    z = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            p++;
        else if (arr[i] < 0)
            n++;
        else
            z++;
    }

    positive = new int[p];
    negative = new int[n];
    zeros = new int[z];
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            positive[a++] = arr[i];
        else if (arr[i] < 0)
            negative[b++] = arr[i];
        else
            zeros[c++] = arr[i];
    }
}

int main()
{
    int size;
    std::cout << "enter array size: ";
    std::cin >> size;
    if (size < 0)
        return 0;

    int* arr = createArray(size);
    std::cout << "enter numbers: ";
    fillArray(arr, size);
    std::cout << "array: ";
    printArray(arr, size);

    int value, index;
    std::cout << "enter value to add: ";
    std::cin >> value;
    addElement(arr, size, value);
    printArray(arr, size);

    std::cout << "enter index and value to insert: ";
    std::cin >> index >> value;
    insertElement(arr, size, index, value);
    printArray(arr, size);

    std::cout << "enter index to remove: ";
    std::cin >> index;
    removeElement(arr, size, index);
    printArray(arr, size);
    deleteArray(arr);

    std::cout << "enter array size: ";
    std::cin >> size;
    if (size < 0)
        return 0;
    arr = createArray(size);
    std::cout << "enter numbers: ";
    fillArray(arr, size);
    int* result = removePrimes(arr, size);
    std::cout << "without prime numbers: ";
    printArray(result, size);
    deleteArray(arr);
    deleteArray(result);

    const int count = 8;
    int numbers[count] = {3, -2, 0, 5, -7, 0, 9, -1};
    int* positive = nullptr;
    int* negative = nullptr;
    int* zeros = nullptr;
    int p, n, z;
    splitArray(numbers, count, positive, p, negative, n, zeros, z);
    std::cout << "positive: ";
    printArray(positive, p);
    std::cout << "negative: ";
    printArray(negative, n);
    std::cout << "zeros: ";
    printArray(zeros, z);
    deleteArray(positive);
    deleteArray(negative);
    deleteArray(zeros);
}
