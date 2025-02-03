#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
int countConsonants(const char* str) {
	const char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	const char* construs = "йцкнгшщзхфвпрлджчсмтб…÷ Ќ√Ўў«’‘¬ѕ–Ћƒ∆„—ћ“Ѕ";
	int count = 0;

	while (*str) {
		if (strchr(consonants, *str)) {
			count++;
		}
		if (strchr(construs, *str)) {
			count++;
		}

		str++;
	}

	return count;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	string line;
	
	unsigned int N, K;
	unsigned int I = 0;
	
	
	cout << "¬ведите номер первой строки:" << '\n';
	cin >> N;
	cout << "¬ведите номер последней строки:" << '\n';
	cin >> K;
	ofstream fout("FILE2.txt");    
	
	ifstream fin("FILE1.txt");
	if (!fin.is_open() || !fout)
		cout << "‘айл не может быть открыт!\n";
	else
	{
		for (int i = 1; i < N; i++) {
			getline(fin, line);
		}
		for (N; N <= K; N++) {
			getline(fin,line);
			fout << line;
			fout << '\n';
			
		}

		fin.close();
		fout.close();
	}
	
	ifstream fin2("FILE2.txt");
	
	while (getline(fin2, line)) {
		I +=countConsonants(line.c_str());
	}
	fin2.close();
		cout << " ол-во согласных букв в файле: "<< I;
		
	return 0;
} 