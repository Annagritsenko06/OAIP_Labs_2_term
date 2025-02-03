#include <iostream>
#include "myStack.h"
#include <Windows.h>
using namespace std;

//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int choice; char x;
//	Stack* myStk = new Stack; //��������� ������ ��� �����
//	myStk = NULL;             //������������� ������� ��������	
//	for (;;)
//	{
//		cout << "�������� �������:" << endl;
//		cout << "1 - ���������� �������� � ����" << endl;
//		cout << "2 - ���������� �������� �� �����" << endl;
//		cout << "3 - ������ � ����" << endl;
//		cout << "4 - ������ �� �����" << endl;
//		cout << "5 - ����� ����� � ��������" << endl;
//		cout << "6 - �����" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "������� �������: " << endl;
//			cin >> x;
//			push(x, myStk); break;
//		case 2: x = pop(myStk);
//			if (x != -1)
//				cout << "����������� �������: " << x << endl;
//			break;
//		case 3: toFile(myStk);  break;
//		case 4: fromFile(myStk); break;
//		case 5: cout << "���� ����: " << endl;
//			show(myStk); break;
//		case 6: return 0; break;
//		}
//	}
//	return 0;
//}
//int main() {
//    SetConsoleCP(1251); // ������������� ��������� ����� ��� �������.
//    SetConsoleOutputCP(1251); // ������������� ��������� ������ ��� �������.
//
//    char x, choice; // ��������� ���������� ��� ����� �������� � ������ ������������.
//    int temp; // ��������������� ���������� ��� �������� ���������� �������.
//    MYSTACK* first = new MYSTACK; // ������� ��������� �� ������ ������� ����� � �������������� ��� ��������� nullptr.
//    first = NULL; // ������������� ��������� �� nullptr, ����� ���������� ������ ����.
//
//    //menu(); // ������� ���� �� �����.
//
//    while (1) { // ����������� ���� ������ ���������.
//
//        menu(); // ������� ���� �� �����.
//        cout << "\nmode : "; // ������� ����������� ��� ����� ������ ������.
//        cin >> choice; // �������� ����� ������������.
//
//        switch (choice) { // ������������ ����� ������������.
//
//        case '1': // ���� ������������ ������ 1:
//            cout << "������� ������� "; // ������ ������������ ������ �������.
//            cin >> x; // �������� ������� �� ������������.
//            push(first, x); // �������� ������� ��� ���������� �������� � ����.
//            cout << "��������\n"; // ������� ��������� � ���������� ��������.
//            break; // ��������� ���������� ����� case.
//
//        case '2': // ���� ������������ ������ 2:
//            x = pop(first); // ��������� ������� �� �����.
//            if (x != -1) // ���������, ������� �� ������� ������� �������.
//                cout << "����������� (��������� ) �������: " << x << endl; // ������� ����������� �������.
//            else
//                cout << "�� ������� ������� ������� " << endl; // �������� �� ������ ��� ���������� ��������.
//            break; // ��������� ���������� ����� case.
//
//        case '3': // ���� ������������ ������ 3:
//            view(first); // ������� ���������� ����� �� �����.
//            break; // ��������� ���������� ����� case.
//
//        case '4': // ���� ������������ ������ 4:
//            tofile(first); // ���������� ���������� ����� � ����.
//            break; // ��������� ���������� ����� case.
//
//        case '5': // ���� ������������ ������ 5:
//            fromfile(first); // ��������� ���������� ����� �� �����.
//            break; // ��������� ���������� ����� case.
//
//        case '6': // ���� ������������ ������ 6:
//            clear(first); // ������� ����.
//            break; // ��������� ���������� ����� case.
//
//        case '7': // ���� ������������ ������ 7:
//            temp = sosedi(first); // �������� ������� ��� �������� ���������� �������� ���������.
//            if (temp != 0) // ���� ���� ���������� �������� ��������:
//                cout << " ���������� ���������� ������� = " << temp << endl; // ������� ���������� ����� �������.
//            else
//                cout << " ������� ��� " << endl; // ����� ��������, ��� ������� ���.
//            break; // ��������� ���������� ����� case.
//
//        case 'h': // ���� ������������ ������ 'h':
//            menu(); // ������� ���� �� �����.
//            break; // ��������� ���������� ����� case.
//
//        case 'q': // ���� ������������ ������ 'q':
//            cout << "����� �� ���������... "; // ������� ��������� � ������ �� ���������.
//            return 0; // ��������� ���������.
//            break; // ��������� ���������� ����� case.
//
//        default: // ���� ������������ ���� ������������ ��������:
//            cout << "������������ ��������. �������� ���-�� �� ������. " << endl; // �������� ������������ �� ������.
//            break; // ��������� ���������� ����� case.
//        }
//    }
//
//    return 0; // ���������� 0, �������� �� �������� ���������� ���������.
//}

//
//int main() {
//    SetConsoleCP(1251); // ������������� ��������� ����� ��� �������.
//        SetConsoleOutputCP(1251); // ������������� ��������� ������ ��� �������.


        void viewStack(Stack & stack) {
            Stack tempStack;
            std::cout << "�������� �����:" << std::endl;
            while (!stack.isEmpty()) {
                std::string data = stack.pop();
                std::cout << data << std::endl;
                tempStack.push(data);
            }
            while (!tempStack.isEmpty()) {
                stack.push(tempStack.pop());
            }
        }

        int main() {
            SetConsoleCP(1251); // ������������� ��������� ����� ��� �������.
            SetConsoleOutputCP(1251); // ������������� ��������� ������ ��� �������.
            Stack stack;
            int choice;
            std::string data;
            do {
                std::cout << "1. �������� ������� � ����\n";
                std::cout << "2. ������� ������� �� �����\n";
                std::cout << "3. ����������� �������� �����\n";
                std::cout << "4. �������� ����\n";
                std::cout << "5. ��������� ���� � ����\n";
                std::cout << "6. ��������� ���� �� �����\n";
                std::cout << "7. ���������� ���������� ��������� �� ��������\n";
                std::cout << "8. ���������� ���������� ��������� � �����\n";
                std::cout << "0. �����\n";
                std::cout << "�������� ��������: ";
                std::cin >> choice;

                switch (choice) {
                case 1:
                    std::cout << "������� ��������: ";
                    std::cin >> data;
                    stack.push(data);
                    break;
                case 2:
                    if (!stack.isEmpty()) {
                        std::cout << "����������� �������: " << stack.pop() << std::endl;
                    }
                    else {
                        std::cout << "���� ����" << std::endl;
                    }
                    break;
                case 3:
                    viewStack(stack);
                    break;
                case 4:
                    stack.clear();
                    std::cout << "���� ������" << std::endl;
                    break;
                case 5:
                    stack.saveToFile("stack.txt");
                    std::cout << "���� �������� � ����� stack.txt" << std::endl;
                    break;
                case 6:
                    stack.readFromFile("stack.txt");
                    std::cout << "���� �������� �� ����� stack.txt" << std::endl;
                    break;
                case 7:
                    std::cout << "���������� ��������� �� ��������: " << stack.countAdjacentEqual() << std::endl;
                    break;
                case 8:
                    std::cout << "���������� ��������� � �����: " << stack.countElements() << std::endl;
                    break;
                case 0:
                    std::cout << "����� �� ���������" << std::endl;
                    break;
                default:
                    std::cout << "�������� ����" << std::endl;
                }
            } while (choice != 0);

            return 0;
        }

