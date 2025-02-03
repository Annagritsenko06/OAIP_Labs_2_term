#include "MyQueue.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int n; //���� ������ �������

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int razmer = 0;
    int x;// ��������� ����������
    Node* start = NULL, * end = NULL;
    Node* t; //������� ��������� 

    cout << "������� ������ �������: " << endl;
    cin >> n;
    /*cout << "������� �������� 1 ��������: " << endl;
    cin >> x;
    t = new Node;
    t->el = x;
    t->next = NULL;

    start = end = t;

    for (int i = 1; i < n; i++) {

        cout << "������� �������� " << i + 1 << " ��������: " << endl;
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
        cout << "�������� ����� ������ � ����������" << endl;
        cout << "1 - ����� ��������� �������" << endl;
        cout << "2 - ���������� ������ �������� (���� � ����������) " << endl;
        cout << "3 - �������� �������� �������" << endl;
        cout << "4 - ������ ������� " << endl;
        cout << "5 - ����� ��������� ������� �� ������� ��������(������������ � �������) " << endl;
        cout << "6 - ������������ ������� �������" << endl;
        cout << "0 - ����� �� ��������� " << endl;
        cout << endl;
        
        cin >> choice;
        switch (choice) {
        case '1': {

            view(start);
            break; }
        case '2': {
            razmer = queue_length(start, end);
            e:
            cout << "������� �������� ������������ ��������: " << endl;
        
            cin >> x;
            if (cin.fail() || cin.get() != '\n') { // ���������, �� ��������� �� ������ �����
                std::cin.clear(); // ������� ���� ������
                std::cin.ignore((32678), '\n'); // ���������� ������������ ���� �� ���������� �������� ������
                std::cout << "������������ ����. ����������, ������� ����� �����.\n";
                goto e;
            }
            if (razmer >= n) {
                cout << "�������� ������ �������!!!!! " << endl;
                break;
            }
            else add_el_to_queue(start, end, x);
            break; }
        case '3': {

            cout << "��������� ������� = " << del(start, end) << endl;
            break;
        }
        case '4': {
            cout << "������ ������� = " << queue_length(start, end) << endl;
            break;
        }
        case '5': {
            find_zero(start, end);
            
            break;
        }
        case '6': {
            cout << "������������ ������� ������� = " << max_queue(start) << endl;
            break;
        }
       
        case '0': {
            cout << "����� �� ���������... ";
            return 0;
        }
        default: {
            cout << "������������ ��������. �������� ���-�� �� ������." << endl;
            break;
        }
        }
    }

    return 0;
}

