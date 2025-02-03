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

    for (;;) // ����������� ����
    {
        cout << "1 - �������� ������� � ���� 1" << endl; // ����� ���� ��������
        cout << "2 - ����� ���� 1 �� �����" << endl;
        cout << "3 - �������� ������������� �� ���� 1" << endl;
        cout << "4 - �������� ������������ �� ���� 1" << endl;
        cout << "5 - �������� i-��� �������� �� ���� 1" << endl;
        cout << "6 - ����������� ���� ��� � ����" << endl;
        cout << "7 - �������� ������� � ���� 2" << endl;
        cout << "8 - ����� ���� 2 �� �����" << endl;
        cout << "9 - �������� ������������� �� ���� 2" << endl;
        cout << "10 - �������� ������������ �� ���� 2" << endl;
        cout << "11 - �������� i-��� �������� �� ���� 2" << endl;
        cout << "0 - �����" << endl;
        cout << "��� ���� �������?" << endl;
        cin >> choise; 
        switch (choise) 
        {
        case 0: exit(0); 
        case 1: 
            a = new AAA; 
            cout << "������� ������� " << endl; 
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
                cout << "������������ �������: " << a->x << endl; 
                h1.Scan(0); 
            }
            else cout << "���� �����." << endl; 
            break;
        case 4:
            a = (AAA*)h1.ExtractMin(); 
            if (a != NULL) 
            {
                cout << "����������� �������: " << a->x << endl; 
                h1.Scan(0); 
            }
            else cout << "���� �����." << endl; 
            break;
        case 5: 
            cout << "������� ����� �������� " << endl; 
            cin >> choise; 
            a = (AAA*)h1.ExtractI(choise); 
            if (a != NULL) 
            {
                cout << "����������� �������: " << a->x << endl; 
                h1.Scan(0);
            }
            else cout << "���� �����." << endl; 
        case 6: 
            h1.Merge(h2); 
            h1.Scan(0);
            break;
        case 7:
            b = new AAA;
            cout << "������� ������� " << endl; 
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
                cout << "������������ �������: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "���� �����." << endl; 
            break;
        case 10: 
            aa = (AAA*)h2.ExtractMin();
            if (aa != NULL) 
            {
                cout << "����������� �������: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "���� �����." << endl; 
            break;
        case 11: 
            cout << "������� ����� �������� " << endl; 
            cin >> choise; 
            aa = (AAA*)h2.ExtractI(choise); 
            if (aa != NULL) 
            {
                cout << "����������� �������: " << aa->x << endl; 
                h2.Scan(0); 
            }
            else cout << "���� �����." << endl; 
            break;
        
        default:
            cout << endl << "������� �������� �������" << endl; // ����� ��������� � �������� �������
            cout << endl;
        }
    }
}

