#include <iostream>



int max(int arr[], int size) 
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


int max(int arr[][3], int rows) 
{
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (arr[i][j] > maxVal) 
            {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}


int max(int arr[][3][3], int rows) 
{
    int maxVal = arr[0][0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 3; k++) 
            {
                if (arr[i][j][k] > maxVal) 
                {
                    maxVal = arr[i][j][k];
                }
            }
        }
    }
    return maxVal;
}


int max(int a, int b) 
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


int max(int a, int b, int c) 
{
    if (a > b && a > c)
    {
        return a;
    }
    if (b > c && b > a) 
    {
        return b;
    }
    else
    {
        return c;
    }
}


int main() 
{
   
    int arr1D[] = { 1, 2, 3, 4, 5 };
    std::cout << "Max value in one layer array: " << max(arr1D, 5) << std::endl;

    
    int arr2D[2][3] = { {1, 2, 3}, {4, 5, 6} };
    std::cout << "Max value in two layer array: " << max(arr2D, 2) << std::endl;

    
    int arr3D[2][3][3] = { {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}} };
    std::cout << "Max value in three layer array: " << max(arr3D, 2) << std::endl;

    
    std::cout << "Max value: " << max(10, 20) << std::endl;

    
    std::cout << "Max value: " << max(10, 20, 15) << std::endl;

    return 0;
}
