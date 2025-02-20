#include <iostream>


//1.1
void findMin(const int arr[], int n, int& minValue, int& minIndex) 
{
    minValue = arr[0];
    minIndex = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (arr[i] < minValue) 
        {
            minValue = arr[i];
            minIndex = i;
        }
    }
}

//1.2
void findMax(const int arr[], int n, int& maxValue, int& maxIndex) 
{
    maxValue = arr[0];
    maxIndex = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (arr[i] > maxValue) 
        {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
}

//2
void reverseArray(int arr[], int n) 
{
    int start = 0;
    int end = n - 1;
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//3.1
bool isPrime(int num) 
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

//3.2
int countPrimes(const int arr[], int n) 
{
    int count = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (isPrime(arr[i])) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    const int n = 10;
    int arr[n] = { 3, 5, 1, 4, 9, 6, 7, 2, 8, 10 };

    //1
    int minValue, minIndex, maxValue, maxIndex;
    findMin(arr, n, minValue, minIndex);
    findMax(arr, n, maxValue, maxIndex);
    std::cout << minValue << " " << minIndex;
    std::cout << maxValue << " " << maxIndex << "\n";

    //2
    reverseArray(arr, n);
    std::cout << "Масив після зміни порядку: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n" << std::endl;

    //3
    int primeCount = countPrimes(arr, n);
    std::cout << primeCount << "\n" << std::endl;

    return 0;
}
