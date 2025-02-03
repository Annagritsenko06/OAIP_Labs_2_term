// ���������� #pragma once ��� �������������� �������� ��������� ������������� �����
#pragma once

// ��������� AAA � ����� ��������: Print() � GetPriority()
struct AAA
{
    int x;
    void Print();
    int GetPriority();
};

// ����������� ������������ ���� heap ��� �������� ��������� Heap � �� �������
namespace heap
{
    // ������������ CMP ��� ����������� ����������� ���������: LESS, EQUAL, GREAT
    enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };

    // ��������� Heap ��� ���������� ����
    struct Heap
    {
        int Size; // ������� ������ ����
        int MaxSize; // ������������ ������ ����
        void** Storage; // ��������� �� ������ ��������� ���� CMP(*Compare)(void*, void*); // ��������� �� ������� ��������� ���������
        CMP(*Compare)(void*, void*);
        // ����������� ��� �������� ���� � �������� ������������ �������� � �������� ���������
        Heap(int maxsize, CMP(*f)(void*, void*))
        {
            Size = 0;
            Storage = new void* [MaxSize = maxsize];
            Compare = f;
        }

        // ����������� ��� �������� ���� � �������� ������������ ��������, �������� ��������� � ��������� �������� ���������
        Heap(int maxsize, CMP(*f)(void*, void*), void* x[])
        {
            Size = 0;
            Storage = x;
            MaxSize = maxsize;
            Compare = f;
        }

        // ������ ��� ��������� �������� ������, ������� ������� � ������������� ����
        int Left(int ix);
        int Right(int ix);
        int Parent(int ix);

        // ������ ��� ��������, �������� �� ���� ������ ��� ������
        bool isFull()
        {
            return (Size >= MaxSize);
        }
        bool isEmpty()
        {
            return (Size <= 0);
        }

        // ������ ��� ��������, �������� �� ���� ������� ������, ������ ��� ����� ������� ��������
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

        // ����� ��� ������ ��������� � ����
        void Swap(int i, int j);

        // ����� ��� ����������� ������� ���� ����� ��������� ��������
        void Heapify(int ix);

            void Insert(void* x);

        // ����� ��� ���������� ������������� �������� �� ���� (��� max-heap)
        void* ExtractMax();

        // ����� ��� ������ ��������� ����
        void Scan(int i);

        // ����� ��� ���������� ������������ �������� �� ���� (��� min-heap)
        void* ExtractMin();

        // ����� ��� ���������� �������� �� ��������� �������
        void* ExtractI(int i);

        // ����� ��� ����������� ���� ���
      
        void Merge(Heap& otherHeap);
    };

    // ������� ��� �������� ���� � �������� ������������ �������� � �������� ���������
    Heap Create(int maxsize, CMP(*f)(void*, void*));
}

