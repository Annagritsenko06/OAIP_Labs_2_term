#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include <cstring>
#include <iomanip>
using namespace std;
void callfunc(double& a, double& b) { 
    cout << "¬ведите a, b" << '\n';
    cin >> a >> b;
}

double func2(double x) {
    return(2 - x * x + x);
}

double func1(double x) {
    return(sin(x) * sin(x) + 0.2);
}

double dihotomy(double& result, void(*callfunc)(double&, double&), double(*func)(double)) { 
    double y1, y2;
    double a, b;
    callfunc(a, b);
    while (abs(a - b) > 2 * 0.001) {
        result = (a + b) / 2;
        y1 = func(result);
        y2 = func(a);
        if (y1 * y2 <= 0) {
            b = result;
        }
        else {
            a = result;
        }
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double result = 0;
    cout << dihotomy(result, callfunc, func1) << '\n';
    cout << dihotomy(result, callfunc, func2) << '\n';
}