#include <iostream>
#include "myStack.h"
#include <Windows.h>
using namespace std;

//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int choice; char x;
//	Stack* myStk = new Stack; //выделение памяти для стека
//	myStk = NULL;             //инициализация первого элемента	
//	for (;;)
//	{
//		cout << "Выберите команду:" << endl;
//		cout << "1 - Добавление элемента в стек" << endl;
//		cout << "2 - Извлечение элемента из стека" << endl;
//		cout << "3 - Запись в файл" << endl;
//		cout << "4 - Чтение из файла" << endl;
//		cout << "5 - Вывод стека с очисткой" << endl;
//		cout << "6 - Выход" << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите элемент: " << endl;
//			cin >> x;
//			push(x, myStk); break;
//		case 2: x = pop(myStk);
//			if (x != -1)
//				cout << "Извлеченный элемент: " << x << endl;
//			break;
//		case 3: toFile(myStk);  break;
//		case 4: fromFile(myStk); break;
//		case 5: cout << "Весь стек: " << endl;
//			show(myStk); break;
//		case 6: return 0; break;
//		}
//	}
//	return 0;
//}
//int main() {
//    SetConsoleCP(1251); // Устанавливаем кодировку ввода для консоли.
//    SetConsoleOutputCP(1251); // Устанавливаем кодировку вывода для консоли.
//
//    char x, choice; // Объявляем переменные для ввода символов и выбора пользователя.
//    int temp; // Вспомогательная переменная для хранения результата функции.
//    MYSTACK* first = new MYSTACK; // Создаем указатель на первый элемент стека и инициализируем его значением nullptr.
//    first = NULL; // Устанавливаем указатель на nullptr, чтобы обозначить пустой стек.
//
//    //menu(); // Выводим меню на экран.
//
//    while (1) { // Бесконечный цикл работы программы.
//
//        menu(); // Выводим меню на экран.
//        cout << "\nmode : "; // Выводим приглашение для ввода режима работы.
//        cin >> choice; // Получаем выбор пользователя.
//
//        switch (choice) { // Обрабатываем выбор пользователя.
//
//        case '1': // Если пользователь выбрал 1:
//            cout << "Введите элемент "; // Просим пользователя ввести элемент.
//            cin >> x; // Получаем элемент от пользователя.
//            push(first, x); // Вызываем функцию для добавления элемента в стек.
//            cout << "Добавлен\n"; // Выводим сообщение о добавлении элемента.
//            break; // Завершаем выполнение блока case.
//
//        case '2': // Если пользователь выбрал 2:
//            x = pop(first); // Извлекаем элемент из стека.
//            if (x != -1) // Проверяем, успешно ли удалось извлечь элемент.
//                cout << "Извлеченный (удаленный ) элемент: " << x << endl; // Выводим извлеченный элемент.
//            else
//                cout << "Не удалось извлечь элемент " << endl; // Сообщаем об ошибке при извлечении элемента.
//            break; // Завершаем выполнение блока case.
//
//        case '3': // Если пользователь выбрал 3:
//            view(first); // Выводим содержимое стека на экран.
//            break; // Завершаем выполнение блока case.
//
//        case '4': // Если пользователь выбрал 4:
//            tofile(first); // Записываем содержимое стека в файл.
//            break; // Завершаем выполнение блока case.
//
//        case '5': // Если пользователь выбрал 5:
//            fromfile(first); // Считываем содержимое стека из файла.
//            break; // Завершаем выполнение блока case.
//
//        case '6': // Если пользователь выбрал 6:
//            clear(first); // Очищаем стек.
//            break; // Завершаем выполнение блока case.
//
//        case '7': // Если пользователь выбрал 7:
//            temp = sosedi(first); // Вызываем функцию для подсчета одинаковых соседних элементов.
//            if (temp != 0) // Если есть одинаковые соседние элементы:
//                cout << " Количество одинаковых соседей = " << temp << endl; // Выводим количество таких соседей.
//            else
//                cout << " Соседей нет " << endl; // Иначе сообщаем, что соседей нет.
//            break; // Завершаем выполнение блока case.
//
//        case 'h': // Если пользователь выбрал 'h':
//            menu(); // Выводим меню на экран.
//            break; // Завершаем выполнение блока case.
//
//        case 'q': // Если пользователь выбрал 'q':
//            cout << "Выход из программы... "; // Выводим сообщение о выходе из программы.
//            return 0; // Завершаем программу.
//            break; // Завершаем выполнение блока case.
//
//        default: // Если пользователь ввел некорректное значение:
//            cout << "Некорректное значение. Выберете что-то из списка. " << endl; // Сообщаем пользователю об ошибке.
//            break; // Завершаем выполнение блока case.
//        }
//    }
//
//    return 0; // Возвращаем 0, указывая на успешное завершение программы.
//}

//
//int main() {
//    SetConsoleCP(1251); // Устанавливаем кодировку ввода для консоли.
//        SetConsoleOutputCP(1251); // Устанавливаем кодировку вывода для консоли.


        void viewStack(Stack & stack) {
            Stack tempStack;
            std::cout << "Элементы стека:" << std::endl;
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
            SetConsoleCP(1251); // Устанавливаем кодировку ввода для консоли.
            SetConsoleOutputCP(1251); // Устанавливаем кодировку вывода для консоли.
            Stack stack;
            int choice;
            std::string data;
            do {
                std::cout << "1. Добавить элемент в стек\n";
                std::cout << "2. Извлечь элемент из стека\n";
                std::cout << "3. Просмотреть элементы стека\n";
                std::cout << "4. Очистить стек\n";
                std::cout << "5. Сохранить стек в файл\n";
                std::cout << "6. Загрузить стек из файла\n";
                std::cout << "7. Подсчитать количество элементов со соседями\n";
                std::cout << "8. Подсчитать количество элементов в стеке\n";
                std::cout << "0. Выход\n";
                std::cout << "Выберите действие: ";
                std::cin >> choice;

                switch (choice) {
                case 1:
                    std::cout << "Введите значение: ";
                    std::cin >> data;
                    stack.push(data);
                    break;
                case 2:
                    if (!stack.isEmpty()) {
                        std::cout << "Извлеченный элемент: " << stack.pop() << std::endl;
                    }
                    else {
                        std::cout << "Стек пуст" << std::endl;
                    }
                    break;
                case 3:
                    viewStack(stack);
                    break;
                case 4:
                    stack.clear();
                    std::cout << "Стек очищен" << std::endl;
                    break;
                case 5:
                    stack.saveToFile("stack.txt");
                    std::cout << "Стек сохранен в файле stack.txt" << std::endl;
                    break;
                case 6:
                    stack.readFromFile("stack.txt");
                    std::cout << "Стек загружен из файла stack.txt" << std::endl;
                    break;
                case 7:
                    std::cout << "Количество элементов со соседями: " << stack.countAdjacentEqual() << std::endl;
                    break;
                case 8:
                    std::cout << "Количество элементов в стеке: " << stack.countElements() << std::endl;
                    break;
                case 0:
                    std::cout << "Выход из программы" << std::endl;
                    break;
                default:
                    std::cout << "Неверный ввод" << std::endl;
                }
            } while (choice != 0);

            return 0;
        }

