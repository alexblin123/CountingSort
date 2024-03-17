#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

static int findMaxValue(const int arr[], int length) {

    int maxValue = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

static int findMinValue(const int arr[], int length) {

    int minValue = arr[0];

    for (int i = 1; i < length; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

static void countingSort(int *arr, int length) {

    int minValue = findMinValue(arr, length);
    int maxValue = findMaxValue(arr, length);

    int elemsRange = maxValue - minValue + 1;

    int* countElems = new int[elemsRange]();


    for (int i = 0; i < length; i++) {
        countElems[arr[i] - minValue]++;
    }

 
    int index = 0;

    for (int i = 0; i < elemsRange; i++) {
        while (countElems[i] > 0) {
            arr[index++] = i + minValue; 
            countElems[i]--;
        }
    }

    delete[] countElems;
}

int main() {

    const int size = 25;
    int* arr = new int[size];

    srand(time(0)); 
    system("chcp 1251 > Null");

   
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 56 - 25; 
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    auto start = high_resolution_clock::now();

    countingSort(arr, size);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "Отсортрованный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl << "Время выполнения программы (в микросекундах): " << duration.count() << endl;

    delete[] arr;

    return 0;
}
