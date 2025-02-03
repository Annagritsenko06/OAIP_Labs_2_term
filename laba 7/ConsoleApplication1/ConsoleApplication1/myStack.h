#pragma once
//struct Stack
//{
//	char data;     //информационный элемент
//	Stack* next;	 //указатель на следующий элемент
//};
//void show(Stack*& myStk);
//char pop(Stack*& myStk);
//void push(char x, Stack*& myStk);
//void toFile(Stack*& myStk);
//void fromFile(Stack*& myStk);
//#pragma once
//
//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <fstream>
//using namespace std;
//
//struct MYSTACK {
//    char x; // Символьное значение элемента стека.
//    MYSTACK* p; // Указатель на следующий элемент стека.
//};
//
//void menu(void); // Функция для вывода меню.
//void push(MYSTACK*& fp, char y); // Функция для добавления элемента в стек.
//int pop(MYSTACK*& fp); // Функция для извлечения верхнего элемента из стека.
//void view(MYSTACK* fp); // Функция для вывода текущего состояния стека.
//void tofile(MYSTACK* fp); // Функция для записи стека в файл.
//void fromfile(MYSTACK*& first); // Функция для считывания стека из файла.
//void clear(MYSTACK*& fp); // Функция для очистки стека.
//int sosedi(MYSTACK* fp); // Функция для подсчета количества элементов в стеке с одинаковыми соседями.
//
//
#ifndef STACK_H
#define STACK_H

#include <string>

struct Node {
    std::string data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack();  // конструктор
    ~Stack(); // деструктор
    void push(const std::string& data); // добавление элемента в стек
    std::string pop(); // извлечение элемента из стека
    bool isEmpty(); // проверка на пустоту
    void clear(); // очистка стека
    void saveToFile(const char* filename); // сохранение в файл
    void readFromFile(const char* filename); // считывание из файла
    int countAdjacentEqual(); // подсчет количества элементов со соседями
    int countElements(); // подсчет количества элементов в стеке
};

#endif
