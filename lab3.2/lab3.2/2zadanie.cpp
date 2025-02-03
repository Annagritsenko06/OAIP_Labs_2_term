#include <iostream>   
#include <string>     
#include <fstream>    

using namespace std;
void infile(string s);
void outfile(string tmp);
string tmp;
int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    cout << "Введите строку: " << endl;
    getline(cin, str);
    infile(str);
    outfile(tmp);

    
}

void infile(string s) {
    ofstream fout("FILE1.txt");
    if (fout.fail())
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(1);
    }
    fout << s;
    fout.close();
};
void outfile(string tmp)
{
    ifstream fin("FILE1.txt");


    if (fin.fail())
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(1);
    }
    while (fin >> tmp)
    {
        if (tmp.length() % 2 == 0)
        {
            cout << tmp << ' ';
        }
    }
    fin.close();
};



























/* while (fin >> tmp)
    {
        if (tmp.length() % 2 == 0)
        {
            cout << tmp << ' ';
        }
    }*/















    





