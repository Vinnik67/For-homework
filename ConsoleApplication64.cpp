#include <iostream>
#include <cmath> 


//1
void my_increment(int* ptr, int n = 1) 
{
    *ptr += n;
}

//2
void multiply(int* a, int* b, int* result) 
{
    *result = (*a) * (*b);
}

//3
void negate(double* ptr) 
{
    *ptr = -(*ptr);
}

//4
void setValue(int* ptr, int newValue) 
{
    *ptr = newValue;
}

//5
void concatenateDigits(int* a, int* b, int* result) 
{
    int bDigits = log10(*b) + 1; 
    *result = (*a) * pow(10, bDigits) + (*b);
}

int main() {
    
    int value = 10;
    my_increment(&value, 5);
    std::cout << "After my_increment: " << value << std::endl;

    
    int x = 3, y = 4, product;
    multiply(&x, &y, &product);
    std::cout << "Multyply result: " << product << std::endl;

    
    double num = 5.5;
    negate(&num);
    std::cout << "After negate: " << num << std::endl;

    
    int var = 20;
    setValue(&var, 99);
    std::cout << "New Value: " << var << std::endl;

   
    int a = 12, b = 34, concatenated;
    concatenateDigits(&a, &b, &concatenated);
    std::cout << "merged number: " << concatenated << std::endl;

    return 0;
}