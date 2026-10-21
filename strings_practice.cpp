#include <iostream>

void myStrset(char* str, char newSymbol) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = newSymbol;
        ++i;
    }
}

bool isLetter(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') ||
        (symbol >= 'A' && symbol <= 'Z');
}

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

int main()
{
    char example[] = "Hello";
    myStrset(example, '*');
    std::cout << "strset result: " << example << '\n';

    char text[256];
    std::cout << "Enter a string: ";
    std::cin.getline(text, 256);

    int lettersCount = 0;
    int digitsCount = 0;
    int otherSymbolsCount = 0;

    int i = 0;
    while (text[i] != '\0') {
        if (isLetter(text[i])) {
            ++lettersCount;
        }
        else if (isDigit(text[i])) {
            ++digitsCount;
        }
        else {
            ++otherSymbolsCount;
        }
        ++i;
    }

    std::cout << "Letters: " << lettersCount << '\n';
    std::cout << "Digits: " << digitsCount << '\n';
    std::cout << "Other symbols: " << otherSymbolsCount << '\n';
}
