#include <iostream>
#include <Windows.h>
#include <cstring>
#include <string>
#include <fstream>
const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
#define len 100
int current_y = 2024;
int current_m = 4;
int current_d = 19;
using namespace std;
char inputFio[len];
// Объявление функций
void newContact();
void list();
void write();
void read();
void search();
bool checkfio(string f);
// Структура для хранения данных контакта
union datas
{
    char datach[len];
    unsigned  datanum;
    double datasalary;
}un_book;

struct Contact
{
    datas name;
    datas sername;
    datas middle_name;
    datas birthDay;
    datas birthMonth;
    datas birthYear;
    datas address;
    datas phoneNumber;
    datas place;
     datas jobtitle;
    datas salary;
};

// Константа для максимального количества контактов
const int MAX_CONTACTS_COUNT = 7;
int contacts_count = 0;
Contact contacts_list[MAX_CONTACTS_COUNT];

// Основная функция
int main()
{
    // Установка кодировки для корректного отображения на кириллице
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    // Основной цикл программы
    do
    {
        
        cout << "Выберите действие:" << endl
            << "1 - Ввести данные о работнике" << endl
            << "2 - отобразить все данные о работниках" << endl
            << "3 - записать данные в файл" << endl
            << "4 - поиск по должности" << endl
            << "5 - прочитать данные из файла" << endl
            << "6 - выход из программы" << endl;
            

        // Считывание выбора пользователя
        cin >> choice;

        // Обработка выбора
        switch (choice)
        {
        case 1:
            newContact();
            break;
        case 2:
            list();
            break;
        case 3:
            write();
            break;
        case 4:
            search();
            break;
        case 5:
            read();
            break;
        case 6:
            cout << "Выход из программы..." << endl;
            system("pause");
            break;
        }
    } while (choice != 6);
}
bool check(string f){
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }
    for (int i = 0; i < f.length(); i++) {
         if ((f[i] >= '0' && f[i] <= '9') /*|| (f[i] >= 'а' && f[i] <= 'я')*/) {
            /*if (f[i - 1] == '-') {
                return 0;
            }*/
             return 0;
        }
        
        else {
           
            continue;
        }
    }
    return 1;

}
bool checkfio(string f) {
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }
    for (int i = 0; i < f.length(); i++) {
        if (i == 0) {
            if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= 'А' && f[0] <= 'Я')) {
                t = true;
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'А' && f[i] <= 'Я') && t) {
            if (f[i - 1] == '-') {
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= 'а' && f[i] <= 'я')) {
            if (f[i - 1] == '-') {
                return 0;
            }
            continue;
        }
        else if (f[i] == '-') {
            continue;
        }
        else {
            return 0;
        }
    }
    return 1;
}
// Функция для добавления нового контакта
void newContact()
{
    // Проверка на максимальное количество контактов
    if (contacts_count == MAX_CONTACTS_COUNT)
    {
        cout << "Вы ввели максимальное кол-во работников" << endl;
        return;
    }

    cin.ignore();
    bool validInput = true;
    do {
        
        printf("Введите Имя: ");
        a:
        gets_s(contacts_list[contacts_count].name.datach, sizeof(contacts_list[contacts_count].name.datach));
        // Убираем символ новой строки в конце ввода
        contacts_list[contacts_count].name.datach[strcspn(contacts_list[contacts_count].name.datach, "\n")] = '\0';
        validInput = checkfio(contacts_list[contacts_count].name.datach);
      
        if (!validInput) {
            printf("Имя введено некорректно.Введите еще раз!!!\n");
            goto a;
        }
        else
            break;
    } while (validInput);
    validInput = true;
    do {

        printf("Введите фамилию: ");
    b:
        gets_s(contacts_list[contacts_count].sername.datach, sizeof(contacts_list[contacts_count].sername.datach));
        // Убираем символ новой строки в конце ввода
        contacts_list[contacts_count].sername.datach[strcspn(contacts_list[contacts_count].sername.datach, "\n")] = '\0';
        validInput = checkfio(contacts_list[contacts_count].sername.datach);

        if (!validInput) {
            printf("Фамилия введено некорректно.Введите еще раз!!!\n");
            goto b;
        }
        else
            break;
    } while (validInput);
    validInput = true;
    do {

        printf("Введите Отчество: ");
    c:
        gets_s(contacts_list[contacts_count].middle_name.datach, sizeof(contacts_list[contacts_count].middle_name.datach));
        // Убираем символ новой строки в конце ввода
        contacts_list[contacts_count].middle_name.datach[strcspn(contacts_list[contacts_count].middle_name.datach, "\n")] = '\0';
        validInput = checkfio(contacts_list[contacts_count].middle_name.datach);

        if (!validInput) {
            printf("Отчество введено некорректно.Введите еще раз!!!\n");
            goto c;
        }
        else
            break;
    } while (validInput);
    do {
    cout << "Введите образование: ";
    d:
    gets_s(contacts_list[contacts_count].address.datach, sizeof(contacts_list[contacts_count].address.datach));
    contacts_list[contacts_count].address.datach[strcspn(contacts_list[contacts_count].address.datach, "\n")] = '\0';
    validInput = check(contacts_list[contacts_count].address.datach);

    if (!validInput) {
        printf("Поле образование введено некорректно.Введите еще раз!!!\n");
        goto d;
    }
    else
        break;
} while (validInput);
validInput = true;
do {
    cout << "Введите специальность: ";
    k:
    gets_s(contacts_list[contacts_count].phoneNumber.datach,sizeof(contacts_list[contacts_count].phoneNumber.datach) );
    contacts_list[contacts_count].phoneNumber.datach[strcspn(contacts_list[contacts_count].phoneNumber.datach, "\n")] = '\0';
    validInput = check(contacts_list[contacts_count].phoneNumber.datach);
    if (!validInput) {
        printf("Поле специальность введено некорректно.Введите еще раз!!!\n");
        goto k;
    }
    else
        break;
} while (validInput);
    cout << "Введите подразделение: ";
    gets_s(contacts_list[contacts_count].place.datach, 60);

    
    do{
    cout << "Введите должность: ";
    /*cin.get();
    cin.getline(un_book.datach, len);
    contacts_list[contacts_count].jobtitle = un_book.datach*/
    /*cin.getline(contacts_list[contacts_count].jobtitle.datach, 100);*/
i:
   
    
    gets_s(contacts_list[contacts_count].jobtitle.datach,sizeof(contacts_list[contacts_count].jobtitle.datach));
    contacts_list[contacts_count].jobtitle.datach[strcspn(contacts_list[contacts_count].jobtitle.datach, "\n")] = '\0';
    validInput = check(contacts_list[contacts_count].jobtitle.datach);
    if (!validInput) {
        printf("Поле должность введено некорректно.Введите еще раз!!!\n");
        goto i;
    }
    else
        break;
    } while (validInput);
    try1:
    cout << "Введите оклад: ";
    cin >> contacts_list[contacts_count].salary.datasalary;
    if (contacts_list[contacts_count].salary.datasalary <= 0 || cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите оклад заново." << '\n';
        goto try1;
    }
    cout << "Введите дату поступления на предприятие: ";
try2:
    cout << "Введите год : ";
    cin >> contacts_list[contacts_count].birthYear.datanum;
    if (contacts_list[contacts_count].birthYear.datanum <= 0 || (contacts_list[contacts_count].birthYear.datanum > 2024)|| cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите год заново." << '\n';
        goto try2;
    }
    bool leapyear = false;
    if ((contacts_list[contacts_count].birthYear.datanum % 4 == 0 && contacts_list[contacts_count].birthYear.datanum != 0) || contacts_list[contacts_count].birthYear.datanum % 400 == 0) {
        leapyear = true;
    }
    int rd_year = contacts_list[contacts_count].birthYear.datanum;

    try3:
    cout << "Введите месяц : ";
    cin >> contacts_list[contacts_count].birthMonth.datanum;
    if (contacts_list[contacts_count].birthMonth.datanum <= 0 || cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите месяц заново." << '\n';
        goto try3;
    }
    if (contacts_list[contacts_count].birthMonth.datanum < 1 || contacts_list[contacts_count].birthMonth.datanum >12)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите месяц заново." << '\n';
        goto try3;
    }
    if (rd_year == 2024 && contacts_list[contacts_count].birthMonth.datanum > 4) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите месяц заново." << '\n';
        goto try3;
    }
    int rd_month = contacts_list[contacts_count].birthMonth.datanum;
    try4:
    cout << "Введите день : ";
    cin >> contacts_list[contacts_count].birthDay.datanum;

    if (contacts_list[contacts_count].birthDay.datanum <= 0 || cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите день заново." << '\n';
        goto try4;
    }
    if (contacts_list[contacts_count].birthDay.datanum < 1)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите день заново." << '\n';
        goto try4;
    }
    
    if ((leapyear && rd_month == 2 && contacts_list[contacts_count].birthDay.datanum > 29))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите день заново." << '\n';
        goto try4;
    }

    if (!leapyear && (contacts_list[contacts_count].birthDay.datanum > daysInMonth[rd_month - 1]))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите день заново." << '\n';
        goto try4;
    }

    if ((rd_month == current_m && rd_year == current_y && contacts_list[contacts_count].birthDay.datanum > current_d))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод!!!Ведите день заново." << '\n';
        goto try4;
    }

    contacts_count++;
    cout << "Данные успешно добавлены!" << endl;
}

// Функция для отображения всех добавленных контактов
void list()
{
    for (int i = 0; i < contacts_count; i++)
    {
        // Вывод информации о контакте
        cout << "Имя работника: " << contacts_list[i].name.datach << endl;
        cout << "Фамилия работника: " << contacts_list[i].sername.datach << endl;
        cout << "Отчество работника: " << contacts_list[i].middle_name.datach << endl;
        cout << "Образование: " << contacts_list[i].address.datach << endl;
        cout << "Специальность: " << contacts_list[i].phoneNumber.datach << endl;
        cout << "Подразделение: " << contacts_list[i].place.datach << endl;
        cout << "Должность: " << contacts_list[i].jobtitle.datach << endl;
        cout << "Введите оклад: "<< contacts_list[i].salary.datasalary<<endl;
        cout << "Дата поступления на предприятие: " << contacts_list[i].birthDay.datanum << "." << contacts_list[i].birthMonth.datanum << "." << contacts_list[i].birthYear.datanum << endl;
    }
}

// Функция для записи контактов в файл
void write()
{
    ofstream fin("file.txt");

    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return;
    }

    for (int i = 0; i < contacts_count; i++)
    {
        // Запись данных в файл
        /*fin << i + 1 << "-й работник:" << endl;*/
        
        fin <<contacts_list[i].name.datach << endl;
        fin <<  contacts_list[i].sername.datach << endl;
        fin <<  contacts_list[i].middle_name.datach << endl;
        fin << contacts_list[i].address.datach << endl;
        fin <<  contacts_list[i].phoneNumber.datach << endl;
        fin  << contacts_list[i].place.datach << endl;
        fin <<  contacts_list[i].jobtitle.datach << endl;
        fin << contacts_list[i].salary.datasalary << endl;
        fin << contacts_list[i].birthDay.datanum << endl<< contacts_list[i].birthMonth.datanum << endl << contacts_list[i].birthYear.datanum << endl;

    }

    fin.close();
}

// Функция для чтения данных из файла
//void read()
//{
//    ifstream fout("file.txt");
//    string line;
//    int count = 0;
//    do
//    {
//        fout >> contacts_list[count].name.datach >>
//                        contacts_list[count].sername.datach >>
//                        contacts_list[count].middle_name.datach >>
//                        contacts_list[count].address.datach >>
//                      contacts_list[count].phoneNumber.datach >>
//                        contacts_list[count].place.datach >>
//                        contacts_list[count].salary.datasalary >>
//                        contacts_list[count].birthDay.datanum >> contacts_list[count].birthMonth.datanum >> contacts_list[count].birthYear.datanum;
//        count++;
//} while (!fout.eof());
//
//    fout.close();
//}
void read() {
    ifstream fout("file.txt");
    int count = 0;
    string line;
    if (fout.is_open()) {
        cout << "Начинаю чтение из файла!!!!" << endl;
        do {
            getline(fout,line);
            line.copy(contacts_list[count].name.datach, line.length()+1);
            /*cout << contacts_list[count].name.datach;*/
            /*if (contacts_list[count].jobtitle.datach == "") {
                
                break;
            }*/
            getline(fout, line);
            line.copy(contacts_list[count].sername.datach, line.length()+1);
            /*cout << contacts_list[count].sername.datach;*/
            getline(fout, line);
            line.copy(contacts_list[count].middle_name.datach, line.length()+1);
            /*cout << contacts_list[count].middle_name.datach;*/
            getline(fout, line);
            line.copy(contacts_list[count].address.datach, line.length()+1);
            /*cout << contacts_list[count].address.datach;*/
            getline(fout, line);
            line.copy(contacts_list[count].phoneNumber.datach, line.length()+1);
           /* cout << contacts_list[count].phoneNumber.datach;*/
            getline(fout, line);
            line.copy(contacts_list[count].place.datach, line.length()+1);
           /* cout << contacts_list[count].place.datach;*/

            getline(fout, line);
           /* cout << line;*/
            strcpy_s(contacts_list[count].jobtitle.datach, line.c_str());
           /* cout << contacts_list[count].jobtitle.datach;*/
            
            fout >> contacts_list[count].salary.datasalary;
            /*cout << contacts_list[count].salary.datasalary;*/
          fout>>  contacts_list[count].birthDay.datanum >> contacts_list[count].birthMonth.datanum >> contacts_list[count].birthYear.datanum;
         /* cout<< contacts_list[count].birthDay.datanum << contacts_list[count].birthMonth.datanum << contacts_list[count].birthYear.datanum;
          */ 
          count++;
          getline(fout, line); 
         
          /*  line = "";*/
           /* cout << "******************" << '\n';*/
            if (fout.eof()) {
                /*cout << "END OF FAIL'\n'";*/
                break;
            }
        } while (!fout.eof());

        fout.close();
        cout << "Данные загружены из файла." << endl;
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
    fout.close();
    contacts_count = count-1;
    list();
}


// Функция для поиска контакта по ФИО
//void search()
//{
//    char inputFam[1000];
//    bool found = false;
//    cout << "Введите должность для поиска: ";
//    cin >> inputFio;
//
//    for (int i = 0; i < contacts_count; i++)
//    {
//        // Поиск контакта по фамилии
//        if (strcmp(contacts_list[i].jobtitle.datach, inputFio) == 0)
//        {
//            found = true;
//            cout << "Имя работника: " << contacts_list[i].name.datach << endl;
//            cout << "Фамилия работника: " << contacts_list[i].sername.datach << endl;
//            cout << "Отчество работника: " << contacts_list[i].middle_name.datach << endl;
//            cout << "Образование: " << contacts_list[i].address.datach << endl;
//            cout << "Специальность: " << contacts_list[i].phoneNumber.datach << endl;
//            cout << "Подразделение: " << contacts_list[i].place.datach << endl;
//            cout << "Должность: " << contacts_list[i].jobtitle.datach << endl;
//            cout << "Введите оклад: " << contacts_list[i].salary.datasalary << endl;
//            cout << "Дата поступления на предприятие: " << contacts_list[i].birthDay.datanum << "." << contacts_list[i].birthMonth.datanum << "." << contacts_list[i].birthYear.datanum << endl;
//            break;
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Работник с такой должностью на найден" << endl;
//    }
//}



void search()
{
    
    bool found = false;
    cout << "Введите должность для поиска: ";
    cin.get();
    gets_s(inputFio,60);
    cout << "------" << endl;
    cout << "have Должность: " << inputFio << endl;

   
    for (int i = 0; i < contacts_count; i++)
    {
        /*cout << "check Должность: " << contacts_list[i].jobtitle.datach << endl;*/

        // Поиск контакта по фамилии
        if (strcmp(contacts_list[i].jobtitle.datach, inputFio) == 0)
            //    if (strcmp(inputFio.compare(contacts_list[i].jobtitle.datach) == 0)
        {
            
            found = true;
            cout << "Имя работника: " << contacts_list[i].name.datach << endl;
            cout << "Фамилия работника: " << contacts_list[i].sername.datach << endl;
            cout << "Отчество работника: " << contacts_list[i].middle_name.datach << endl;
            cout << "Образование: " << contacts_list[i].address.datach << endl;
            cout << "Специальность: " << contacts_list[i].phoneNumber.datach << endl;
            cout << "Подразделение: " << contacts_list[i].place.datach << endl;
            cout << "Должность: " << contacts_list[i].jobtitle.datach << endl;
            cout << "Введите оклад: " << contacts_list[i].salary.datasalary << endl;
            cout << "Дата поступления на предприятие: " << contacts_list[i].birthDay.datanum << "." << contacts_list[i].birthMonth.datanum << "." << contacts_list[i].birthYear.datanum << endl;

            /*   cout << "ФИО: " << contacts_list[i].fio.datach << endl;
               cout << "Дата рождения: " << contacts_list[i].birthDay.datanum << "." << contacts_list[i].birthMonth.datanum << "." << contacts_list[i].birthYear.datanum << endl;
               cout << "Адрес: " << contacts_list[i].address.datanum << endl;
               cout << "Телефон: " << contacts_list[i].phoneNumber.datanum << endl;
               */
          /*  break;*/
        }
    }

    if (!found)
    {
        cout << "Контакт с такой должностью не найден" << endl;
    }
}