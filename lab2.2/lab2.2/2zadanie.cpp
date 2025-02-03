#include <stdio.h>
#include <math.h>
#include <iostream>
int main() {
    setlocale(LC_CTYPE,"rus");
    FILE* fA;
    float userNumber, currentNumber, closestNumber;
    int lineNumber = 0;
    int position=0;
    float minDistance = INFINITY;

    fopen_s(&fA,"fA.txt", "r");
    if (fA == NULL) {
        printf("������ ��� �������� ����� fA\n");
        return 1;
    }


    printf("������� ����� �����: ");
    scanf_s("%f", &userNumber);

    
    while (fscanf_s(fA, "%f", &currentNumber) == 1) {
        lineNumber++;

   
        float distance = fabs(userNumber - currentNumber);
        
    
        if (distance < minDistance) {
            minDistance = distance;
            closestNumber = currentNumber;
            position = lineNumber;
        }
    }

    fclose(fA);

 
    printf("�������� ������� ����� � ����������: %.2f (������� �����: %d)\n",  closestNumber, position);

    return 0;
}


