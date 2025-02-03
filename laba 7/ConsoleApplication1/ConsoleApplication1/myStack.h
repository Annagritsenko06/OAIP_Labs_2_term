#pragma once
//struct Stack
//{
//	char data;     //�������������� �������
//	Stack* next;	 //��������� �� ��������� �������
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
//    char x; // ���������� �������� �������� �����.
//    MYSTACK* p; // ��������� �� ��������� ������� �����.
//};
//
//void menu(void); // ������� ��� ������ ����.
//void push(MYSTACK*& fp, char y); // ������� ��� ���������� �������� � ����.
//int pop(MYSTACK*& fp); // ������� ��� ���������� �������� �������� �� �����.
//void view(MYSTACK* fp); // ������� ��� ������ �������� ��������� �����.
//void tofile(MYSTACK* fp); // ������� ��� ������ ����� � ����.
//void fromfile(MYSTACK*& first); // ������� ��� ���������� ����� �� �����.
//void clear(MYSTACK*& fp); // ������� ��� ������� �����.
//int sosedi(MYSTACK* fp); // ������� ��� �������� ���������� ��������� � ����� � ����������� ��������.
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
    Stack();  // �����������
    ~Stack(); // ����������
    void push(const std::string& data); // ���������� �������� � ����
    std::string pop(); // ���������� �������� �� �����
    bool isEmpty(); // �������� �� �������
    void clear(); // ������� �����
    void saveToFile(const char* filename); // ���������� � ����
    void readFromFile(const char* filename); // ���������� �� �����
    int countAdjacentEqual(); // ������� ���������� ��������� �� ��������
    int countElements(); // ������� ���������� ��������� � �����
};

#endif
