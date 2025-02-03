#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

//void push(MYSTACK*& fp, char y)  //Добавление элемента х в стек	
//{
//    MYSTACK* e = new MYSTACK;    //выделение памяти для нового элемента
//	e->x = y;             //запись элемента x в поле data 
//	e->p = fp;         //перенос вершины на следующий элемент 
//	fp = e;               //сдвиг вершины на позицию вперед
//}
//
//int pop(MYSTACK*& myStk)   //Извлечение (удаление) элемента из стека
//{
//	if (myStk == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат (-1) 
//	}
//	else
//	{
//        MYSTACK*e = myStk;        //е-переменная для хранения адреса элемента
//		char x = myStk->x;    //запись элемента из поля data в перем. x 
//		if (myStk)
//			myStk = myStk->p;   //перенос вершины
//		delete e;
//		return x;
//	}
//}
////void toFile(Stack*& myStk) //Запись в файл
////{
////	Stack* e = myStk;
////	Stack buf;
////	ofstream frm("mStack.dat");
////	if (frm.fail())
////	{
////		cout << "\n Ошибка открытия файла";
////		exit(1);
////	}
////	while (e)
////	{
////		buf = *e;
////		frm.write((char*)&buf, sizeof(Stack));
////		e = e->next;
////	}
////	frm.close();
////	cout << "Стек записан в файл mStack.dat\n";
////}
////
////void fromFile(Stack*& myStk)          //Считывание из файла
////{
////	Stack buf, * p = nullptr, * e = nullptr;
////	ifstream frm("mStack.dat");
////	if (frm.fail())
////	{
////		cout << "\n Ошибка открытия файла";
////		exit(1);
////	}
////	frm.seekg(0);
////	frm.read((char*)&buf, sizeof(Stack));
////	while (!frm.eof())
////	{
////		push(buf.data, e);
////		frm.read((char*)&buf, sizeof(Stack));
////	}
////	frm.close();
////	while (e != NULL)
////	{
////		buf.data = pop(e);
////		push(buf.data, p);
////		myStk = p;
////	}
////	cout << "\nСтек считан из файла mStack.dat\n\n";
////}
////void show(Stack*& myStk)  //Вывод стека с очисткой
////{
////	Stack* e = myStk;
////	if (e == NULL)
////		cout << "Стек пуст!" << endl;
////	while (e != NULL)
////		cout << pop(e) << " ";
////	cout << endl;
////}
//
//
//
//void menu() {
//    cout << endl;
//    cout << "Выберите режим работы с программой" << endl;
//    cout << "1 - Добавление элемента в стек " << endl;
//    cout << "2 - Извлечение верхнего элемента из стека " << endl;
//    cout << "3 - Вывести текущий стек  " << endl;
//    cout << "4 - Запись стека в файл " << endl;
//    cout << "5 - Считывание стека из файла " << endl;
//    cout << "6 - Очистить текущий стек " << endl;
//    cout << "7 - Посчитать количество элементов в стеке, у которых равные соседи.  " << endl;
//    cout << "h - Вызов меню " << endl;
//    cout << "q - Выход из программы " << endl;
//}
//
//void view(MYSTACK* fp) {
//    if (fp == NULL)
//        cout << "Стек пуст!" << endl; // Если стек пуст, выводим сообщение об этом.
//    else {
//        cout << "Стек:" << endl; // Выводим заголовок "Стек:".
//        while (fp) { // Пока не достигнут конец стека:
//            cout << " -> " << fp->x; // Выводим значение текущего элемента стека.
//            fp = fp->p; // Переходим к следующему элементу стека.
//        }
//        cout << " -> NULL " << endl; // Выводим указатель на конец стека.
//    }
//}
//
//void tofile(MYSTACK* fp) {
//    MYSTACK buf; // Создаем временную переменную для хранения данных из стека.
//    ofstream file("stackMemory.txt"); // Открываем файл для записи.
//    if (file.fail()) { // Проверяем, удалось ли открыть файл.
//        cout << "Ошибка открытия файла stackMemory.txt"; // Если не удалось, выводим сообщение об ошибке.
//        exit(1); // Завершаем программу с кодом ошибки.
//    }
//    else {
//        while (fp) { // Пока не достигнут конец стека:
//            buf = *fp; // Копируем данные текущего элемента стека в буфер.
//            file.write((char*)&buf, sizeof(MYSTACK)); // Записываем данные из буфера в файл.
//            fp = fp->p; // Переходим к следующему элементу стека.
//        }
//        file.close(); // Закрываем файл.
//        cout << "Текущий стек записан в stackMemory.txt " << endl; // Выводим сообщение об успешной записи стека в файл.
//    }
//}
//void fromfile(MYSTACK*& first) {
//    MYSTACK buf, * t1 = NULL, * t2 = NULL; // Объявляем переменные для временного хранения данных из файла и для работы со стеком.
//    ifstream file("stackMemory.txt"); // Открываем файл для чтения.
//    if (file.fail()) { // Проверяем, удалось ли открыть файл.
//        cout << "Ошибка открытия файла stackMemory.txt"; // Выводим сообщение об ошибке.
//        exit(1); // Завершаем программу с кодом ошибки.
//    }
//    else {
//        file.seekg(0); // Устанавливаем позицию чтения в начало файла.
//        file.read((char*)&buf, sizeof(MYSTACK)); // Читаем данные из файла в буферную переменную buf.
//        while (!file.eof()) { // Пока не достигнут конец файла:
//            push(first, buf.x); // Добавляем элемент из буфера в стек.
//            file.read((char*)&buf, sizeof(MYSTACK)); // Читаем следующие данные из файла.
//        }
//        file.close(); // Закрываем файл.
//        while (first) { // Пока стек не пуст:
//            buf.x = pop(first); // Извлекаем элемент из стека и сохраняем его в буферной переменной buf.
//            push(t2, buf.x); // Добавляем извлеченный элемент во временный стек t2.
//            t1 = first; // Сохраняем текущий указатель на первый элемент стека.
//        }
//        first = t2; // Обновляем указатель на первый элемент стека first.
//        cout << "Стек считан из stackMemory.txt " << endl; // Выводим сообщение об успешном считывании стека из файла.
//    }
//}
//
//void clear(MYSTACK*& fp) {
//    while (fp) // Пока стек не пуст:
//        pop(fp); // Извлекаем элементы из стека.
//    cout << "Стек очищен! " << endl; // Выводим сообщение о том, что стек очищен.
//}
//
//int sosedi(MYSTACK* fp) {
//    MYSTACK* next1 = fp->p; // Указатель на следующий элемент стека.
//    if (fp == NULL || next1 == NULL || next1->p == NULL || next1->p->p == NULL) // Проверяем, что стек содержит как минимум три элемента.
//        return 0; // Если условие не выполнено, возвращаем 0, так как невозможно определить соседей.
//    int count = 0; // Инициализируем счетчик для подсчета соседей.
//    while (next1->p != nullptr) { // Пока не достигнут конец стека:
//        if (fp->x == next1->x && next1->x == next1->p->x) // Проверяем, равны ли текущий элемент и его соседи.
//            count++; // Увеличиваем счетчик на единицу, если соседи равны текущему элементу.
//        fp = fp->p; // Переходим к следующему элементу стека.
//        next1 = fp->p; // Обновляем указатель на следующий элемент стека.
//    }
//    return count; // Возвращаем количество найденных соседей.
//}
//
//


Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    clear();
}

void Stack::push(const std::string& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

std::string Stack::pop() {
    if (isEmpty()) {
        return ""; // или другое значение, обозначающее ошибку или пустой стек
    }
    std::string data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(const char* filename) {
    std::ofstream file(filename);
    if (!file) {
        // обработка ошибки
        return;
    }
    Node* current = top;
    while (current) {
        file << current->data << std::endl;
        current = current->next;
    }
    file.close();
}

void Stack::readFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        // обработка ошибки
        return;
    }
    clear(); // очищаем стек перед загрузкой данных из файла
    std::string data;
    while (std::getline(file, data)) {
        std::cout << "Добавлен элемент в стек: " << data << std::endl;
        push(data);
    }
    file.close();
}


//int Stack::countAdjacentEqual() {
//    int count = 0;
//    Node* current = top;
//    while (current && current->next && current->next->next) {
//        if (current->data == current->next->data /*&& current->data == current->next->next->data*/) {
//            count++;
//            std::cout << "Элементы с равными соседями: " << current->data << ", " << current->next->data << ", " << current->next->next->data << std::endl;
//        }
//        current = current->next;
//    }
//    return count;
//}
//int sosedi(Stack* fp)
//int Stack::countAdjacentEqual() {
//   
//    Node* current = top;
//        Node* next1 = current->next; // Указатель на следующий элемент стека.
//        if (current == NULL || next1 == NULL || next1->next == NULL || next1->next->next == NULL) // Проверяем, что стек содержит как минимум три элемента.
//            return 0; // Если условие не выполнено, возвращаем 0, так как невозможно определить соседей.
//        int count = 0; // Инициализируем счетчик для подсчета соседей.
//        while (next1->next != nullptr) { // Пока не достигнут конец стека:
//            if (current->data == next1->data && next1->data == next1->next->data) // Проверяем, равны ли текущий элемент и его соседи.
//                count++; // Увеличиваем счетчик на единицу, если соседи равны текущему элементу.
//            current = current->next; // Переходим к следующему элементу стека.
//            next1 = current->next; // Обновляем указатель на следующий элемент стека.
//        }
//        return count; // Возвращаем количество найденных соседей.
//    }
    

int Stack::countAdjacentEqual() {
    int count=0;
    Node* current = top;
    while (current && current->next->next) {
        if (current->data == current->next->next->data) {
            count++;
        }
        current = current->next;
    }
    return count;
}


int Stack::countElements() {
    int count = 0;
    Node* current = top;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
