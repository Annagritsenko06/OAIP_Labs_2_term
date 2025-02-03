#include "MyQueue.h"


void view(Node* start) {                        //вывод элементов очереди 
	cout << "Очередь: " << endl;
	if (start != NULL)
	{
		while (start != NULL) {
			cout << start->el << " <- ";
			start = start->next;
		}
		cout << endl;
	}

	else
		cout << "Пуста" << endl;
}

void find_zero(Node*& start, Node*& end)
{
	int number = 0;
	if (start == NULL) {
		cout << "Очередь пуста!" << endl;
		return;
	}

	Node* temp = start;
	while (temp != NULL && temp->el != 0) {
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << "Нулевой элемент не найден." << endl;
		return;
	}
	else {
		while (start != temp) {
			cout << start->el << " ";
			number++;
			del(start, end);
		}
		cout << 0;
		cout<<endl;
		del(start, end);
		number++;
		cout << "Элементы до первого нулевого очищены" << endl;
		cout << number;
	}
}

void add_el_to_queue(Node*& start, Node*& end, int el) {
	
	Node* temp = new Node;
	temp->el = el;
	temp->next = NULL;

	if (start != NULL && end != NULL) {

		end->next = temp;
		end = temp;
	}
	else {
		start = end = temp;
	}

}

int del(Node*& start, Node*& end) {
	if (start != NULL && end != NULL) {

		Node* temp = start; int t;

		start = start->next;

		t = temp->el;
		temp->next = NULL;
		delete temp;

		return t;
	}
	else
		return 0;
}
int queue_length(Node* start, Node* end) {

	if (start != end && start != NULL && end != NULL) {
		int count = 0;
		while (start != NULL) {

			count++;
			start = start->next;

		}
		return count;
	}
	else
		return 0;
}





int max_queue(Node* start)
{
	if (start == NULL)
		return -404;

	int max = start->el;
	while (start != NULL) {
		if (max < start->el) {
			max = start->el;
		}
		start = start->next;
	}

	return max;
}

int getInt()
{
	int number;
	char c; /* Временная переменная для проверки ввода */

	/* Бесконечный цикл, работающий до момента удачного считывания */
	while (1)
	{
		/* Читаем поток ввода, необходимо число завершаемое
		* символом перевода на новую строку и никак иначе
		*/
		if (!scanf_s("%d", &number) || getchar() != '\n')
		{
			/* Очистка потока от оставшихся после чтения символов
			* для предотвращения их прочтения следующимим вызовами scanf
			*/
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else return number;

		printf("Необходимо ввести число.\nПовторите ввод: ");
	}
}

