#include <iostream>
#include <algorithm>  
#include <cstdlib>    
#include <random>     


void fillArray(int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = i + 1;
    }
}


void shuffleArray(int arr[], int size) 
{
    for (int i = size - 1; i > 0; --i) 
    {
        int j = std::rand() % (i + 1);  
        std::swap(arr[i], arr[j]);
    }
}


int findRandomNumberPosition(int arr[], int size, int& randomNumber) 
{
    randomNumber = std::rand() % size + 1; 
    int pos = -1;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == randomNumber) 
        {
            pos = i;
            break;
        }
    }
    return pos;
}


void sortAroundPosition(int arr[], int size, int pos) 
{
    if (pos > 0) 
    {
        std::sort(arr, arr + pos, [](int a, int b) { return a > b; });
    }
    if (pos < size - 1) 
    {
        std::sort(arr + pos + 1, arr + size);
    }
}

int main() 
{
    const int SIZE = 20;
    int arr[SIZE];

    
    std::srand(std::random_device{}());

    
    fillArray(arr, SIZE);
    shuffleArray(arr, SIZE);

    
    int randomNumber;
    int position = findRandomNumberPosition(arr, SIZE, randomNumber);

    
    if (position != -1) 
    {
        sortAroundPosition(arr, SIZE, position);
    }

    
    std::cout << "Array: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nRandom number: " << randomNumber;
    std::cout << "\nPosition: " << position << std::endl;

    return 0;
}
