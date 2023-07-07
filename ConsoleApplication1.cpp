#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void processArrays(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Не удалось открыть входной файл." << endl;
        return;
    }

    int array1[5], array2[6];
    int num;
    int size1, size2;

    // Чтение второго массива
    inputFile >> size2; // Чтение размера второго массива
    for (int i = 0; i < size2; i++) {
        inputFile >> num;
        array2[i] = num;
    }

    // Чтение первого массива
    inputFile >> size1; // Чтение размера первого массива
    for (int i = 0; i < size1; i++) {
        inputFile >> num;
        array1[i] = num;
    }

    inputFile.close();

    // Переворачиваем массивы
    reverse(array1, array1 + size1);
    reverse(array2, array2 + size2);

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Не удалось открыть выходной файл." << endl;
        return;
    }

    // Запись первого массива в выходной файл
    outputFile << "Размер первого массива: " << size1 << endl;
    for (int i = 0; i < size1; i++) {
        outputFile << array1[i] << " ";
    }
    outputFile << endl;

    // Запись второго массива в выходной файл
    outputFile << "Размер второго массива: " << size2 << endl;
    for (int i = 0; i < size2; i++) {
        outputFile << array2[i] << " ";
    }
    outputFile << endl;

    outputFile.close();
}

int main() {
    string inputFileName = "int.txt";
    string outputFileName = "out.txt";

    processArrays(inputFileName, outputFileName);

    return 0;
}
