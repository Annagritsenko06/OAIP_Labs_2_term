#include <iostream>
#include <cmath>

// Функция, которая вычисляет значение f(x)
double f(double x) {
    // Здесь необходимо вставить ваше уравнение
    return x * x - 4; // Пример: уравнение x^2 - 4 = 0
}

// Рекурсивная функция для нахождения корня уравнения
double dicho(double (*func)(double), double a, double b, double e) {
    double c = (a + b) / 2;

    // Условие выхода: ширина интервала меньше заданной точности
    if (b - a <= 2 * e) {
        return c;
    }

    // Проверяем знаки функции на концах интервала
    if (func(a) * func(c) <= 0) {
        // Знаки разные или одинаковые, но точность не удовлетворена
        return dicho(func, a, c, e);
    }
    else {
        // Знаки одинаковые
        return dicho(func, c, b, e);
    }
}

int main() {
    setlocale(LC_CTYPE,"RUS");
    double a, b, e;
    std::cout << "Введите значения a, b и e: ";
    std::cin >> a >> b >> e;

    // Проверяем, что на концах интервала функция имеет разные знаки
   /* if (f(a) * f(b) >= 0) {
        std::cout << "Ошибка: На концах интервала функция имеет одинаковые знаки." << std::endl;
        return 1;
    }*/

    // Вызываем рекурсивную функцию и выводим результат
    double root = dicho(f, a, b, e);
    std::cout << "Один из корней уравнения f(x) на отрезке [" << a << ", " << b << "] равен " << root << std::endl;

    return 0;
}
