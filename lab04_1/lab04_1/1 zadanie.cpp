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

        cout << "������� ������������ ������: ";
        getline(cin, inventory[currentSize].name);
    try1:
        cout << "������� ���� ������: ";
        cin >> inventory[currentSize].price;
        cout << '\n';
        if (inventory[currentSize].price <= 0 || cin.fail() || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "������������ ����!!!������ ���� ������." << '\n';
            goto try1;
        }
        

    try2:
        cout << "������� ���������� ������: ";
        cin >> inventory[currentSize].quantity;
        if (inventory[currentSize].quantity < 0 || cin.fail() || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "������������ ����!!!������� ���������� ������ ������." << '\n';
            goto try2;
        }
    try3:
        cout << "�������� ������� �������� �������� (5, 10, 15, 20, 25, 30): ";
        cin >> inventory[currentSize].markupPercent;
        if (cin.fail() || inventory[currentSize].markupPercent % 5 != 0 || inventory[currentSize].markupPercent < 0 || inventory[currentSize].markupPercent > 30 || cin.get() != '\n') {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "������������ ����!!!������� ������� �������� �������� ������." << '\n';
            goto try3;
        }
        cin.ignore();

        currentSize++;
    }
    else {
        cout << "���������� ������������ ���������� ������� �� ������." << endl;
    }

}

void displayProduct(Product& product) {
    cout << "------------------------" << endl;
    cout << "������������: " << product.name << endl;
    cout << "����: " <<setprecision(13)<< product.price << endl;
    cout << "����������: " << product.quantity << endl;
    cout << "�������� ��������: " << product.markupPercent << "%" << endl;
    cout << "------------------------" << endl;
}


void displayAllProducts() {
    cout << "������ ����� �������� ��� ������: " <<  endl;
    cout << "����� ������� �� ������: " << currentSize << endl;
    for (int i = 0; i < currentSize; ++i) {
        displayProduct(inventory[i]);
    }
}

void searchProduct() {
tr:
    cout << "������� ���� ������ ��� ������: ";
    cin >> searchProductPrice;
    if (searchProductPrice < 0 ||  cin.get() != '\n' || cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "������������ ����!!!���������� ������ ��� ���." << '\n';

        goto tr;
    }

    for (int i = 0; i < currentSize; ++i) {
        if (inventory[i].price == searchProductPrice) {
            displayProduct(inventory[i]);
            return;
        }
    }
    cout << "����� �� ������." << endl;
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
        cout << "������ �������� � ����." << endl;
    }
    else {
        cout << "������ �������� �����." << endl;
    }
    file.close();
}


void readFromFile() {
    ifstream file(filename);
    int count = 0;

    if (file.is_open()) {
        cout << "������� ������ �� �����!!!!" << endl;
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
        cout << "������ ��������� �� �����." << endl;
       
        
    }
    else {
        cout << "������ �������� �����." << endl;
    }
   file.close();
    currentSize = count;
    displayAllProducts();
}

void deleteProduct() {
    number:
    cout << "������� ���� ������, ������� ������ �������: ";
    cin >> deleteProductPrice;
    if (searchProductPrice < 0 || cin.get() != '\n' || cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "������������ ����!!!���������� ������ ��� ���." << '\n';

        goto number;
    }
    for (int i = 0; i < currentSize; ++i) {
        if (inventory[i].price == deleteProductPrice) {
            for (int j = i; j < currentSize - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            currentSize--;
            cout << "����� ������." << endl;
            displayAllProducts();
            writeToFile();
            return;
        }
    }
    cout << "����� �� ������." << endl;
}

int main() {
 
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        cout << "1-���� �������� ���������\n"
            << "2-����� ��������� ���������\n"
            << "3-�������� ������\n"
            << "4-����� ������ �� ����\n"
            << "5-������ ���������� � ����\n"
            << "6-������ ������ �� �����\n"
            << "0-��� ������ �� ���������\n"
            << "�������� ��������: ";
        cin >> choice;
        cin.ignore();
        if (choice < 0) {
            cout << "������������ ����!!!" << '\n';
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
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}



