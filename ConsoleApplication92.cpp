#include <iostream>
#include <fstream>

using namespace std;

struct Student 
{
    char name[50];  
    int age;
    float grade;
};

void writeToBinaryFile(const char* filename, Student* students, int count) 
{
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    file.write(reinterpret_cast<char*>(students), sizeof(Student) * count);
    file.close();
    cout << "Данные успешно записаны в " << filename << endl;
}

int main() 
{
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    cin.ignore(); 

    Student* students = new Student[n];

    for (int i = 0; i < n; ++i) 
    {
        cout << "Введите имя студента " << i + 1 << ": ";
        cin.getline(students[i].name, 50);
        cout << "Введите возраст студента " << i + 1 << ": ";
        cin >> students[i].age;
        cout << "Введите средний балл студента " << i + 1 << ": ";
        cin >> students[i].grade;
        cin.ignore(); 
    }

    writeToBinaryFile("students.bin", students, n);

    delete[] students; 
    return 0;
}