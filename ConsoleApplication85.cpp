#include <iostream>

using namespace std;

struct Student 
{
    char name[50];
    unsigned short age;
    float averageGrade;
};

struct Book 
{
    char title[50];
    char author[50];
    unsigned short year;
};

struct Rectangle 
{
    float width;
    float height;
};

float calculateArea(const Rectangle& rect) 
{
    return rect.width * rect.height;
}

void showBooksAfterYear(Book* books, int size, unsigned short year) 
{
    cout << "\nКниги, видані після " << year << " року:\n";
    for (int i = 0; i < size; i++) 
    {
        if (books[i].year > year) 
        {
            cout << "Назва: " << books[i].title << ", Автор: " << books[i].author << ", Рік: " << books[i].year << endl;
        }
    }
}

int main() 
{
    int studentCount = 3;
    Student* students = new Student[studentCount]; 

    for (int i = 0; i < studentCount; i++) 
    {
        cout << "Введіть ім’я студента: ";
        cin.ignore();
        cin.getline(students[i].name, 50);
        cout << "Введіть вік студента: ";
        cin >> students[i].age;
        cout << "Введіть середній бал студента: ";
        cin >> students[i].averageGrade;
    }

    cout << "\nІнформація про студентів:\n";
    for (int i = 0; i < studentCount; i++) 
    {
        cout << "Ім’я: " << students[i].name << ", Вік: " << students[i].age << ", Середній бал: " << students[i].averageGrade << endl;
    }

    Student bestStudent = students[0];
    for (int i = 1; i < studentCount; i++) 
    {
        if (students[i].averageGrade > bestStudent.averageGrade) 
        {
            bestStudent = students[i];
        }
    }

    cout << "\nСтудент з найвищим середнім балом: " << bestStudent.name << " - " << bestStudent.averageGrade << endl;

    delete[] students; 

    int bookCount = 5;
    Book* books = new Book[bookCount]; 

    for (int i = 0; i < bookCount; i++) 
    {
        cout << "Введіть назву книги: ";
        cin.ignore();
        cin.getline(books[i].title, 50);
        cout << "Введіть автора книги: ";
        cin.getline(books[i].author, 50);
        cout << "Введіть рік видання: ";
        cin >> books[i].year;
    }

    unsigned short year;
    cout << "Введіть рік для фільтрації: ";
    cin >> year;
    showBooksAfterYear(books, bookCount, year);

    delete[] books; 

    
    Rectangle rect;
    cout << "Введіть ширину прямокутника: ";
    cin >> rect.width;
    cout << "Введіть висоту прямокутника: ";
    cin >> rect.height;
    cout << "Площа прямокутника: " << calculateArea(rect) << endl;

    return 0;
}