#include "MyQueue.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int n; //макс размер очереди

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int razmer = 0;
    int x;// временная переменная
    Node* start = NULL, * end = NULL;
    Node* t; //рабочий указатель 

    cout << "Введите размер очереди: " << endl;
    cin >> n;
    /*cout << "Введите значение 1 элемента: " << endl;
    cin >> x;
    t = new Node;
    t->el = x;
    t->next = NULL;

    start = end = t;

    for (int i = 1; i < n; i++) {

        cout << "Введите значение " << i + 1 << " элемента: " << endl;
        cin >> x;
        t->next = new Node;
        t = t->next;

        t->el = x;
        t->next = NULL;

        end = t;

    }*/


    char choice;
   /* menu();*/

    while (1) {
        cout << endl;
        cout << "Выберите режим работы с программой" << endl;
        cout << "1 - Вывод элементов очереди" << endl;
        cout << "2 - Добавление нового элемента (Ввод с клавиатуры) " << endl;
        cout << "3 - Удаление элемента очереди" << endl;
        cout << "4 - Размер очереди " << endl;
        cout << "5 - Вывод элементов очереди до первого нулевого(включительно с нулевым) " << endl;
        cout << "6 - Максимальный элемент очереди" << endl;
        cout << "0 - Выход из программы " << endl;
        cout << endl;
        
        cin >> choice;
        switch (choice) {
        case '1': {

            view(start);
            break; }
        case '2': {
            razmer = queue_length(start, end);
            e:
            cout << "Введите значение добавляемого элемента: " << endl;
        
            cin >> x;
            if (cin.fail() || cin.get() != '\n') { // Проверяем, не произошла ли ошибка ввода
                std::cin.clear(); // Очищаем флаг ошибки
                std::cin.ignore((32678), '\n'); // Игнорируем некорректный ввод до следующего перевода строки
                std::cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
                goto e;
            }
            if (razmer >= n) {
                cout << "Превышен размер очереди!!!!! " << endl;
                break;
            }
            else add_el_to_queue(start, end, x);
            break; }
        case '3': {

            cout << "Удаленный элемент = " << del(start, end) << endl;
            break;
        }
        case '4': {
            cout << "Размер очереди = " << queue_length(start, end) << endl;
            break;
        }
        case '5': {
            find_zero(start, end);
            
            break;
        }
        case '6': {
            cout << "Максимальный элемент очереди = " << max_queue(start) << endl;
            break;
        }
       
        case '0': {
            cout << "Выход из программы... ";
            return 0;
        }
        default: {
            cout << "Некорректное значение. Выберите что-то из списка." << endl;
            break;
        }
        }
    }

    return 0;
}

