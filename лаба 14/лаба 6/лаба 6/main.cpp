#include "Hash_Chain.h"
#include <iostream>
#include <chrono>
#include <string>
#include <Windows.h>
using namespace std::chrono;
using namespace std;
bool validInput = true;
bool check(string f) {
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }
    for (int i = 0; i < f.length(); i++) {
        if ((f[i] >= '0' && f[i] <= '9') /*|| (f[i] >= 'а' && f[i] <= 'я')*/) {
            /*if (f[i - 1] == '-') {
                return 0;
            }*/
            return 0;
        }

        else {

            continue;
        }
    }
    return 1;

}
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = nullptr;
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int current_size = 7;
    cout << "Введите размер хеш-таблицы" << endl;
    cin >> current_size;
    hashTC::Object H = hashTC::create(current_size, hf);
    int choice;
    long k;
    for (;;)
    {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: exit(0);
        case 2: {
            AAA* a = new AAA;
            char* str = new char[1000];
            a:
            cout << "введите номер маршрута " << endl;
            cin >> k;
            if (cin.fail() || cin.get() != '\n') {
                cout << "Некорректный ввод...Попробуйте еще раз " << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                goto a;
            }
            a->key = k;
            do{
                i:
            cout << "введите название маршрута " << endl;
            cin.getline(str, 256, '\n');
            validInput = check(str);
            if (!validInput) {
                printf("Название маршрута введено некорректно.Введите еще раз!!!\n");
                goto i;
            }
            else
                break;
            } while (validInput);
            a->mas = str;
            H.insert(a);
        }
              break;
        case 1: H.Scan();
            break;
        case 3: {
            AAA* b = new AAA;
            cout << "введите номер маршрута" << endl;
            cin >> k;
            b->key = k;
            H.deleteByData(b);
        }
              break;
        case 4: {
            AAA* c = new AAA;
            cout << "введите номер маршрута" << endl;
            cin >> k;
            c->key = k;

            // Измерение времени начинается перед вызовом функции поиска
            auto start = high_resolution_clock::now();

            listx::Element* result = H.search(c);

            // Измерение времени завершается после выполнения функции поиска
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Время выполнения поиска: " << duration.count() << endl;

            if (result == NULL)
                cout << "Элемент не найден" << endl;
            else
            {
                cout << "Первый элемент с данным номер маршрута" << endl;
                AAA_print(result);
                cout << endl;
            }
        }
              break;
        }
    }
    return 0;
}