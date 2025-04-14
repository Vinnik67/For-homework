#include <iostream>
#include <ctime>

void task1(int*& array, int& size) 
{
    
    int newSize = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (array[i] <= 100) 
        {
            array[newSize++] = array[i];
        }
    }
    size = newSize;
}

void task2(int*& array, int& size, int index) 
{
    
    if (index < 0 || index >= size) 
    {
        std::cout << "Incorrect index!" << std::endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) 
    {
        array[i] = array[i + 1];
    }
    size--;
}

void task3(int*& array, int size) 
{
    
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        sum += array[i];
    }
    if (sum > 100) 
    {
        for (int i = 0; i < size; ++i) 
        {
            array[i] *= 10;
        }
    }
    else 
    {
        for (int i = 0; i < size; ++i) 
        {
            array[i] /= 10;
        }
    }
}

int main() 
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    // Создание массива в heap
    int* array = new int[size];

    // Заполнение массива значениями
    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cin >> array[i];
    }

    //1
    task1(array, size);
    std::cout << "Array after deliting elements > than 100: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //2
    int index;
    std::cout << "Enter index of element: ";
    std::cin >> index;
    task2(array, size, index);
    std::cout << "Array after deliting element: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //3
    std::srand(std::time(nullptr)); 
    for (int i = 0; i < size; ++i) 
    {
        array[i] = std::rand() % 50; 
    }
    task3(array, size);
    std::cout << "Array after: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    
    delete[] array;

    return 0;
}