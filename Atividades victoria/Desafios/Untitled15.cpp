#include <stdio.h>

// Função para imprimir o estado atual da lista
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    printf("\nInício do Bubble Sort:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Imprime o estado após cada iteração
        printf("Passo %d: ", i + 1);
        printArray(arr, n);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Partição após o pivô %d: ", arr[pi]);
        printArray(arr, high + 1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    printf("\nInício do Selection Sort:\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca os elementos
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        // Imprime o estado após cada iteração
        printf("Passo %d: ", i + 1);
        printArray(arr, n);
    }
}

// Função principal
int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Demonstrar o Bubble Sort
    bubbleSort(arr1, n);

    // Demonstrar o Quick Sort
    printf("\nInício do Quick Sort:\n");
    quickSort(arr2, 0, n - 1);

    // Demonstrar o Selection Sort
    selectionSort(arr3, n);

    return 0;
}

