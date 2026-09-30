#include <iostream>

int main() {

    // task 1

    int arr2d[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int sum = 0;
    int min = arr2d[0][0];
    int max = arr2d[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr2d[i][j];

            if (arr2d[i][j] < min) {
                min = arr2d[i][j];
            }

            if (arr2d[i][j] > max) {
                max = arr2d[i][j];
            }
        }
    }

    double average = (double)sum / 9;

    std::cout << "sum: " << sum << '\n';
    std::cout << "average: " << average << '\n';
    std::cout << "minimum: " << min << '\n';
    std::cout << "maximum: " << max << '\n';


    // task 2

    for (int i = 0; i < 3; i++) {
        int row_sum = 0;

        for (int j = 0; j < 3; j++) {
            row_sum += arr2d[i][j];
        }

        std::cout << "row " << i + 1 << ": " << row_sum << '\n';
    }

    for (int j = 0; j < 3; j++) {
        int column_sum = 0;

        for (int i = 0; i < 3; i++) {
            column_sum += arr2d[i][j];
        }

        std::cout << "column " << j + 1 << ": " << column_sum << '\n';
    }

    int total = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            total += arr2d[i][j];
        }
    }

    std::cout << "total: " << total << '\n';


    // task 3

    int arr1[5][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}
    };

    int arr2[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr2[i][j] = arr1[i][j * 2] + arr1[i][j * 2 + 1];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << arr1[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << '\n';
    }

}