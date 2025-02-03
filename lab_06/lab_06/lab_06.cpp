#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
// Определение структуры узла списка
struct Node {
    int data;   // Данные, хранящиеся в узле
    Node* next; // Указатель на следующий узел в списке

};

// Функция для добавления элемента в начало списка
void insert(Node*& head, double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// Функция для вывода списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


void deleteElement(Node*& head, int value) {
    if (head == nullptr) {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Если удаляемый элемент находится в голове списка
    if (temp != nullptr && temp->data == value) {
        head = temp->next; // Изменяем голову списка
        delete temp;       // Освобождаем память удаляемого узла
        std::cout << "Элемент удален." << std::endl;
        return;
    }

    // Ищем удаляемый элемент, сохраняя предыдущий узел
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Если элемент не найден
    if (temp == nullptr) {
        std::cout << "Элемент не найден." << std::endl;
        return;
    }

    // Удаляем элемент из списка
    prev->next = temp->next;
    delete temp; // Освобождаем память удаляемого узла
    std::cout << "Элемент удален." << std::endl;
}

// Функция для поиска элемента в списке
void findElement(Node* head, int value) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == value) {
            std::cout << "Элемент со значением " << value << " найден на позиции " << position << "." << std::endl;
            return;
        }
        current = current->next;
        position++;
    }
    std::cout << "Элемент со значением " << value << " не найден в списке." << std::endl;
}

void writeListToFile(Node* head, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }

    file.close();
    std::cout << "Список успешно записан в файл." << std::endl;
}
int negativeSum(Node* pointer) {
    if (pointer == NULL) // Если список пуст, возвращаем 0.
        return 0;
    else {
        int sum = 0; // Инициализируем переменную для хранения суммы.
        while (pointer != NULL) { // Проходим по всему списку.
            if (pointer->data > -100 && pointer->data < -9) // Если элемент списка является положительным двузначным числом:
                sum += pointer->data; // Добавляем его к сумме.
            pointer = pointer->next; // Переходим к следующему элементу списка.
        }
        return sum; // Возвращаем вычисленную сумму.
    }
}

// Прототипы функций для меню
void addElement(Node*& head);
void deleteElement(Node*& head, int value);
void findElement(Node* head, int value);
void writeListToFile(Node* head, const std::string& filename);
void readListFromFile(Node*& head, const std::string& filename);
int sumOfNegativeMultiplesOfFive(Node* head);

// Функция для добавления элемента через меню
void addElement(Node*& head) {
    int value;
    while (true) {
        std::cout << "Введите целое число для добавления: ";
        std::cin >> value;

        if (std::cin.fail()) { // Проверяем, не произошла ли ошибка ввода
            std::cin.clear(); // Очищаем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем некорректный ввод до следующего перевода строки
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшийся ввод после числа
            if (std::cin.gcount() > 1) { // Проверяем, были ли введены лишние символы после числа
                std::cout << "Введено не только целое число. Попробуйте снова.\n";
            }
            else {
                break; // Ввод корректен, выходим из цикла
            }
        }
    }

    insert(head, value); // Добавляем элемент в список
}

// Функция для чтения списка из файла
Node* readListFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return nullptr;
    }

    Node* head = nullptr;
    Node* current = nullptr;
    int value;

    while (file >> value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            current = head;
        }
        else {
            current->next = newNode;
            current = newNode;
        }
    }

    file.close();
    std::cout << "Список успешно прочитан из файла и воссоздан." << std::endl;
    return head;
}

int menu()
{
    std::cout << "Меню:\n"
        << "1. Добавить элемент\n"
        << "2. Удалить элемент\n"
        << "3. Найти элемент\n"
        << "4. Вывести список\n"
        << "5. Записать список в файл\n"
        << "6. Считать список из файла\n"
        << "7. Найти сумму двузначных отрицательных элементов\n"
        << "0. Выход\n";


    char c[100];
    while (true)
    {
        cout << "выберите пункт меню: ";
        cin.getline(c, 100);

        bool validInput = true;
        for (int i = 0; i < strlen(c); ++i) {
            if (!isdigit(c[i])) {
                validInput = false;
                break;
            }
        }


        if (validInput && (strlen(c) == 1) && (c[0] >= '0' && c[0] <= '7'))
        {
            break;
        }
        /*else
        {
            cout << "------------------------------------" << endl;
        }*/
    }

    return atoi(c);
}

// Основная функция с меню
int main() {
    setlocale(LC_CTYPE, "rus");
    Node* head = nullptr; // Начало списка пусто
    int choice;
    int sum = 0;

    while (true)
    {
        int m = menu();
        switch (m) {
        case 1:
            addElement(head);
            break;
        case 2:
            int valueToDelete;
            std::cout << "Введите значение для удаления: ";
            std::cin >> valueToDelete;
            deleteElement(head, valueToDelete);
            break;
            // Здесь будет вызов функции для удаления элемента
            break;
        case 3:
            int valueToFind;
            std::cout << "Введите значение для поиска: ";
            std::cin >> valueToFind;
            findElement(head, valueToFind);
            break;
            // Здесь будет вызов функции для поиска элемента
            break;
        case 4:
            printList(head);
            break;
        case 5: {
            std::string filenameToWrite;
            std::cout << "Введите имя файла для записи: ";
            std::cin >> filenameToWrite;
            writeListToFile(head, filenameToWrite);
            break;
        }
              // Здесь будет вызов функции для записи списка в файл
              break;
        case 6: {
            std::string filenameToRead;
            std::cout << "Введите имя файла для чтения: ";
            std::cin >> filenameToRead;
            head = readListFromFile(filenameToRead);
            break; }
              // Здесь будет вызов функции для чтения списка из файла
              break;
        case 7:
            sum = negativeSum(head); // Используем уже объявленную переменную sum
            if (sum != 0) {
                std::cout << "Сумма двузначных отрицательных элементов: " << sum << std::endl;
            }
            else {
                std::cout << "Двузначных отрицательных элементов нет" << std::endl;
            }
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            return 0;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }


        // Освобождение памяти и очистка списка
        // ...
    }
    return 0;
}







//
//
//#include <iostream>
//#include <fstream>
//#include <iomanip> 
//#include <sstream> 
//#include <limits> 
//using namespace std;
//
//// Структура для односвязного списка
//struct Node {
//    int data;
//    Node* next;
//};
//
//// Функция для добавления элемента в начало списка
//void insert(Node*& head, int value) {
//    Node* newNode = new Node;
//    newNode->data = value;
//    newNode->next = head;
//    head = newNode;
//}
//
//// Функция для удаления элемента из списка
//void remove(Node*& head, int value) {
//    Node* current = head;
//    Node* prev = nullptr;
//
//    // Поиск элемента
//    while (current != nullptr && current->data != value) {
//        prev = current;
//        current = current->next;
//    }
//
//    // Если элемент найден, удаляем его
//    if (current != nullptr) {
//        if (prev != nullptr) {
//            prev->next = current->next;
//        }
//        else {
//            head = current->next;
//        }
//        delete current;
//    }
//    else {
//        cout << "Элемент " << value << " не найден в списке" << endl;
//    }
//}
//
//
//// Функция для вывода списка на консоль
//void printList(Node* head) {
//    if (head == NULL) {
//        cout << "Список пуст" << endl;
//    }
//    else {
//        cout << "Список:" << endl;
//        while (head != NULL) {
//            cout << "-->" << head->data;
//            head = head->next;
//        }
//        cout << "-->NULL" << endl;
//    }
//}
//
//// Функция для записи списка в файл
//void toFile(Node* head, const string& filename) {
//    ofstream file(filename);
//    if (!file) {
//        cerr << "Ошибка открытия файла" << endl;
//        return;
//    }
//    while (head != nullptr) {
//        file << fixed << setprecision(2) << head->data << endl;
//        head = head->next;
//    }
//    cout << "Список записан в файл " << filename << endl;
//    file.close();
//}
//
//// Функция для чтения списка из файла
//void fromFile(Node*& head, const string& filename) {
//    ifstream file(filename);
//    if (!file) {
//        cerr << "Ошибка открытия файла" << endl;
//        return;
//    }
//
//    // Освобождаем память, выделенную под старый список
//    while (head != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    int value;
//    while (file >> value) {
//        insert(head, value);
//    }
//    cout << "Список считан из файла " << filename << endl;
//    file.close();
//}
//
//// Функция для поиска элемента в списке и вывода его номера
//void search(Node* head, int value) {
//    int index = 1;
//    while (head != nullptr) {
//        if (head->data == value) {
//            cout << "Элемент " << value << " найден на позиции " << index << endl;
//            return;
//        }
//        head = head->next;
//        index++;
//    }
//    cout << "Элемент " << value << " не найден в списке" << endl;
//}
//
//// Функция для вычисления суммы положительных двузначных элементов списка
//int negativeSum(Node* pointer) {
//    if (pointer == NULL) // Если список пуст, возвращаем 0.
//        return 0;
//    else {
//        int sum = 0; // Инициализируем переменную для хранения суммы.
//        while (pointer != NULL) { // Проходим по всему списку.
//            if (pointer->data > -100 && pointer->data < -9) // Если элемент списка является положительным двузначным числом:
//                sum += pointer->data; // Добавляем его к сумме.
//            pointer = pointer->next; // Переходим к следующему элементу списка.
//        }
//        return sum; // Возвращаем вычисленную сумму.
//    }
//}
//
//// Функция для вывода меню
//void menu() {
//    cout << "Сделайте выбор:" << endl;
//    cout << "1 - Добавить элемент" << endl;
//    cout << "2 - Удалить элемент" << endl;
//    cout << "3 - Вывести список" << endl;
//    cout << "4 - Записать список в файл" << endl;
//    cout << "5 - Считать список из файла" << endl;
//    cout << "6 - Поиск элемента" << endl;
//    cout << "7 - Найти сумму всех двузначных отрицательных элементов списка" << endl;
//    cout << "8 - Выход" << endl;
//}
//
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    Node* head = nullptr;
//    int choice;
//    int value;
//
//    menu();
//    while (!(cin >> choice)) {
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << "Ошибка ввода. Введите число от 1 до 8: ";
//    }
//
//    while (choice != 8) {
//        switch (choice) {
//        case 1:
//            cout << "Введите элемент: ";
//
//            cin >> value;
//            if (cin.fail() || cin.get() != '\n') {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Ошибка ввода. Введите целое число: ";
//                continue;
//            }
//            insert(head, value);
//            break;
//        case 2:
//            cout << "Введите элемент, который хотите удалить: ";
//            while (!(cin >> value)) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Ошибка ввода. Введите целое число: ";
//            }
//            remove(head, value);
//            printList(head);
//            break;
//        case 3:
//            printList(head);
//            break;
//        case 4:
//            toFile(head, "list.txt");
//            break;
//        case 5:
//            fromFile(head, "list.txt");
//            printList(head);
//            break;
//        case 6:
//            cout << "Введите элемент, который хотите найти: ";
//            while (!(cin >> value)) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Ошибка ввода. Введите целое число: ";
//            }
//            search(head, value);
//            break;
//        case 7:
//            cout << "Сумма положительных двузначных элементов: " << negativeSum(head) << endl;
//            break;
//        default:
//            cout << "Неправильный выбор" << endl;
//            break;
//        }
//        menu();
//        while (!(cin >> choice)) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Ошибка ввода. Введите число от 1 до 8: ";
//        }
//    }
//
//    // Освобождаем память, выделенную под список
//    while (head != nullptr) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    return 0;
//}
//
