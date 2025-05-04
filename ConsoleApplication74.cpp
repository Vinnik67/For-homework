#include <iostream>



void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** addRow(int** matrix, int& rows, int cols, int* newRow, int position) 
{
    int** newMatrix = new int* [rows + 1];
    for (int i = 0, k = 0; i <= rows; ++i) 
    {
        if (i == position) 
        {
            newMatrix[i] = newRow;
        }
        else {
            newMatrix[i] = matrix[k++];
        }
    }
    ++rows;
    delete[] matrix;
    return newMatrix;
}

int** removeRow(int** matrix, int& rows, int cols, int position) 
{
    int** newMatrix = new int* [rows - 1];
    for (int i = 0, k = 0; i < rows; ++i) 
    {
        if (i != position) 
        {
            newMatrix[k++] = matrix[i];
        }
        else 
        {
            delete[] matrix[i];
        }
    }
    --rows;
    delete[] matrix;
    return newMatrix;
}

int main() 
{
    int rows = 3, cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[cols] {i + 1, i + 2, i + 3};
    }

    std::cout << "Defalt:\n";
    printMatrix(matrix, rows, cols);

    int* newRow = new int[cols] {10, 20, 30};
    matrix = addRow(matrix, rows, cols, newRow, 1);

    std::cout << "After adding:\n";
    printMatrix(matrix, rows, cols);

    matrix = removeRow(matrix, rows, cols, 0);

    std::cout << "After deliting:\n";
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}