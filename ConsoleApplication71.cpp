#include <iostream>


int mystrlen(const char* str) 
{
    int length = 0;
    while (*str++) 
    {
        length++;
    }
    return length;
}


char* mystrcpy(char* str1, const char* str2) 
{
    char* temp = str1;
    while ((*str1++ = *str2++));
    return temp;
}


char* mystrcat(char* str1, const char* str2) 
{
    char* temp = str1;
    while (*str1) 
    {
        str1++;
    }
    while ((*str1++ = *str2++));
    return temp;
}


char* mystrchr(char* str, char s) 
{
    while (*str) 
    {
        if (*str == s) 
        {
            return str;
        }
        str++;
    }
    return nullptr;
}


char* mystrstr(char* str1, char* str2) 
{
    if (!*str2) 
    {
        return str1;
    }
    while (*str1) 
    {
        const char* temp1 = str1;
        const char* temp2 = str2;
        while (*temp1 && *temp2 && *temp1 == *temp2) 
        {
            temp1++;
            temp2++;
        }
        if (!*temp2) 
        {
            return str1;
        }
        str1++;
    }
    return nullptr;
}

int main() {
    
    char str1[100] = "Hello";
    char str2[] = "World";

    std::cout << "Length str1: " << mystrlen(str1) << std::endl;
    std::cout << "Copying: " << mystrcpy(str1, str2) << std::endl;
    std::cout << "Multyply: " << mystrcat(str1, "!!!") << std::endl;
    std::cout << "Symbol search: " << mystrchr(str1, 'o') << std::endl;
    std::cout << "Search: " << mystrstr(str1, "Wo") << std::endl;

    return 0;
}