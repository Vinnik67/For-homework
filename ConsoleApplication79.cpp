#include <iostream>
#include <cstring> 
const int MAX_LENGTH = 50; 


char** inputSurnames(int& n) 
{
    std::cout << "Введіть кількість студентів: ";
    std::cin >> n;

    char** surnames = new char* [n];

    std::cout << "Введіть прізвища:\n";
    for (int i = 0; i < n; ++i) 
    {
        surnames[i] = new char[MAX_LENGTH];
        std::cin >> surnames[i]; 
    }

    return surnames;
}


void printSurnames(char** surnames, int n) 
{
    std::cout << "Введені прізвища:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << surnames[i] << std::endl;
    }
}


bool findSurname(char** surnames, int n, const char* search) 
{
    for (int i = 0; i < n; ++i) 
    {
        if (std::strcmp(surnames[i], search) == 0) 
        {
            return true;
        }
    }
    return false;
}


void deleteSurnames(char** surnames, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        delete[] surnames[i];
    }
    delete[] surnames;
}

int main() 
{
    int n;
    char** surnames = inputSurnames(n);

    printSurnames(surnames, n);

    char searchSurname[MAX_LENGTH];
    std::cout << "Enter lastname for search: ";
    std::cin >> searchSurname;

    if (findSurname(surnames, n, searchSurname)) 
    {
        std::cout << "Lastname \"" << searchSurname << "\" finded.\n";
    }
    else 
    {
        std::cout << "Lastname \"" << searchSurname << "\" not finded.\n";
    }

    deleteSurnames(surnames, n); 

    return 0;
}