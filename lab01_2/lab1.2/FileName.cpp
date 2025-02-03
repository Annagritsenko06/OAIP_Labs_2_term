#include <iostream>
#include <Windows.h>
#include <ctype.h>
using namespace std;

int sumn(int n, int a ...) {
    int* x = &a;
    int temp = a;
    int sum=0;
    x++;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum -= (temp * *x);
        }
        else {
            sum += (temp * *x);
        }
        temp = *x;
        x++;
    }
    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << sumn(5, 1, 6, 3, 5, 1) << '\n';
    cout << sumn(3, 5, 6, 7) << '\n';
    cout << sumn(2, -1, -10) << '\n';
}