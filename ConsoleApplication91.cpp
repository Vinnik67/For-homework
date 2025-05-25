#include <iostream>
#include <fstream>

using namespace std;

bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool is_alpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + ('a' - 'A');
    return ch;
}

void analyzeFile(const char* inputPath, const char* outputPath) {
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    char ch;

    while (inputFile.get(ch)) {
        charCount++;
        if (ch == '\n') {
            lineCount++;
        }
        else if (is_digit(ch)) {
            digitCount++;
        }
        else if (is_alpha(ch)) {
            char lowerCh = to_lower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u' || lowerCh == 'y')
                vowelCount++;
            else
                consonantCount++;
        }
    }

    outputFile << "Количество символов: " << charCount << endl;
    outputFile << "Количество строк: " << lineCount << endl;
    outputFile << "Количество гласных: " << vowelCount << endl;
    outputFile << "Количество согласных: " << consonantCount << endl;
    outputFile << "Количество цифр: " << digitCount << endl;

    inputFile.close();
    outputFile.close();

    cout << "Анализ завершен! Результаты записаны в " << outputPath << endl;
}

int main() {
    const char* inputFile = "input.txt";  // Исходный файл
    const char* outputFile = "stats.txt"; // Файл статистики

    analyzeFile(inputFile, outputFile);

    return 0;
}