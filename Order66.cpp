#include <iostream>


//1
void calculateSumAndProduct(int arr[], int size, int& sum, int& product) 
{
    sum = 0;
    product = 1;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
        product *= arr[i];
    }
}

//2
void countElements(int arr[], int size, int& negatives, int& positives, int& zeros) 
{
    negatives = 0;
    positives = 0;
    zeros = 0;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] < 0) negatives++;
        else if (arr[i] > 0) positives++;
        else zeros++;
    }
}

//3
bool isSubset(int A[], int sizeA, int B[], int sizeB) 
{
    for (int i = 0; i <= sizeA - sizeB; i++) 
    {
        bool found = true;
        for (int j = 0; j < sizeB; j++) 
        {
            if (A[i + j] != B[j]) 
            {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}

int main() 
{
    
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum, product;

    
    calculateSumAndProduct(arr, size, sum, product);
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Product: " << product << "\n";

    
    int negatives, positives, zeros;
    int arr2[] = { -1, 0, 3, -5, 0, 2 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    countElements(arr2, size2, negatives, positives, zeros);
    std::cout << "Negatives: " << negatives << "\n";
    std::cout << "Positives: " << positives << "\n";
    std::cout << "Zeros: " << zeros << "\n";

    
    int A[] = { 1, 2, 3, 4, 5 };
    int B[] = { 3, 4 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    if (isSubset(A, sizeA, B, sizeB))
        std::cout << "B is a subset of A.\n";
    else
        std::cout << "B is not a subset of A.\n";

    return 0;
}