#include <iostream>

// 2
void sumArrays(int* A, int* B, int* C, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        C[i] = A[i] + B[i];
    }
}

int main() 
{
    const int size = 5; 
    int A[size] = { 1, 2, 3, 4, 5 }; 
    int B[size] = { 10, 20, 30, 40, 50 }; 
    int C[size]; 

    
    sumArrays(A, B, C, size);

    
    std::cout << "Массив C (сумма массивов A и B): ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}