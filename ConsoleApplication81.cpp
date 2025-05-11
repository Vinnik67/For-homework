#include <iostream>



struct WashingMachine 
{
    char brand[20];
    char color[20];
    double width, length, height, power;
    int spinSpeed, heatingTemp;

    void display() 
    {
        std::cout << "Пральна машинка: " << brand << ", " << color
            << ", розміри: " << width << "x" << length << "x" << height
            << ", потужність: " << power << "Вт, швидкість віджиму: "
            << spinSpeed << " об./хв, температура нагріву: " << heatingTemp << "°C\n";
    }
};


struct Iron 
{
    char brand[20];
    char model[20];
    char color[20];
    int minTemp, maxTemp, power;
    bool steamSupply;

    void display() 
    {
        std::cout << "Праска: " << brand << " " << model << ", " << color
            << ", температура: " << minTemp << "-" << maxTemp << "°C, потужність: "
            << power << "Вт, подача пари: " << (steamSupply ? "Так" : "Ні") << "\n";
    }
};


struct Boiler 
{
    char brand[20];
    char color[20];
    int power, capacity, heatingTemp;

    void display() 
    {
        std::cout << "Бойлер: " << brand << ", " << color
            << ", потужність: " << power << "Вт, обсяг: "
            << capacity << "л, температура нагріву: " << heatingTemp << "°C\n";
    }
};


struct Animal 
{
    char name[20];
    char type[20];
    char nickname[20];

    void input() 
    {
        std::cout << "Введіть назву: ";
        std::cin >> name;
        std::cout << "Введіть клас: ";
        std::cin >> type;
        std::cout << "Введіть кличку: ";
        std::cin >> nickname;
    }

    void display() 
    {
        std::cout << "Тварина: " << name << ", клас: " << type
            << ", кличка: " << nickname << "\n";
    }

    void makeSound() 
    {
        std::cout << nickname << " видає звук!\n";
    }
};

int main() 
{
    WashingMachine wm = { "Samsung", "Біла", 60, 40, 85, 2000, 1200, 60 };
    wm.display();

    Iron iron = { "Philips", "GC4909", "Синій", 100, 250, 2400, true };
    iron.display();

    Boiler boiler = { "Ariston", "Срібний", 1500, 80, 75 };
    boiler.display();

    Animal animal;
    animal.input();
    animal.display();
    animal.makeSound();

    return 0;
}