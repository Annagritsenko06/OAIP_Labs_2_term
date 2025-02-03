// Используем #pragma once для предотвращения двойного включения заголовочного файла
#pragma once

// Структура AAA с двумя методами: Print() и GetPriority()
struct AAA
{
    int x;
    void Print();
    int GetPriority();
};

// Определение пространства имен heap для хранения структуры Heap и ее функций
namespace heap
{
    // Перечисление CMP для определения результатов сравнения: LESS, EQUAL, GREAT
    enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };

    // Структура Heap для реализации кучи
    struct Heap
    {
        int Size; // Текущий размер кучи
        int MaxSize; // Максимальный размер кучи
        void** Storage; // Указатель на массив элементов кучи CMP(*Compare)(void*, void*); // Указатель на функцию сравнения элементов
        CMP(*Compare)(void*, void*);
        // Конструктор для создания кучи с заданным максимальным размером и функцией сравнения
        Heap(int maxsize, CMP(*f)(void*, void*))
        {
            Size = 0;
            Storage = new void* [MaxSize = maxsize];
            Compare = f;
        }

        // Конструктор для создания кучи с заданным максимальным размером, функцией сравнения и начальным массивом элементов
        Heap(int maxsize, CMP(*f)(void*, void*), void* x[])
        {
            Size = 0;
            Storage = x;
            MaxSize = maxsize;
            Compare = f;
        }

        // Методы для получения индексов левого, правого потомка и родительского узла
        int Left(int ix);
        int Right(int ix);
        int Parent(int ix);

        // Методы для проверки, является ли куча полной или пустой
        bool isFull()
        {
            return (Size >= MaxSize);
        }
        bool isEmpty()
        {
            return (Size <= 0);
        }

        // Методы для проверки, является ли один элемент меньше, больше или равен другому элементу
        bool isLess(void* x1, void* x2)
        {
            return Compare(x1, x2) == LESS;
        }
        bool isGreat(void* x1, void* x2)
        {
            return Compare(x1, x2) == GREAT;
        }
        bool isEqual(void* x1, void* x2)
        {
            return Compare(x1, x2) == EQUAL;
        }

        // Метод для обмена элементов в куче
        void Swap(int i, int j);

        // Метод для поддержания свойств кучи после изменения элемента
        void Heapify(int ix);

            void Insert(void* x);

        // Метод для извлечения максимального элемента из кучи (для max-heap)
        void* ExtractMax();

        // Метод для обхода элементов кучи
        void Scan(int i);

        // Метод для извлечения минимального элемента из кучи (для min-heap)
        void* ExtractMin();

        // Метод для извлечения элемента по заданному индексу
        void* ExtractI(int i);

        // Метод для объединения двух куч
      
        void Merge(Heap& otherHeap);
    };

    // Функция для создания кучи с заданным максимальным размером и функцией сравнения
    Heap Create(int maxsize, CMP(*f)(void*, void*));
}

