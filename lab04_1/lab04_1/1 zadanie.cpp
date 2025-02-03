#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

const int MAX_PRODUCTS = 1000;

struct Product {
    string name;
    double price;
    int quantity;
    int markupPercent;
} inventory[MAX_PRODUCTS];
int count = 0;
int currentSize = 0;
const string filename = "inventory.txt";
double deleteProductPrice;
double searchProductPrice;


void inputProduct() {
    
    if (currentSize < MAX_PRODUCTS) {

        cout << "Введите наименование товара: ";
        getline(cin, inventory[currentSize].name);
    try1:
        cout << "Введите цену товара: ";
        cin >> inventory[currentSize].price;
        cout << '\n';
        if (inventory[currentSize].price <= 0 || cin.fail() || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод!!!Ведите цену заново." << '\n';
            goto try1;
        }
        

    try2:
        cout << "Введите количество товара: ";
        cin >> inventory[currentSize].quantity;
        if (inventory[currentSize].quantity < 0 || cin.fail() || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод!!!Введите количество товара заново." << '\n';
            goto try2;
        }
    try3:
        cout << "Выберите процент торговой надбавки (5, 10, 15, 20, 25, 30): ";
        cin >> inventory[currentSize].markupPercent;
        if (cin.fail() || inventory[currentSize].markupPercent % 5 != 0 || inventory[currentSize].markupPercent < 0 || inventory[currentSize].markupPercent > 30 || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод!!!Введите процент торговой надбавки занаво." << '\n';
            goto try3;
        }
        cin.ignore();

        currentSize++;
    }
    else {
        cout << "Достигнуто максимальное количество товаров на складе." << endl;
    }

}

void displayProduct(Product& product) {
    cout << "------------------------" << endl;
    cout << "Наименование: " << product.name << endl;
    cout << "Цена: " <<setprecision(13)<< product.price << endl;
    cout << "Количество: " << product.quantity << endl;
    cout << "Торговая надбавка: " << product.markupPercent << "%" << endl;
    cout << "------------------------" << endl;
}


void displayAllProducts() {
    cout << "Сейчас будут выведены все товары: " <<  endl;
    cout << "Всего товаров на складе: " << currentSize << endl;
    for (int i = 0; i < currentSize; ++i) {
        displayProduct(inventory[i]);
    }
}

void searchProduct() {
tr:
    cout << "Введите цену товара для поиска: ";
    cin >> searchProductPrice;
    if (searchProductPrice < 0 ||  cin.get() != '\n' || cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Попробуйте ввести еще раз." << '\n';

        goto tr;
    }

    for (int i = 0; i < currentSize; ++i) {
        if (inventory[i].price == searchProductPrice) {
            displayProduct(inventory[i]);
            return;
        }
    }
    cout << "Товар не найден." << endl;
}


void writeToFile() {
    ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < currentSize; ++i) {
            file << inventory[i].name;
           file << '\n';
           file << setprecision(13) << inventory[i].price << " "
               << inventory[i].quantity << " " << inventory[i].markupPercent <<endl;
        }
        file.close();
        cout << "Данные записаны в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
    file.close();
}


void readFromFile() {
    ifstream file(filename);
    int count = 0;

    if (file.is_open()) {
        cout << "Начинаю чтение из файла!!!!" << endl;
        do {
            getline(file, inventory[count].name);
            if (inventory[count].name == "") {
               // cout << "********" << inventory[count].name<< endl;
                break;
            }
  
            file>> inventory[count].price
                >> inventory[count].quantity >> inventory[count].markupPercent;
                count++;
                getline(file, inventory[count].name);
        } while (!file.eof());
        
        file.close();
        cout << "Данные загружены из файла." << endl;
       
        
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
   file.close();
    currentSize = count;
    displayAllProducts();
}

void deleteProduct() {
    number:
    cout << "Введите цену товара, который хотите удалить: ";
    cin >> deleteProductPrice;
    if (searchProductPrice < 0 || cin.get() != '\n' || cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Попробуйте ввести еще раз." << '\n';

        goto number;
    }
    for (int i = 0; i < currentSize; ++i) {
        if (inventory[i].price == deleteProductPrice) {
            for (int j = i; j < currentSize - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            currentSize--;
            cout << "Товар удален." << endl;
            displayAllProducts();
            writeToFile();
            return;
        }
    }
    cout << "Товар не найден." << endl;
}

int main() {
 
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        cout << "1-ввод элемента структуры\n"
            << "2-вывод элементов структуры\n"
            << "3-удаление товара\n"
            << "4-поиск товара по цене\n"
            << "5-запись информации в файл\n"
            << "6-чтение данных из файла\n"
            << "0-для выхода из программы\n"
            << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        if (choice < 0) {
            cout << "Некорректный ввод!!!" << '\n';
            break;
        }
        switch (choice) {
        case 1:
            inputProduct();
            break;
        case 2:
            displayAllProducts();
            break;
        case 3:
            deleteProduct();
            break;
        case 4:
            searchProduct();
            break;
        case 5:
            writeToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}



