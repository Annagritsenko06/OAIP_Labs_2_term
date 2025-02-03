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
                return true; // ������� ������� �����
            }
        }
    }
    else
    {
        /*printf("������� ����� �� �������\n")*/;
        return false; // ������� ����� �� �������
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
    Other, // ������ ��� ������.
    Sedan, // �����.
    SUV, // �����������.
    Hatchback, // �������.
    Coupe, // ����.
    Pickup // �����.
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
        if ((f[i] >= '0' && f[i] <= '9') /*|| (f[i] >= '�' && f[i] <= '�')*/) {
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
            if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= '�' && f[0] <= '�')) {
                t = true;
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= '�' && f[i] <= '�') && t) {
            if (f[i - 1] == '-') {
                continue;
            }
            else {
                return 0;
            }
        }
        else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= '�' && f[i] <= '�')) {
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
        cout << "����� ���� (1 - AUDI, 2 - BMW, 3 - MERCEDES_BENZ, 4 - VOLKSWAGEN, 5 - TOYOTA, 0 - OTHER): ";
        car.mark = (MARK)getInt();

        if (cin.fail() || car.mark < 0 || car.mark > 5) {
            cout << "������������ ���� " /*<< endl*/;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cout << carMarkToString(car.mark) << endl;
            break;
        }
    } while (true);

    cout << "����: ";
    getline(cin, car.color);

    cout << "�������� �����: ";
    getline(cin, car.serialnum);

    cout << "���� ������� ����: \n";
    cout << "\t���: ";
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
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }

      /*  if (!check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/
        
        else if ((int)number_m < 0 || (int)number_m > 2024) {
            printf("���������� ������ ���������� ���!!!��������� ����:\n ");
        }

        else break;


        /*printf("���������� ������ �����.��������� ����:\n ");*/
    }
    bool leapyear = false;
    car.rd.year = (int)number_m;
    if ((car.rd.year % 4 == 0 && car.rd.year != 0) || car.rd.year % 400 == 0) {
        leapyear = true;
    }
    int rd_year = car.rd.year;

    cout << "\t�����: ";

    
    while (1)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/

        if ((int)number_m < 1 || (int)number_m >12)
        {
            //while ((c = getchar()) != '\n' /*&& c != EOF*/);
            printf("���������� ������ ���������� �����!!!��������� ����:\n ");
            continue;
        }
        if (rd_year == 2024 && (int)number_m > 4) {
            /*while ((c = getchar()) != '\n' && c != EOF);*/
            printf("���������� ������ ���������� ����� ��� �������� ���� !!!��������� ����:\n ");
            continue;
        }
        else break;

        /*printf("������������ ����!!!��������� ����:\n ");*/
    }
    car.rd.month = (int)number_m;
    int rd_month = car.rd.month;
    /*cout << "�����, �������: " << car.rd.month << "\n";*/

    cout << "\t����: ";
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
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/

        else   if ((int)number_m < 1)
        {

            printf("���� �� ����� ���� �������������!!!��������� ����:\n ");
            continue;
        }

        /* if (number - (int)number != 0)
         {
             printf("���������� ������� �����\n ");
             if (check_input(to_string(number))) {
                 printf("���� �� ����� ���� �������!!!��������� ����:\n ");
                 continue;
             }
         }*/


        if ((leapyear && rd_month == 2 && (int)number_m> 29))
        {
            printf("���������� ������ ���������� ���� �������  ����������� ����!!!��������� ����:\n ");
            continue;
        }

        if (!leapyear && (int)number_m > daysInMonth[rd_month - 1])
        {
            printf("���������� ������ ���������� ����!!!��������� ����:\n ");
            continue;
        }

        if ((rd_month == current_m && rd_year == current_y && (int)number_m > current_d))
        {
            printf("���������� ������ ���������� ���� �������� ������!!!��������� ����:\n ");
            continue;
        }
        else break;


        /*printf("���������� ������ �����.��������� ����:\n ");*/
    }
    car.rd.day = (int)number_m;
    int rd_day = car.rd.day;
    do {
        cout << "��� ������ (1 - Sedan, 2 - SUV, 3 - Hatchback, 4 - Coupe, 5 - Pickup, 0 - Other): ";
        car.tb = (CarBodyType)getInt();

        if (cin.fail() || car.tb < 0 || car.tb > 5) {
            cout << "������������ ���� " /*<< endl*/;
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

    cout << "��������: ";
a:
    getline(cin, car.owner);
    validInput = checkfio(car.owner);

    if (!validInput) {
        printf("��� ������� �����������.������� ��� ���!!!\n");
        goto a;
    }
    else
        break;
    } while (validInput);
    validInput = true;
   


    cout << "���� ���������� ���������� ����: \n";
    cout << "\t���: ";
    while (1)
    {
        /*cin.clear();
        cin.ignore(32767, '\n');*/
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
        if (isFractional(number_m)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }

        if (car.rd.year> number_m) {
            printf("���� ���������� ���������� �� ����� ���� ������ ���� �������!!!��������� ����.\n");
            continue;
        }

       /* if (check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/

        else if ((int)number_m < 0 || (int)number_m > 2024) {
            printf("���������� ������ ���������� ���!!!��������� ����:\n ");
        }

        else break;


        /*printf("���������� ������ �����.��������� ����:\n ");*/
    }
    
     leapyear = false;
     car.ro.year = (int)number_m;
    if ((car.ro.year % 4 == 0 && car.ro.year != 0) || car.ro.year % 400 == 0) {
        leapyear = true;
    }
     rd_year = car.ro.year;


    cout << "\t�����: ";
    while (1)
    {
        cin.clear();
        cin.ignore(32767, '\n');
        char c;
        /* scanf_s("%d", &number);*/
        if (!scanf_s("%f", &number_m)) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
        if (car.rd.year== car.ro.year && car.rd.month>number_m) {
            printf("���� ���������� ���������� �� ����� ���� ������ ���� �������!!!��������� ����.\n");
            continue;
        }

        if (isFractional(number_m)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }

        /*if (check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/

        if ((int)number_m < 1 || (int)number_m >12)
        {
            //while ((c = getchar()) != '\n' /*&& c != EOF*/);
            printf("���������� ������ ���������� �����!!!��������� ����:\n ");
            continue;
        }
        if (rd_year == 2024 && (int)number_m > 4) {
            /*while ((c = getchar()) != '\n' && c != EOF);*/
            printf("���������� ������ ���������� ����� ��� �������� ���� !!!��������� ����:\n ");
            continue;
        }
        else break;

        /*printf("������������ ����!!!��������� ����:\n ");*/
    }
    car.ro.month= (int)number_m;
    rd_month = car.ro.month;
    cout << "\t����: ";
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
            printf("���������� ������ �����.��������� ����:\n ");
            continue;
        }
       
       
        if (isFractional(number)) {
            printf("���������� ������ ����� �����. ��������� ����.\n");
            continue;
        }
        
      /*  if (check(to_string(number_m)))
        {
            printf("������ ������� ����� �����. ���������� ������ �����.��������� ����:\n ");
            continue;
        }*/

        if ((int)number < 1)
        {

            printf("���� �� ����� ���� �������������!!!��������� ����:\n ");
            continue;
        }
       
        /* if (number - (int)number != 0)
         {
             printf("���������� ������� �����\n ");
             if (check_input(to_string(number))) {
                 printf("���� �� ����� ���� �������!!!��������� ����:\n ");
                 continue;
             }
         }*/


        if ((leapyear && rd_month == 2 && (int)number > 29))
        {
            printf("���������� ������ ���������� ���� �������  ����������� ����!!!��������� ����:\n ");
            continue;
        }

        if (!leapyear && (int)number > daysInMonth[rd_month - 1])
        {
            printf("���������� ������ ���������� ����!!!��������� ����:\n ");
            continue;
        }

        if ((rd_month == current_m && rd_year == current_y && (int)number > current_d))
        {
            printf("���������� ������ ���������� ���� �������� ������!!!��������� ����:\n ");
            continue;
        }
         if (car.rd.year == car.ro.year && car.rd.month == car.ro.month && (int)number <(int)car.rd.day) {
            printf("���� ���������� ���������� �� ����� ���� ������ ���� �������!!!��������� ����.\n");
            continue;
        }
        else break;


        /*printf("���������� ������ �����.��������� ����:\n ");*/
    }
    car.ro.day = (int)number;

   
}




void view(CAR* s, int i) {
    if (i == 0) {
        printf("� ��������� �����\n");
    }
    else {


        for (int k = 0; k < i; k++)
        {

            cout << "�������" << '\t' << k + 1 << '\n';
            cout << "�����" << '\t' << carMarkToString(s[k].mark).c_str() << '\n';
            cout << "����" << '\t' << s[k].color.c_str() << '\n';
            cout << "��������� �����" << '\t' << s[k].serialnum.c_str() << '\n';
            cout << "���� �������" << '\t' << (int)s[k].rd.year << "." << (int)s[k].rd.month << "." << (int)s[k].rd.day << '\n';
            cout << "��� ������" << '\t' << bodytprint(s[k].tb).c_str() << '\n';
            cout << "��������� ���������" << '\t' << (int)s[k].ro.year << "." << (int)s[k].ro.month << "." << (int)s[k].ro.day << '\n';
            cout << "�������� " << '\t' << s[k].owner.c_str() << '\n';

        }


    }
}
void displayProduct(CAR& car) {
    cout << "�����" << '\t' << carMarkToString(car.mark).c_str() << '\n';
    cout << "����" << '\t' << car.color.c_str() << '\n';
    cout << "��������� �����" << '\t' << car.serialnum.c_str() << '\n';
    cout << "���� �������" << '\t' << (int)car.rd.year << "." << (int)car.rd.month << "." << (int)car.rd.day << '\n';
    cout << "��� ������" << '\t' << bodytprint(car.tb).c_str() << '\n';
    cout << "��������� ���������" << '\t' << (int)car.ro.year << "." << (int)car.ro.month << "." << (int)car.ro.day << '\n';
    cout << "�������� " << '\t' << car.owner.c_str() << '\n';

}





//if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1] || (day == 29 && month == 2 && !leapYear(year))) {
  //  cout << "������������ ����." << endl;
   // continue;
//}
//year % 4 == 0 && year % 100 != 0

string find(CAR* s, int& i, string x) {
    if (i == 0)
    {
        return "� ��������� �����!";
    }
    else {


        for (int k = 0; k < i; k++)
            if (_stricmp(s[k].serialnum.c_str(), x.c_str()) == 0)
                displayProduct(STORAGE[k]);
        return "����!";

    }
    return "������ ������ ���!";
}

CAR* del(CAR* s, int& i, int x) {
    if (i == 0)
    {
        printf("� ��������� �����\n");
        return s;
    }
    else if (x > i) {
        printf("������ �������� ���!\n");
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

        printf("���������� ������ �����.��������� ����:\n ");
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
        return "������������ ����";
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
        return "������";
    default:
        cout << "������������ ����";
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
        cout << "1 - ���������� ������ �������� (���� � ����������) " << endl;
        cout << "2 - ����� ��������� ��������� " << endl;
        cout << "3 - �������� ��������" << endl;
        cout << "4 - ����� ������������ ������� �� ���������� ������ " << endl;
        cout << "0 - ����� �� ��������� " << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore();
        if (choice < 0) {
            cout << "������������ ����!!!" << '\n';
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
                cout << "��������, �� �� ������ ��� ����! \n ";
            break;


        case '2':
            view(STORAGE, i);
            break;

        case '3':
            cout << "������� ��������� �������: \n ";
            STORAGE == del(STORAGE, i, getInt());

            break;


        case '4':
            cout << "������� ��������� ����� ��������:  \n ";
            cin >> inputString;
            printf(find(STORAGE, i, inputString).c_str());

            break;


        case '0':
            cout << "����� �� ���������... ";
            return 0;
            break;

        default:
            cout << "������������ ��������. �������� ���-�� �� ������. " << endl;
            break;
        }
    } while (choice != 0);
    delete[]STORAGE;
}


