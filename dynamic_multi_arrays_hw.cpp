#include <iostream>

int** createMatrix(int rows, int cols)
{
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    return arr;
}

void deleteMatrix(int** arr, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
}

void fillMatrix(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            std::cin >> arr[i][j];
}

void printMatrix(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            std::cout << arr[i][j] << " ";
        std::cout << '\n';
    }
}

void addColumn(int**& arr, int rows, int& cols, int index, int value)
{
    if (index < 0 || index > cols)
        return;

    int** temp = createMatrix(rows, cols + 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < index; j++)
            temp[i][j] = arr[i][j];
        temp[i][index] = value;
        for (int j = index; j < cols; j++)
            temp[i][j + 1] = arr[i][j];
    }

    deleteMatrix(arr, rows);
    arr = temp;
    cols++;
}

void removeColumn(int**& arr, int rows, int& cols, int index)
{
    if (index < 0 || index >= cols)
        return;

    int** temp = createMatrix(rows, cols - 1);
    for (int i = 0; i < rows; i++)
    {
        int k = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j != index)
                temp[i][k++] = arr[i][j];
        }
    }

    deleteMatrix(arr, rows);
    arr = temp;
    cols--;
}

void shiftMatrix(int** arr, int rows, int cols, int steps, int direction)
{
    if (rows == 0 || cols == 0 || steps < 0)
        return;

    if (direction == 1 || direction == 2)
        steps %= rows;
    else if (direction == 3 || direction == 4)
        steps %= cols;
    else
        return;

    for (int s = 0; s < steps; s++)
    {
        if (direction == 1)
        {
            int* temp = arr[0];
            for (int i = 0; i < rows - 1; i++)
                arr[i] = arr[i + 1];
            arr[rows - 1] = temp;
        }
        else if (direction == 2)
        {
            int* temp = arr[rows - 1];
            for (int i = rows - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = temp;
        }
        else if (direction == 3)
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][0];
                for (int j = 0; j < cols - 1; j++)
                    arr[i][j] = arr[i][j + 1];
                arr[i][cols - 1] = temp;
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][cols - 1];
                for (int j = cols - 1; j > 0; j--)
                    arr[i][j] = arr[i][j - 1];
                arr[i][0] = temp;
            }
        }
    }
}

void transpose(int**& arr, int& rows, int& cols)
{
    int** temp = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp[j][i] = arr[i][j];

    deleteMatrix(arr, rows);
    arr = temp;
    int old = rows;
    rows = cols;
    cols = old;
}

bool sameText(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return a[i] == b[i];
}

int compareText(const char* a, const char* b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

void phoneBook()
{
    int count;
    std::cout << "enter number of contacts: ";
    std::cin >> count;
    if (count < 0)
        return;

    char*** book = new char**[2];
    for (int row = 0; row < 2; row++)
    {
        book[row] = new char*[count];
        for (int i = 0; i < count; i++)
            book[row][i] = new char[100];
    }

    for (int i = 0; i < count; i++)
    {
        std::cout << "enter name and phone: ";
        std::cin >> std::ws;
        std::cin.width(100);
        std::cin >> book[0][i];
        std::cin.width(100);
        std::cin >> book[1][i];
    }

    int choice = -1;
    while (choice != 0)
    {
        std::cout << "1 search name, 2 search phone, 3 change contact, 4 show, 0 exit: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2)
        {
            char text[100];
            std::cout << "enter search: ";
            std::cin.width(100);
            std::cin >> text;

            bool found = false;
            int row = choice - 1;
            for (int i = 0; i < count; i++)
            {
                if (sameText(book[row][i], text))
                {
                    std::cout << book[0][i] << " " << book[1][i] << '\n';
                    found = true;
                }
            }
            if (!found)
                std::cout << "not found\n";
        }
        else if (choice == 3)
        {
            int index;
            std::cout << "enter contact number (1-" << count << "): ";
            std::cin >> index;
            if (index >= 1 && index <= count)
            {
                std::cout << "enter new name and phone: ";
                std::cin.width(100);
                std::cin >> book[0][index - 1];
                std::cin.width(100);
                std::cin >> book[1][index - 1];
            }
        }
        else if (choice == 4)
        {
            for (int i = 0; i < count; i++)
                std::cout << i + 1 << " " << book[0][i] << " " << book[1][i] << '\n';
        }
    }

    for (int row = 0; row < 2; row++)
    {
        for (int i = 0; i < count; i++)
            delete[] book[row][i];
        delete[] book[row];
    }
    delete[] book;
}

void sortStudents()
{
    char students[5][100];
    std::cout << "enter 5 surnames: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin.width(100);
        std::cin >> students[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (compareText(students[j], students[j + 1]) > 0)
            {
                char temp[100];
                int k = 0;
                while (students[j][k] != '\0')
                {
                    temp[k] = students[j][k];
                    k++;
                }
                temp[k] = '\0';

                k = 0;
                while (students[j + 1][k] != '\0')
                {
                    students[j][k] = students[j + 1][k];
                    k++;
                }
                students[j][k] = '\0';

                k = 0;
                while (temp[k] != '\0')
                {
                    students[j + 1][k] = temp[k];
                    k++;
                }
                students[j + 1][k] = '\0';
            }
        }
    }

    std::cout << "sorted: ";
    for (int i = 0; i < 5; i++)
        std::cout << students[i] << " ";
    std::cout << '\n';
}

bool contains(int* arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return true;
    }
    return false;
}

bool inMatrix(int** arr, int rows, int cols, int value)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] == value)
                return true;
    return false;
}

int timesInMatrix(int** arr, int rows, int cols, int value)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] == value)
                count++;
    return count;
}

void compareMatrices()
{
    int ar, ac, br, bc, cr, cc;
    std::cout << "enter A rows and columns: ";
    std::cin >> ar >> ac;
    std::cout << "enter B rows and columns: ";
    std::cin >> br >> bc;
    std::cout << "enter C rows and columns: ";
    std::cin >> cr >> cc;

    if (ar < 0 || ac < 0 || br < 0 || bc < 0 || cr < 0 || cc < 0)
        return;

    int** a = createMatrix(ar, ac);
    int** b = createMatrix(br, bc);
    int** c = createMatrix(cr, cc);

    std::cout << "enter A: ";
    fillMatrix(a, ar, ac);
    std::cout << "enter B: ";
    fillMatrix(b, br, bc);
    std::cout << "enter C: ";
    fillMatrix(c, cr, cc);

    int total = ar * ac + br * bc + cr * cc;
    int* all = new int[total];
    int k = 0;

    for (int i = 0; i < ar; i++)
        for (int j = 0; j < ac; j++)
            all[k++] = a[i][j];
    for (int i = 0; i < br; i++)
        for (int j = 0; j < bc; j++)
            all[k++] = b[i][j];
    for (int i = 0; i < cr; i++)
        for (int j = 0; j < cc; j++)
            all[k++] = c[i][j];

    int* common = new int[total];
    int* unique = new int[total];
    int* commonAC = new int[total];
    int* negatives = new int[total];
    int x = 0, y = 0, z = 0, w = 0;

    for (int i = 0; i < total; i++)
    {
        int value = all[i];
        if (contains(all, i, value))
            continue;

        bool inA = inMatrix(a, ar, ac, value);
        bool inB = inMatrix(b, br, bc, value);
        bool inC = inMatrix(c, cr, cc, value);

        if (inA && inB && inC)
            common[x++] = value;
        if (inA && inC)
            commonAC[z++] = value;
        if (value < 0)
            negatives[w++] = value;

        int times = timesInMatrix(a, ar, ac, value)
            + timesInMatrix(b, br, bc, value)
            + timesInMatrix(c, cr, cc, value);
        if (times == 1)
            unique[y++] = value;
    }

    std::cout << "common A B C: ";
    for (int i = 0; i < x; i++)
        std::cout << common[i] << " ";
    std::cout << '\n';

    std::cout << "unique A B C: ";
    for (int i = 0; i < y; i++)
        std::cout << unique[i] << " ";
    std::cout << '\n';

    std::cout << "common A C: ";
    for (int i = 0; i < z; i++)
        std::cout << commonAC[i] << " ";
    std::cout << '\n';

    std::cout << "negative without repeats: ";
    for (int i = 0; i < w; i++)
        std::cout << negatives[i] << " ";
    std::cout << '\n';

    delete[] all;
    delete[] common;
    delete[] unique;
    delete[] commonAC;
    delete[] negatives;
    deleteMatrix(a, ar);
    deleteMatrix(b, br);
    deleteMatrix(c, cr);
}

int main()
{
    int rows, cols;
    std::cout << "enter rows and columns: ";
    std::cin >> rows >> cols;
    if (rows < 0 || cols < 0)
        return 0;

    int** arr = createMatrix(rows, cols);
    std::cout << "enter matrix: ";
    fillMatrix(arr, rows, cols);

    int index, value;
    std::cout << "enter column index to add (starting from 0) and value: ";
    std::cin >> index >> value;
    addColumn(arr, rows, cols, index, value);
    printMatrix(arr, rows, cols);

    std::cout << "enter column index to remove (starting from 0): ";
    std::cin >> index;
    removeColumn(arr, rows, cols, index);
    printMatrix(arr, rows, cols);

    int direction, steps;
    std::cout << "direction (1 up, 2 down, 3 left, 4 right) and steps: ";
    std::cin >> direction >> steps;
    shiftMatrix(arr, rows, cols, steps, direction);
    printMatrix(arr, rows, cols);

    transpose(arr, rows, cols);
    std::cout << "transposed matrix:\n";
    printMatrix(arr, rows, cols);

    deleteMatrix(arr, rows);

    phoneBook();
    sortStudents();
    compareMatrices();
}
