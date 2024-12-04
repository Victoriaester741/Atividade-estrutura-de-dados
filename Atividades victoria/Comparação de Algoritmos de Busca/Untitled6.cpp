#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Função de Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Função de Interpolation Search
int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == target) return pos;
        else if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

// Função de Jump Search
int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[step < size ? step : size - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) return -1;
    }
    for (int i = prev; i < (step < size ? step : size); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Função de Exponential Search
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < size && arr[i] <= target) i *= 2;
    return binarySearch(arr, i < size ? i : size, target);
}

// Função para gerar um array ordenado
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Preenche o array com valores 1, 2, 3, ...
    }
}

// Função para medir o tempo de execução
double measureTime(int (*searchFunc)(int[], int, int), int arr[], int size, int target) {
    clock_t start = clock();
    searchFunc(arr, size, target);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Função principal
int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    int target = 100000; // Garantido que está no final da lista para todos os casos
    printf("Tamanho\tBinary Search\tInterpolation Search\tJump Search\tExponential Search\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));
        generateArray(arr, size);

        double binaryTime = measureTime(binarySearch, arr, size, target);
        double interpolationTime = measureTime(interpolationSearch, arr, size, target);
        double jumpTime = measureTime(jumpSearch, arr, size, target);
        double exponentialTime = measureTime(exponentialSearch, arr, size, target);

        printf("%d\t%.6f\t\t%.6f\t\t\t%.6f\t\t%.6f\n", size, binaryTime, interpolationTime, jumpTime, exponentialTime);

        free(arr);
    }

    return 0;
}

