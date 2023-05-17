/*
Вариант 2
1. Реализовать пузырьковую сортировку - обходим массив, попутно
меняя местами неотсортированные соседние элементы. В результате
прохода на последнее место "всплывает" максимальный элемент.
2. Пользователь вводит с клавиатуры слово - найти это слово в
контейнере и вывести, сколько оно раз встречается в тексте
*/

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <fstream>

using namespace std;

int getRandomNumber(int min, int max) {
    int range = max - min + 1;
    return rand() % range + min;
}

void bubbleSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printVector(vector<int> vec, string label) {
    cout << label << endl;
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для приведения слова к нижнему регистру и удаления пунктуации
string normalizeWord(const string& word) {
    string normalizedWord;
    for (char c : word) {
        if (isalpha(c)) {
            normalizedWord += tolower(c);
        }
    }
    return normalizedWord;
}

// Функция для подсчета частоты встречаемости слов из текстового файла
map<string, int> countWordFrequency(const string& filename) {
    ifstream textFile(filename);
    map<string, int> wordFrequency;

    if (textFile.is_open()) {
        string word;
        while (textFile >> word) {
            word = normalizeWord(word);
            if (!word.empty()) {
                ++wordFrequency[word];
            }
        }
        textFile.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return wordFrequency;
}

// Функция для вывода слов и их частоты встречаемости
void printWordFrequency(const map<string, int>& wordFrequency) {
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    // Задание 1
    int numElements;

    cout << "Введите количество элементов: ";
    cin >> numElements;

    vector<int> vec(numElements);

    for (int & element : vec) {
        element = getRandomNumber(-100, 100);
    }

    // Выводим неотсортированный вектор
    printVector(vec, "Неотсортированный вектор: ");

    bubbleSort(vec);

    // Выводим отсортированный вектор
    printVector(vec, "Отсортированный вектор: ");

    // Задание 2
    string searchStr;

    // Путь к файлу
    string filename = "text.txt";

    map<string, int> wordFrequency = countWordFrequency(filename);

    cout << "Слова в тексте и их частота встречаемости: " << endl;
    printWordFrequency(wordFrequency);

    cout << "Какое слово ищем в тексте: ";
    cin >> searchStr;
    searchStr = normalizeWord(searchStr);

    cout << "Слово " << searchStr
        << " в тексте встречается "
        << wordFrequency[searchStr]
        << " раз" << endl;

    return 0;
}
