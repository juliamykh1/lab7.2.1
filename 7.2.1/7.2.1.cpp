// Lab_7_2_1.cpp
// < Михайлович Юлія >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 17
#include <iostream>
#include <ctime>

int** CreateMatrix(int k, int n);
void ChangeMatrix(int** Matrix, int k, int n);
void PrintMatrix(int** Matrix, int k, int n);

int main()
{
    srand(time(NULL));

    int k, n;
    std::cout << "Enter k: "; //рядки
    std::cin >> k;
    std::cout << "Enter n: "; //стовпці
    std::cin >> n;

    int** Matrix = CreateMatrix(k, n);
    std::cout << "First matrix:\n";
    PrintMatrix(Matrix, k, n);
    ChangeMatrix(Matrix, k, n);
    std::cout << "Changed matrix:\n";
    PrintMatrix(Matrix, k, n);

}

int** CreateMatrix(int k, int n)
{
    int** Matrix = new int* [k];
    for (int i = 0; i < k; i++)
    {
        Matrix[i] = new int[n];
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] = rand() % 10;
        }
    }
    return Matrix;
}

void ChangeMatrix(int** Matrix, int k, int n)
{
    int MinElement, MaxElement;
    for (int i = 1; i < k; i += 2)
    {
        MinElement = Matrix[i - 1][0];
        int MinJ = 0;
        for (int j = 0; j < n; j++)
        {
            if (MinElement > Matrix[i - 1][j])
            {
                MinElement = Matrix[i - 1][j];
                MinJ = j;
            }
        }

        MaxElement = Matrix[i][0];
        int MaxJ = 0;
        for (int j = 0; j < n; j++)
        {
            if (MaxElement < Matrix[i][j])
            {
                MaxElement = Matrix[i][j];
                MaxJ = j;
            }
        }

        std::swap(Matrix[i - 1][MinJ], Matrix[i][MaxJ]);
    }
}

void PrintMatrix(int** Matrix, int k, int n)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}