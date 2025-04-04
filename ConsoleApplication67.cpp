#include <iostream>
//1

double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b) 
{
    return a * b;
}

double divide(double a, double b) 
{
    if (b != 0)
        return a / b;
    else 
    {
        std::cerr << "Ошибка: деление на ноль!\n";
        return 0;
    }
}

int main() 
{
    
    double (*operations[4])(double, double) = { add, subtract, multiply, divide };

    
    double x, y;
    int op;

    std::cout << "Введите первое число: ";
    std::cin >> x;

    std::cout << "Введите второе число: ";
    std::cin >> y;

    std::cout << "Выберите операцию (0-сложение, 1-вычитание, 2-умножение, 3-деление): ";
    std::cin >> op;

    
    if (op >= 0 && op < 4) 
    {
        double result = operations[op](x, y); 
        std::cout << "Результат: " << result << std::endl;
    }
    else 
    {
        std::cerr << "Ошибка: некорректный выбор операции!\n";
    }

    return 0;
}