#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) {
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1) Print(a, size, i + 1);
    else cout << endl;
}

int Max(int* a, const int size, int i = 0, int max = INT_MIN) {
    if (i == size) return max;
    if (a[i] > max) max = a[i];
    return Max(a, size, i + 1, max);
}

int Min(int* a, const int size, int i = 0, int min = INT_MAX) {
    if (i == size) return min;
    if (a[i] < min) min = a[i];
    return Min(a, size, i + 1, min);
}

double MeanOfMaxMin(int* a, const int size) {
    int maxElement = Max(a, size);
    int minElement = Min(a, size);
    return (maxElement + minElement) / 2.0;
}

int main() {
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 5;
    int a[n];
    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "max = " << Max(a, n) << endl;
    cout << "min = " << Min(a, n) << endl;
    cout << "Mean of max and min elements = " << MeanOfMaxMin(a, n) << endl;

    return 0;
}
