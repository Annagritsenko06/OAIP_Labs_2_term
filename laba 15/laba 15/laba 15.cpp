#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

// Функция для пирамидальной сортировки
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Функция для сортировки слиянием
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    
        setlocale(LC_CTYPE, "RUS");
    int n;
    std::cout << "Введите количество элементов в массиве A: ";
    std::cin >> n;

    int* A = new int[n];

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение массива A случайными числами
    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 100; // Случайные числа от 0 до 99
    }

    std::cout << "Массив A: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    int* B = new int[n];
    int B_size = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] % 2 == 0) {
            B[B_size++] = A[i];
        }
    }

    int* B_heap_sorted = new int[B_size];
    int* B_merge_sorted = new int[B_size];
    std::copy(B, B + B_size, B_heap_sorted);
    std::copy(B, B + B_size, B_merge_sorted);

    // Пирамидальная сортировка
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(B_heap_sorted, B_size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Массив B, отсортированный пирамидальной сортировкой: ";
    for (int i = 0; i < B_size; ++i) {
        std::cout << B_heap_sorted[i] << " ";
    }
    std::cout << "\nВремя работы пирамидальной сортировки: " << duration.count() << " секунд" << std::endl;

    // Сортировка слиянием
    start = std::chrono::high_resolution_clock::now();
    mergeSort(B_merge_sorted, 0, B_size - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Массив B, отсортированный сортировкой слиянием: ";
    for (int i = 0; i < B_size; ++i) {
        std::cout << B_merge_sorted[i] << " ";
    }
    std::cout << "\nВремя работы сортировки слиянием: " << duration.count() << " секунд" << std::endl;

    delete[] A;
    delete[] B;
    delete[] B_heap_sorted;
    delete[] B_merge_sorted;

    return 0;
}


