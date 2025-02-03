#include "Heap.h" 
#include <iostream> 
#include <fstream> 
using namespace std; 

heap::CMP cmpAAA(void* a1, void* a2) 
{
#define A1 ((AAA*)a1) 
#define A2 ((AAA*)a2)

    heap::CMP rc = heap::EQUAL; 
    if (A1->x > A2->x) 
        rc = heap::GREAT; 
    else if (A2->x > A1->x) 
        rc = heap::LESS; 
    return rc; 
#undef A2 
#undef A1 
}

int main() 
{
    setlocale(LC_ALL, "rus"); 
    int k; 
    heap::Heap h1 = heap::Create(30, cmpAAA), h2 = heap::Create(30, cmpAAA); 

    int choise; 
    AAA* aa, * bb; 
    AAA* a, * b;

    for (;;) // Бесконечный цикл
    {
        cout << "1 - Добавить элемент в кучу 1" << endl; // Вывод меню действий
        cout << "2 - Вывод кучи 1 на экран" << endl;
        cout << "3 - Удаление максимального из кучи 1" << endl;
        cout << "4 - Удаление минимального из кучи 1" << endl;
        cout << "5 - Удаление i-ого элемента из кучи 1" << endl;
        cout << "6 - Объединения двух куч в одну" << endl;
        cout << "7 - Добавить элемент в кучу 2" << endl;
        cout << "8 - Вывод кучи 2 на экран" << endl;
        cout << "9 - Удаление максимального из кучи 2" << endl;
        cout << "10 - Удаление минимального из кучи 2" << endl;
        cout << "11 - Удаление i-ого элемента из кучи 2" << endl;
        cout << "0 - Выход" << endl;
        cout << "Что надо сделать?" << endl;
        cin >> choise; 
        switch (choise) 
        {
        case 0: exit(0); 
        case 1: 
            a = new AAA; 
            cout << "Введите элемент " << endl; 
            cin >> k; 
            a->x = k; 
            h1.Insert(a); 
            break;
        case 2: h1.Scan(0); 
            break;
        case 3: 
            a = (AAA*)h1.ExtractMax(); 
            if (a != NULL) 
            {
                cout << "Максимальный элемент: " << a->x << endl; 
                h1.Scan(0); 
            }
            else cout << "Куча пуста." << endl; 
            break;
        case 4:
            a = (AAA*)h1.ExtractMin(); 
            if (a != NULL) 
            {
                cout << "Минимальный элемент: " << a->x << endl; 
                h1.Scan(0); 
            }
            else cout << "Куча пуста." << endl; 
            break;
        case 5: 
            cout << "Введите номер элемента " << endl; 
            cin >> choise; 
            a = (AAA*)h1.ExtractI(choise); 
            if (a != NULL) 
            {
                cout << "Извлечённый элемент: " << a->x << endl; 
                h1.Scan(0);
            }
            else cout << "Куча пуста." << endl; 
        case 6: 
            h1.Merge(h2); 
            h1.Scan(0);
            break;
        case 7:
            b = new AAA;
            cout << "Введите элемент " << endl; 
            cin >> k; 
            b->x = k; 
            h2.Insert(b); 
            break;
        case 8: h2.Scan(0); 
            break;
        case 9: 
            aa = (AAA*)h2.ExtractMax(); 
            if (aa != NULL) 
            {
                cout << "Максимальный элемент: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "Куча пуста." << endl; 
            break;
        case 10: 
            aa = (AAA*)h2.ExtractMin();
            if (aa != NULL) 
            {
                cout << "Минимальный элемент: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "Куча пуста." << endl; 
            break;
        case 11: 
            cout << "Введите номер элемента " << endl; 
            cin >> choise; 
            aa = (AAA*)h2.ExtractI(choise); 
            if (aa != NULL) 
            {
                cout << "Извлечённый элемент: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "Куча пуста." << endl; 
            break;
        
        default:
            cout << endl << "Введена неверная команда" << endl; // Вывод сообщения о неверной команде
            cout << endl;
        }
    }
}

