#include <iostream> 
#include <string>
#include <Windows.h> 
//#include <regex>
#define SIZE 10000

/*
bool check_input(const std::string& input_str) {
    std::regex regex("([0-9]+)((\\.){1}([0-9]+)|(\\.){0})");
    return std::regex_match(input_str, regex);
}*/

bool isFractional(float number) {
    char str[1000];
    if (number - (int)number != 0)
    {
        printf("float?\n");
        snprintf(str, sizeof str, "%f", number);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == '.') {
                return true; // Найдена дробная часть
            }
        }
    }
    else
    {
        /*printf("Дробной части не найдено\n")*/;
        return false; // Дробной части не найдено
    }

}

using namespace std;


int i = 0;
int current_year = 2024;
int current_y = 2024;
int current_m = 4;
int current_d = 17;
struct release_date {
    unsigned int day : 4;
    unsigned int month : 3;
    unsigned int year : 12;
};

enum MARK {
    EMPTY = -1,
    OTHER,
    AUDI,
    BMW,
    MERCEDES_BENZ,
    VOLKSWAGEN,
    TOYOTA
};


enum CarBodyType {
    Other, // Другой тип кузова.
    Sedan, // Седан.
    SUV, // Внедорожник.
    Hatchback, // Хэтчбек.
    Coupe, // Купе.
    Pickup // Пикап.
};


struct CAR {
    MARK mark;
    string color;
    string serialnum;
    release_date rd;
    CarBodyType tb;
    release_date ro;
    string owner;
}STORAGE[SIZE];

bool checkfio(string f);
int getInt();
void add(CAR& car);
string carMarkToString(MARK mark);
string bodytprint(CarBodyType tb);
void view(CAR* s, int);
CAR* del(CAR* s, int& i, int x);
string find(CAR* s, int& i, string x);
void displayProduct(CAR* s);

#include <ctime>
bool check(string f) {
    bool t = false;
    if (f == "" || f == "\n") {
        return 0;
    }
    for (int i = 0; i < f.length(); i++) {
        if ((f[i] >= '0' && f[i] <= '9') /*|| (f[i] >= 'а' && f[i] <= 'я')*/) {
            /*if (f[i - 1] == '-') {
                return 0;
            }*/
          
            break;
        }

        else {

            return 0;
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
void add(CAR& car) {
    do {
        cout << "Марку авто (1 - AUDI, 2 - BMW, 3 - MERCEDES_BENZ, 4 - VOLKSWAGEN, 5 - TOYOTA, 0 - OTHER): ";
        car.mark = (MARK)getInt();

        if (cin.fail() || car.mark < 0 || car.mark > 5) {
            cout << "Некорректный ввод " /*<< endl*/;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cout << carMarkToString(car.mark) << endl;
            break;
        }
    } while (true);

    cout << "Цвет: ";
    getline(cin, car.color);

    cout << "Серийный номер: ";
    getline(cin, car.serialnum);

    cout << "Дата выпуска авто: \n";
    cout << "\tГод: ";
    float number_m;
  /*  int number;*/
    while (1)
    {
        /*cin.clear();
        cin.ignore(32767, '\n');*/
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }

      /*  if (!check(to_string(number_m)))
        {
            printf("лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/
        
        else if ((int)number_m < 0 || (int)number_m > 2024) {
            printf("Необходимо ввести корректный год!!!Повторите ввод:\n ");
        }

        else break;


        /*printf("Необходимо ввести число.Повторите ввод:\n ");*/
    }
    bool leapyear = false;
    car.rd.year = (int)number_m;
    if ((car.rd.year % 4 == 0 && car.rd.year != 0) || car.rd.year % 400 == 0) {
        leapyear = true;
    }
    int rd_year = car.rd.year;

    cout << "\tМесяц: ";

    
    while (1)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/

        if ((int)number_m < 1 || (int)number_m >12)
        {
            //while ((c = getchar()) != '\n' /*&& c != EOF*/);
            printf("Необходимо ввести корректный месяц!!!Повторите ввод:\n ");
            continue;
        }
        if (rd_year == 2024 && (int)number_m > 4) {
            /*while ((c = getchar()) != '\n' && c != EOF);*/
            printf("Необходимо ввести корректный месяц для текущего года !!!Повторите ввод:\n ");
            continue;
        }
        else break;

        /*printf("Некорректный ввод!!!Повторите ввод:\n ");*/
    }
    car.rd.month = (int)number_m;
    int rd_month = car.rd.month;
    /*cout << "Месяц, сохранён: " << car.rd.month << "\n";*/

    cout << "\tДень: ";
    /*cin.clear();
    cin.ignore(32767, '\n');*/
    while (1)
    {
        const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
       
        cin.clear();
        cin.ignore(32767, '\n');
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/

        else   if ((int)number_m < 1)
        {

            printf("День не может быть отрицательным!!!Повторите ввод:\n ");
            continue;
        }

        /* if (number - (int)number != 0)
         {
             printf("обнаружена дробная часть\n ");
             if (check_input(to_string(number))) {
                 printf("День не может быть дробным!!!Повторите ввод:\n ");
                 continue;
             }
         }*/


        if ((leapyear && rd_month == 2 && (int)number_m> 29))
        {
            printf("Необходимо ввести корректный день февраля  високосного года!!!Повторите ввод:\n ");
            continue;
        }

        if (!leapyear && (int)number_m > daysInMonth[rd_month - 1])
        {
            printf("Необходимо ввести корректный день!!!Повторите ввод:\n ");
            continue;
        }

        if ((rd_month == current_m && rd_year == current_y && (int)number_m > current_d))
        {
            printf("Необходимо ввести корректный день текущего месяца!!!Повторите ввод:\n ");
            continue;
        }
        else break;


        /*printf("Необходимо ввести число.Повторите ввод:\n ");*/
    }
    car.rd.day = (int)number_m;
    int rd_day = car.rd.day;
    do {
        cout << "Тип кузова (1 - Sedan, 2 - SUV, 3 - Hatchback, 4 - Coupe, 5 - Pickup, 0 - Other): ";
        car.tb = (CarBodyType)getInt();

        if (cin.fail() || car.tb < 0 || car.tb > 5) {
            cout << "Некорректный ввод " /*<< endl*/;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cout << bodytprint(car.tb) << endl;
            break;
        }
    } while (true);
    bool validInput = true;
    do{

    cout << "Владелец: ";
a:
    getline(cin, car.owner);
    validInput = checkfio(car.owner);

    if (!validInput) {
        printf("Имя введено некорректно.Введите еще раз!!!\n");
        goto a;
    }
    else
        break;
    } while (validInput);
    validInput = true;
   


    cout << "Дата последнего техосмотра авто: \n";
    cout << "\tГод: ";
    while (1)
    {
        /*cin.clear();
        cin.ignore(32767, '\n');*/
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }

        if (car.rd.year> number_m) {
            printf("Дата последнего техосмотра не может быть меньше даты выпуска!!!Повторите ввод.\n");
            continue;
        }

       /* if (check(to_string(number_m)))
        {
            printf("Лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/

        else if ((int)number_m < 0 || (int)number_m > 2024) {
            printf("Необходимо ввести корректный год!!!Повторите ввод:\n ");
        }

        else break;


        /*printf("Необходимо ввести число.Повторите ввод:\n ");*/
    }
    
     leapyear = false;
     car.ro.year = (int)number_m;
    if ((car.ro.year % 4 == 0 && car.ro.year != 0) || car.ro.year % 400 == 0) {
        leapyear = true;
    }
     rd_year = car.ro.year;


    cout << "\tМесяц: ";
    while (1)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
        if (car.rd.year== car.ro.year && car.rd.month>number_m) {
            printf("Дата последнего техосмотра не может быть меньше даты выпуска!!!Повторите ввод.\n");
            continue;
        }

        if (isFractional(number_m)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/

        if ((int)number_m < 1 || (int)number_m >12)
        {
            //while ((c = getchar()) != '\n' /*&& c != EOF*/);
            printf("Необходимо ввести корректный месяц!!!Повторите ввод:\n ");
            continue;
        }
        if (rd_year == 2024 && (int)number_m > 4) {
            /*while ((c = getchar()) != '\n' && c != EOF);*/
            printf("Необходимо ввести корректный месяц для текущего года !!!Повторите ввод:\n ");
            continue;
        }
        else break;

        /*printf("Некорректный ввод!!!Повторите ввод:\n ");*/
    }
    car.ro.month= (int)number_m;
    rd_month = car.ro.month;
    cout << "\tДень: ";
    float number;
   
    while (1)
    {
        const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        /*cin.clear();
        cin.ignore(32767, '\n');*/
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }
       
       
        if (isFractional(number)) {
            printf("Необходимо ввести целое число. Повторите ввод.\n");
            continue;
        }
        
      /*  if (check(to_string(number_m)))
        {
            printf("лишние символы после числа. Необходимо ввести число.Повторите ввод:\n ");
            continue;
        }*/

        if ((int)number < 1)
        {

            printf("День не может быть отрицательным!!!Повторите ввод:\n ");
            continue;
        }
       
        /* if (number - (int)number != 0)
         {
             printf("обнаружена дробная часть\n ");
             if (check_input(to_string(number))) {
                 printf("День не может быть дробным!!!Повторите ввод:\n ");
                 continue;
             }
         }*/


        if ((leapyear && rd_month == 2 && (int)number > 29))
        {
            printf("Необходимо ввести корректный день февраля  високосного года!!!Повторите ввод:\n ");
            continue;
        }

        if (!leapyear && (int)number > daysInMonth[rd_month - 1])
        {
            printf("Необходимо ввести корректный день!!!Повторите ввод:\n ");
            continue;
        }

        if ((rd_month == current_m && rd_year == current_y && (int)number > current_d))
        {
            printf("Необходимо ввести корректный день текущего месяца!!!Повторите ввод:\n ");
            continue;
        }
         if (car.rd.year == car.ro.year && car.rd.month == car.ro.month && (int)number <(int)car.rd.day) {
            printf("Дата последнего техосмотра не может быть меньше даты выпуска!!!Повторите ввод.\n");
            continue;
        }
        else break;


        /*printf("Необходимо ввести число.Повторите ввод:\n ");*/
    }
    car.ro.day = (int)number;

   
}




void view(CAR* s, int i) {
    if (i == 0) {
        printf("В хранилище пусто\n");
    }
    else {


        for (int k = 0; k < i; k++)
        {

            cout << "Элемент" << '\t' << k + 1 << '\n';
            cout << "Марка" << '\t' << carMarkToString(s[k].mark).c_str() << '\n';
            cout << "Цвет" << '\t' << s[k].color.c_str() << '\n';
            cout << "Заводской номер" << '\t' << s[k].serialnum.c_str() << '\n';
            cout << "Дата выпуска" << '\t' << (int)s[k].rd.year << "." << (int)s[k].rd.month << "." << (int)s[k].rd.day << '\n';
            cout << "Тип кузова" << '\t' << bodytprint(s[k].tb).c_str() << '\n';
            cout << "Последний техосмотр" << '\t' << (int)s[k].ro.year << "." << (int)s[k].ro.month << "." << (int)s[k].ro.day << '\n';
            cout << "Владелец " << '\t' << s[k].owner.c_str() << '\n';

        }


    }
}
void displayProduct(CAR& car) {
    cout << "Марка" << '\t' << carMarkToString(car.mark).c_str() << '\n';
    cout << "Цвет" << '\t' << car.color.c_str() << '\n';
    cout << "Заводской номер" << '\t' << car.serialnum.c_str() << '\n';
    cout << "Дата выпуска" << '\t' << (int)car.rd.year << "." << (int)car.rd.month << "." << (int)car.rd.day << '\n';
    cout << "Тип кузова" << '\t' << bodytprint(car.tb).c_str() << '\n';
    cout << "Последний техосмотр" << '\t' << (int)car.ro.year << "." << (int)car.ro.month << "." << (int)car.ro.day << '\n';
    cout << "Владелец " << '\t' << car.owner.c_str() << '\n';

}





//if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1] || (day == 29 && month == 2 && !leapYear(year))) {
  //  cout << "Некорректная дата." << endl;
   // continue;
//}
//year % 4 == 0 && year % 100 != 0

string find(CAR* s, int& i, string x) {
    if (i == 0)
    {
        return "В хранилище пусто!";
    }
    else {


        for (int k = 0; k < i; k++)
            if (_stricmp(s[k].serialnum.c_str(), x.c_str()) == 0)
                displayProduct(STORAGE[k]);
        return "Есть!";

    }
    return "Такого номера нет!";
}

CAR* del(CAR* s, int& i, int x) {
    if (i == 0)
    {
        printf("В хранилище пусто\n");
        return s;
    }
    else if (x > i) {
        printf("Такого элемента нет!\n");
        return s;
    }
    else {
        i--;
        int temp = 0;
        for (int k = 0; k < i; k++) {
            if (k == (x - 1))
            {
                s[k] = s[k + 1];
            }
        }
        return s;
    }
}

int getInt()
{
    int number;
    char c;
    while (1)
    {

        if (!scanf_s("%d", &number) || getchar() != '\n')
        {
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else return number;

        printf("Необходимо ввести число.Повторите ввод:\n ");
    }
}


string carMarkToString(MARK mark)
{
    switch (mark) {
    case 2:
        return "BMW";
    case 1:
        return "Audi";
    case 3:
        return "Mercedes";
    case 4:
        return "Volkswagen";
    case 5:
        return "Toyota";
    case 0:
        return "Other";
    default:
        return "Некорректный ввод";
    }
}



string bodytprint(CarBodyType tb) {
    switch (tb) {
    case Sedan:
        return "Sedan";
    case SUV:
        return "SUV";
    case Hatchback:
        return "Hatchback";
    case Coupe:
        return "Coupe";
    case Pickup:
        return "Pickup";
    case 0:
        return "Другой";
    default:
        cout << "Некорректный ввод";
    }
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    char choice;
    string inputString;
    do
    {
        cout << endl;
        cout << "1 - Добавление нового элемента (Ввод с клавиатуры) " << endl;
        cout << "2 - Вывод элементов хранилища " << endl;
        cout << "3 - Удаление элемента" << endl;
        cout << "4 - Поиск транспортных средств по заводскому номеру " << endl;
        cout << "0 - Выход из программы " << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        if (choice < 0) {
            cout << "Некорректный ввод!!!" << '\n';
            break;
        }

        switch (choice)
        {

        case '1':
            if (i < SIZE) {
                add(STORAGE[i]);
                i++;
            }
            else
                cout << "Извините, но на складе нет мест! \n ";
            break;


        case '2':
            view(STORAGE, i);
            break;

        case '3':
            cout << "Введите удаляемый элемент: \n ";
            STORAGE == del(STORAGE, i, getInt());

            break;


        case '4':
            cout << "Введите заводской номер элемента:  \n ";
            cin >> inputString;
            printf(find(STORAGE, i, inputString).c_str());

            break;


        case '0':
            cout << "Выход из программы... ";
            return 0;
            break;

        default:
            cout << "Некорректное значение. Выберите что-то из списка. " << endl;
            break;
        }
    } while (choice != 0);
    delete[]STORAGE;
}


