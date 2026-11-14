#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

// Build: g++ -std=c++11 -Wall -Wextra -pedantic algorithms_hw.cpp -o algorithms_hw

int readInt(const char* prompt, int low, int high)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value && value >= low && value <= high)
            return value;
        if (std::cin.eof())
            throw std::runtime_error("Input ended.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Allowed range: " << low << ".." << high << '\n';
    }
}

std::string readPhone(const char* prompt)
{
    std::string phone;
    while (true)
    {
        std::cout << prompt;
        if (!(std::cin >> phone))
            throw std::runtime_error("Input ended.");
        if (phone.size() <= 15 &&
            phone.find_first_not_of("0123456789") == std::string::npos)
            return phone;
        std::cout << "Enter 1-15 digits without spaces or punctuation.\n";
    }
}

// Compare numeric values without losing leading zeros in the stored phones.
bool phoneGreater(const std::string& a, const std::string& b)
{
    const auto firstA = a.find_first_not_of('0');
    const auto firstB = b.find_first_not_of('0');
    const std::string x = firstA == std::string::npos ? "0" : a.substr(firstA);
    const std::string y = firstB == std::string::npos ? "0" : b.substr(firstB);
    return x.size() != y.size() ? x.size() > y.size() : x > y;
}

// Task 1: the two arrays always move together to preserve each person's pair.
void phoneBook()
{
    const int capacity = 100;
    std::string mobile[capacity], home[capacity];
    const int n = readInt("Number of users (1-100): ", 1, capacity);
    for (int i = 0; i < n; ++i)
    {
        std::cout << "User " << i + 1 << ":\n";
        mobile[i] = readPhone("Mobile: ");
        home[i] = readPhone("Home: ");
    }

    while (true)
    {
        const int choice = readInt(
            "\n1. Sort by mobile\n2. Sort by home\n3. List users\n4. Exit\nChoice: ", 1, 4);
        if (choice == 4)
            return;
        if (choice == 3)
        {
            std::cout << "No.\tMobile\tHome\n";
            for (int i = 0; i < n; ++i)
                std::cout << i + 1 << '\t' << mobile[i] << '\t' << home[i] << '\n';
            continue;
        }
        for (int end = n - 1; end > 0; --end)
        {
            int swaps = 0;
            for (int j = 0; j < end; ++j)
            {
                if (phoneGreater(choice == 1 ? mobile[j] : home[j],
                                 choice == 1 ? mobile[j + 1] : home[j + 1]))
                {
                    std::swap(mobile[j], mobile[j + 1]);
                    std::swap(home[j], home[j + 1]);
                    ++swaps;
                }
            }
            if (swaps == 0)
                break;
        }
        std::cout << "Sorted in ascending order.\n";
    }
}

// Task 2: stop as soon as a full pass makes no swaps.
void bubbleSort(int a[], int n)
{
    for (int end = n - 1; end > 0; --end)
    {
        int swaps = 0;
        for (int j = 0; j < end; ++j)
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                ++swaps;
            }
        std::cout << "Swaps on this pass: " << swaps << '\n';
        if (swaps == 0)
            break;
    }
}

void bubbleTask()
{
    int a[100];
    const int n = readInt("Array size (1-100): ", 1, 100);
    for (int i = 0; i < n; ++i)
        a[i] = readInt("Element: ", std::numeric_limits<int>::min(),
                       std::numeric_limits<int>::max());
    bubbleSort(a, n);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

struct Previous
{
    std::string state;
    int flip;
};

// Task 3: BFS visits states by distance, so the first solution is optimal.
// Index 0 is the TOP. Ascending top-to-bottom means decreasing bottom-to-top.
// At most 9! states; limiting n avoids unbounded factorial memory consumption.
std::vector<int> minimumFlips(const std::string& start)
{
    std::string target = start;
    std::sort(target.begin(), target.end());
    std::unordered_map<std::string, Previous> previous;
    std::queue<std::string> pending;
    previous.emplace(start, Previous{"", 0});
    pending.push(start);
    while (!pending.empty())
    {
        const std::string current = pending.front();
        pending.pop();
        if (current == target)
            break;
        for (int k = 2; k <= static_cast<int>(start.size()); ++k)
        {
            std::string next = current;
            std::reverse(next.begin(), next.begin() + k);
            if (previous.emplace(next, Previous{current, k}).second)
                pending.push(next);
        }
    }
    std::vector<int> flips;
    for (std::string state = target; state != start; state = previous.at(state).state)
        flips.push_back(previous.at(state).flip);
    std::reverse(flips.begin(), flips.end());
    return flips;
}

void pancakeTask()
{
    const int n = readInt("Number of pancakes (1-9, exact minimum search): ", 1, 9);
    int radius[9];
    std::cout << "Enter distinct positive integer radii from TOP to BOTTOM.\n";
    for (int i = 0; i < n; ++i)
    {
        bool duplicate;
        do
        {
            radius[i] = readInt("Radius: ", 1, std::numeric_limits<int>::max());
            duplicate = false;
            for (int j = 0; j < i; ++j)
                if (radius[j] == radius[i])
                    duplicate = true;
            if (duplicate)
                std::cout << "Radii must be distinct.\n";
        } while (duplicate);
    }
    // Encode radii by rank; the BFS state then takes only n bytes.
    std::string start;
    for (int i = 0; i < n; ++i)
    {
        int rank = 0;
        for (int j = 0; j < n; ++j)
            if (radius[j] < radius[i])
                ++rank;
        start += static_cast<char>('0' + rank);
    }
    const std::vector<int> flips = minimumFlips(start);
    std::cout << "Minimum operations: " << flips.size() << '\n';
    for (int k : flips)
    {
        std::reverse(radius, radius + k);
        std::cout << "Flip top " << k << ": ";
        for (int i = 0; i < n; ++i)
            std::cout << radius[i] << ' ';
        std::cout << "(top to bottom)\n";
    }
    std::cout << "Result, BOTTOM to TOP: ";
    for (int i = n - 1; i >= 0; --i)
        std::cout << radius[i] << ' ';
    std::cout << '\n';
}

int main()
{
    try
    {
        while (true)
        {
            const int task = readInt(
                "\n1. Phone book\n2. Improved bubble sort\n3. Pancakes\n0. Exit\nTask: ", 0, 3);
            if (task == 0) return 0;
            if (task == 1) phoneBook();
            if (task == 2) bubbleTask();
            if (task == 3) pancakeTask();
        }
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }
}

