#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <regex>
#include <stdio.h>
using namespace std;
const unsigned int NAME_SIZE = 300;
const unsigned int CITY_SIZE = 200;
regex checkcity("(([A-ZА-Я]{1}[a-zа-я]+[ ]?)+||([A-ZА-Я]{1}[a-zа-я]+([\\-]{1})[A-ZА-Я]{1}[a-zа-я]+))");
struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};
bool check(string f) {
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }

    for (int i = 0; i < f.length(); i++) {
        if (i == 0) {
            if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= 'А' && f[0] <= 'Я')) {
                t = true;
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'А' && f[i] <= 'Я') && t) {
            if (f[i - 1] == '-') {
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= 'а' && f[i] <= 'я')) {
            if (f[i - 1] == '-') {
                return 0;
            }

            continue;
        }
        else if (f[i] == '-' || f[i] == ' ') {
            continue;
        }

        else {
            return 0;
        }
    }
    return 1;
}
//-----------------------------------------------------------
bool checkfio(string f) {
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }
    for (int i = 0; i < f.length(); i++) {
        if (i == 0) {
            if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= 'А' && f[0] <= 'Я')) {
                t = true;
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'А' && f[i] <= 'Я') && t) {
            if (f[i - 1] == '-') {
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= 'а' && f[i] <= 'я')) {
            if (f[i - 1] == '-') {
                return 0;
            }
            continue;
        }
        else if (f[i] == '-') {
            continue;
        }
        else {
            return 0;
        }
    }
    return 1;
}
int menu(void)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char s[80]; int c;
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Запись в файла" << endl;
    cout << "6. Чтение с файла" << endl;
    cout << "7. Поиск минимального(имени)" << endl;
    cout << "8. Поиск минимального(города)" << endl;
    cout << "0. Выход" << endl;
    cout << endl;

    do {
        cout << "Ваш выбор: ";
        cin.sync();
        gets_s(s);
        cout << endl;
        c = atoi(s);
    } while (c < 0 || c > 8);
    return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
    Address* p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
        return;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}
//-----------------------------------------------------------
Address* setElement() // Создание элемента и ввод его значений с клавиатуры
{
    Address* temp = new Address();
    if (!temp)
    {
        cerr << "Ошибка выделения памяти памяти";
        return NULL;
    }

    bool validInput = true;
    do {
        cout << "Введите имя: ";
    a:
        cin.getline(temp->name, NAME_SIZE - 1, '\n');
        validInput = checkfio(temp->name);

        if (!validInput) {
            printf("Имя введено некорректно.Введите еще раз!!!\n");
            cin.ignore(cin.rdbuf()->in_avail());
            cin.clear();
            goto a;
        }
        else
            break;
    } while (validInput);
   /* cout << "Введите город: ";
    while (!regex_match(temp->city, checkcity)) {
        cout << "Некорректный ввод\n";
       getline(cin,to_string(temp->city));
    }*/
    do {
        cout << "Введите город: ";
    an:
        cin.getline(temp->city, CITY_SIZE - 1, '\n');
        validInput = regex_match(temp->city, checkcity);

        if (!validInput) {
            printf("Город введен некорректно.Введите еще раз!!!\n");
            cin.ignore(cin.rdbuf()->in_avail());
            cin.clear();
            goto an;
        }
        else
            break;
    } while (validInput);
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) //Вывод списка на экран
{
    Address* t = *phead;
    while (t)
    {
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}
//-----------------------------------------------------------
//void find(char name[NAME_SIZE], Address** phead) // Поиск имени в списке
//{
//    Address* t = *phead;
//    while (t)
//    {
//        if (!strcmp(name, t->name)) break;
//        t = t->next;
//    }if (!t)
//        cerr << "Имя не найдено" << endl;
//    else
//        cout << t->name << ' ' << t->city << endl;
//}
////-----------------------------------------------------------
//void delet(char name[NAME_SIZE], Address** phead, Address** plast) // Удаление имени
//{
//    struct Address* t = *phead;
//    while (t)
//    {
//        if (!strcmp(name, t->name)) break;
//        t = t->next;
//    }
//    if (!t)
//        cerr << "Имя не найдено" << endl;
//    else
//    {
//        if (*phead == t)
//        {
//            *phead = t->next;
//            if (*phead)
//                (*phead)->prev = NULL;
//            else
//                *plast = NULL;
//        }
//        else
//        {
//            t->prev->next = t->next;
//            if (t != *plast)
//                t->next->prev = t->prev;
//            else
//                *plast = t->prev;
//        }
//        delete t; cout << "Элемент удален" << endl;
//    }
//}
void find(char name[NAME_SIZE], Address** phead) // Поиск имени в списке
{
    Address* t = *phead;
    bool found = false;
    while (t)
    {
        if (!strcmp(name, t->name)) {
            found = true;
            cout << t->name << ' ' << t->city << endl;
        }
        t = t->next;
    }
    if (!found)
        cerr << "Имя не найдено" << endl;
}
void delet(char name[NAME_SIZE], Address** phead, Address** plast) // Удаление имени
{
    struct Address* t = *phead;
    bool deleted = false;
    while (t)
    {
        if (!strcmp(name, t->name)) {
            deleted = true;
            if (*phead == t)
            {
                *phead = t->next;
                if (*phead)
                    (*phead)->prev = NULL;
                else
                    *plast = NULL;
                delete t;
                cout << "Элемент удален" << endl;
                t = *phead; // Переходим к следующему элементу после удаления
            }
            else
            {
                t->prev->next = t->next;
                if (t != *plast)
                    t->next->prev = t->prev;
                else
                    *plast = t->prev;
                struct Address* temp = t->next; // Сохраняем указатель на следующий элемент перед удалением текущего
                delete t;
                cout << "Элемент удален" << endl;
                t = temp; // Переходим к следующему элементу после удаления
            }
        }
        else
        {
            t = t->next;
        }
    }
    if (!deleted)
        cerr << "Имя не найдено" << endl;
}


void findMin(Address** phead) {
    Address* temp = *phead;//задаем пачатковае значэнне для буфернага элемента
    Address* min = *phead;//задаем пачатковае значэнне для мін элемента

    temp = temp->next;
    while (temp)
    {
        if (strlen(temp->name) < strlen(min->name))//шукаем мініэлемент
            min = temp;
        temp = temp->next;
    }
    cout << "Элемент с минимальным именем:" << min->name << " " << min->city << endl;//выводзім яго
}

void findMin_city(Address** phead) {
    Address* temp = *phead;//задаем пачатковае значэнне для буфернага элемента
    Address* min = *phead;//задаем пачатковае значэнне для мін элемента

    temp = temp->next;
    while (temp)
    {
        if (strlen(temp->city) < strlen(min->city))//шукаем мініэлемент
            min = temp;
        temp = temp->next;
    }
    cout<<"Элемент с минимальным городом:" << min->name << " " << min->city << endl;//выводзім яго
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void writeToFile(Address** phead) //Запись в файл
{
    struct Address* t = *phead;
    ofstream file("mlist.txt"); // Открываем файл для записи
    if (!file.is_open()) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    cout << "Сохранение в файл" << endl;
    while (t)
    {
        file << t->name << endl;
        file << t->city << endl;
        t = t->next;
    }
    file.close();
}
//-----------------------------------------------------------
//void readFromFile(Address** phead, Address** plast) //Считывание из файла
//{
//    struct Address* t;
//    ifstream file("mlist.txt"); // Открываем файл для чтения
//    if (!file.is_open()) {
//        cerr << "Файл не открывается" << endl;
//        exit(1);
//    }
//    while (*phead)
//    {
//        *plast = (*phead)->next;
//        delete* phead;
//        *phead = *plast;
//    }
//    *phead = *plast = NULL;
//    cout << "Загрузка из файла" << endl;
//    string line;
//    while (getline(file, line)) {
//        t = new Address();
//        if (!t)
//        {
//            cerr << "Ошибка выделения памяти" << endl;
//            return;
//        }
//        strcpy_s(t->name, line.c_str());
//        getline(file, line);
//        strcpy_s(t->city, line.c_str());
//        t->next = NULL;
//        // Далее вставляем узел в список (*phead, *plast)
//        // Например, через вашу функцию insert
//        insert(t, phead, plast);
//    }
//    file.close();
//}
void readFromFile(Address** phead, Address** plast) //Считывание из файла
{
    struct Address* t;
    ifstream file("mlist.txt"); // Открываем файл для чтения
    if (!file.is_open()) {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    while (*phead)
    {
        *plast = (*phead)->next;
        delete* phead;
        *phead = *plast;
    }
    *phead = *plast = NULL;
    cout << "Загрузка из файла" << endl;
    string line;
    int count = 0;
    while (getline(file, line)) {
        t = new Address();
        if (!t)
        {
            cerr << "Ошибка выделения памяти" << endl;
            return;
        }
        strcpy_s(t->name, line.c_str());
        getline(file, line);
        strcpy_s(t->city, line.c_str());
        t->next = NULL;
        // Далее вставляем узел в список (*phead, *plast)
        // Например, через вашу функцию insert
        insert(t, phead, plast);
        // Выводим данные в консоль
        cout << "Запись " << ++count << ": " << t->name << ' ' << t->city << endl;
    }
    file.close();
}


int main(void)
{
    Address* head = NULL;
    Address* last = NULL;
    setlocale(LC_CTYPE, "Rus");
    while (true)
    {
        switch (menu())
        {
        case 1: insert(setElement(), &head, &last);
            break;
        case 2: { char dname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            delet(dname, &head, &last);
        }
              break;
        case 3: outputList(&head, &last);
            break;
        case 4: { char fname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
        }
              break;
        case 5:
            writeToFile(&head);
            break;

        case 6:
            readFromFile(&head, &last);
            break;

        case 7:
            findMin(&head);           
            break;
        case 8:
            findMin_city(&head);
            break;
        case 0:
            exit(0);

        default:
            exit(1);
        }
    }
    return 0;
}
