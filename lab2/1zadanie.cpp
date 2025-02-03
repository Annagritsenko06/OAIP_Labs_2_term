#include <Windows.h>
#include <iostream>
#include <stdio.h>  
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");
    FILE* f1, * f2;
    char line[10000];
    char* pline;
    int i;
    
    
    fopen_s(&f1, "F1.txt", "r");
    if (f1 == NULL) {
        printf("Ошибка открытия файла F1.txt\n");
        return 1;
    }

    fopen_s(&f2, "F2.txt", "w");
    if (f2 == NULL) {
        printf("Ошибка открытия файла F2.txt\n");
        return 1;
    }
   
   
    i = 1; 
    while (fgets(line,sizeof(line),f1)!=NULL) { 
        if (i % 2 == 0) {
            fputs(line, f2);
        }
        i++;
    }
    
  
    fclose(f1);
    fclose(f2);

    printf("Программа успешно выполнена. Четные строки скопированы в файл F2.txt.\n");

    return 0;
}
