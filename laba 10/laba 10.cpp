#include <iostream>

using namespace std;

// Рекурсивная функция для вычисления значения A(m, n)

int A(int m, int n) {
    // Базовый случай: когда m равно 0
    if (m == 0) {
        return n + 1;
    }
    // Если m > 0 и n равно 0
    else if (m > 0 && n == 0) {
        return A(m - 1, 1);    // Рекурсивно вызываем A с аргументами (m - 1, 1)
    }
    // Если m > 0 и n > 0
    else if (m > 0 && n > 0) {
        return A(m - 1, A(m-1, n - 1));  // Рекурсивно вызываем A с аргументами (m - 1, A(m, n - 1))
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int m, n;
    cout << "Введите значения m и n: ";
    cin >> m >> n;

    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;

    return 0;
}

