#include <iostream>

int myStrcmp(const char* first, const char* second)
{
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0')
    {
        if (first[i] != second[i])
            return (unsigned char)first[i] - (unsigned char)second[i];
        i++;
    }

    return (unsigned char)first[i] - (unsigned char)second[i];
}

bool isPalindrome(char text[])
{
    int size = 0;
    while (text[size] != '\0')
        size++;

    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        while (left < right && text[left] == ' ')
            left++;
        while (left < right && text[right] == ' ')
            right--;

        char a = text[left];
        char b = text[right];

        if (a >= 'A' && a <= 'Z')
            a += 32;
        if (b >= 'A' && b <= 'Z')
            b += 32;

        if (a != b)
            return false;

        left++;
        right--;
    }

    return true;
}

int countWords(char text[])
{
    int count = 0;
    bool word = false;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == '\t')
        {
            word = false;
        }
        else if (!word)
        {
            count++;
            word = true;
        }
    }

    return count;
}

int main()
{
    char first[256];
    char second[256];
    char text[256];

    std::cout << "enter first string: ";
    std::cin.getline(first, 256);
    std::cout << "enter second string: ";
    std::cin.getline(second, 256);

    std::cout << "strcmp result: " << myStrcmp(first, second) << '\n';

    std::cout << "enter text: ";
    std::cin.getline(text, 256);

    if (isPalindrome(text))
        std::cout << "palindrome\n";
    else
        std::cout << "not palindrome\n";

    std::cout << "enter text: ";
    std::cin.getline(text, 256);

    std::cout << "words: " << countWords(text) << '\n';
}
