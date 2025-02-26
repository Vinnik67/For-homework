#include <iostream>

enum Menu 
{
    PLUS = 101,
    MINUS = 102,
    DIVIDE = 103,
    MULT = 104,
    EXIT = 0
};

double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double divide(double a, double b) 
{
    if (b != 0) 
    {
        return a / b;
    }
    else 
    {
       std::cout << "Error: divide by 0!" << std::endl;
        return 0;
    }
}

double multiply(double a, double b) 
{
    return a * b;
}

void menu() 
{
    std::cout << "Menu" << std::endl;
    std::cout << "101. add" << std::endl;
    std::cout << "102. substract" << std::endl;
    std::cout << "103. divide" << std::endl;
    std::cout << "104. multyply" << std::endl;
    std::cout << "0. exit" << std::endl;
}

int main() 
{
    int choice;
    double num1, num2;

    do 
    {
        menu();
        std::cout << "Choose what to do: ";
        std::cin >> choice;

        if (choice != EXIT) 
        {
            std::cout << "Enter first num: ";
            std::cin >> num1;
            std::cout << "Enter second num: ";
            std::cin >> num2;
        }

        switch (choice) 
        {
        case PLUS:
            std::cout << "Result: " << add(num1, num2) << std::endl;
            break;
        case MINUS:
            std::cout << "Result: " << subtract(num1, num2) << std::endl;
            break;
        case DIVIDE:
            std::cout << "Result: " << divide(num1, num2) << std::endl;
            break;
        case MULT:
            std::cout << "Result: " << multiply(num1, num2) << std::endl;
            break;
        case EXIT:
            std::cout << "Exit programm." << std::endl;
            break;
        default:
            std::cout << "Non in the list. Try again." << std::endl;
            break;
        }
    } while (choice != EXIT);

    return 0;
}
