#include "Heap.h" 
#include <iostream> 
#include <iomanip> 
using namespace std; 

// Реализация методов структуры AAA
void AAA::Print()
{
	std::cout << x; // Вывод значения поля x объекта AAA
}

int AAA::GetPriority()
{
	return x; // Возврат значения поля x как приоритета объекта AAA
}
namespace heap
{   // Создание кучи с заданным максимальным размером и функцией сравнения
	Heap Create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}

	// Получение индекса правого потомка узла с заданным индексом
	int Heap::Left(int ix)
	{
		return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);
	}

	// Получение индекса правого потомка узла с заданным индексом
	int Heap::Right(int ix)
	{
		return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);
	}
	// Получение индекса родительского узла узла с заданным индексом
	int Heap::Parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	// Обмен значениями двух узлов кучи
	void Heap::Swap(int i, int j)
	{
		void* buf = Storage[i];
		Storage[i] = Storage[j];
		Storage[j] = buf;
	}
	// Процедура для поддержания свойств кучи после изменения
	void Heap::Heapify(int ix)
	{
		int l = Left(ix), r = Right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(Storage[l], Storage[ix]))
				irl = l;

			if (r > 0 && isGreat(Storage[r], Storage[irl]))

				irl = r;

			if (irl != ix)
			{
				Swap(ix, irl);
				Heapify(irl);
			}
		}
	}
	// Вставка элемента в кучу
	/*void Heap::Insert(void* x)
	{
		int i;
		if (!isFull())
		{
			i = Size;
			Storage[i] = x;
			Size++;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i])) {
				Swap(Parent(i), i);
				i = Parent(i);
			}
		}
	}*/
	//// Извлечение максимального элемента из кучи
	//void* Heap::ExtractMax()
	//{
	//	void* rc = NULL;
	//	if (!isEmpty())
	//	{
	//		rc = Storage[0];
	//		Storage[0] = Storage[Size - 1];
	//		Size--;
	//		Heapify(0);
	//	}
	//	Heapify(0);
	//	return rc;
	//}
	// Вывод кучи на экран
	void Heap::Scan(int i)
	{
		int probel = 20;
		std::cout << '\n';
		if (Size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0, level = 1; u < Size; u++)

		{
			cout << setw(probel + 10) << setfill(' ');

			((AAA*)Storage[u])->Print();
			if (u == y)
			{
				level++;
				cout << '\n';
				if (y == 0)
					y = 2;
				else y = pow(2, level) - 2;
			}
			probel /= 2;
			
		}
		cout << '\n';
	}
	//// Извлечение минимального элемента из кучи
	//void* Heap::ExtractMin()
	//{
	//	void* rc = NULL;
	//	if (Size > 0)
	//	{
	//		int j = Size / 2;
	//		for (int i = Size / 2; i < Size; i++)

	//		{
	//			if (Compare(Storage[i], Storage[j]) == LESS)

	//			{
	//				j = i;
	//			}
	//		}
	//		rc = Storage[j];
	//		Swap(j, Size - 1);
	//		Size--;
	//	}
	//	Heapify(0);
	//	return rc;
	//}

	//// Извлечение i-го элемента из кучи
	//void* Heap::ExtractI(int i)
	//{
	//	void* rc = NULL;
	//	if (Size > 0 && i >= 0 && i < Size)
	//	{
	//		rc = Storage[i];
	//		Swap(i, Size - 1);
	//		Size--;
	//	}
	//	Heapify(0);
	//	return rc;
	//}

	void Heap::Merge(Heap& otherHeap)
	{
		// Объединяем массивы элементов двух куч
		for (int i = 0; i < otherHeap.Size; ++i) {
			// Вставляем элементы из другой кучи в текущую
			Insert(otherHeap.Storage[i]);
		}

		// После вставки всех элементов нужно выполнить Heapify для поддержания свойств кучи
		for (int i = Size / 2 - 1; i >= 0; --i) {
			Heapify(i);
		}
		
	}

}


namespace heap
{
	// Вставка элемента в кучу
	void Heap::Insert(void* x)
	{
		int i;
		if (!isFull())
		{
			i = Size;
			Storage[i] = x;
			Size++;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))
			{
				Swap(Parent(i), i);
				i = Parent(i);
			}
		}
	}

	// Извлечение максимального элемента из кучи
	void* Heap::ExtractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = Storage[0];
			Storage[0] = Storage[Size - 1];
			Size--;
			Heapify(0);
		}
		return rc;
	}

	// Извлечение минимального элемента из кучи
	void* Heap::ExtractMin()
	{
		void* rc = nullptr;
		if (Size > 0)
		{
			int j = Size / 2;
			for (int i = Size / 2; i < Size; i++)
			{
				if (Compare(Storage[i], Storage[j]) == LESS)
				{
					j = i;
				}
			}
			rc = Storage[j];
			Swap(j, Size - 1);
			Size--;
		}
		Heapify(0);
		return rc;
	}

	// Извлечение i-го элемента из кучи
	void* Heap::ExtractI(int i)
	{
		void* rc = nullptr;
		if (Size > 0 && i >= 0 && i < Size)
		{
			rc = Storage[i];
			Swap(i, Size - 1);
			Size--;
			Heapify(i);
		}
		return rc;
	}
}

