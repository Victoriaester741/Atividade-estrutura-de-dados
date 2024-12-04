#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Fun��o para imprimir a lista
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fun��o de ordena��o Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fun��o de ordena��o Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
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

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

// Fun��o de ordena��o Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fun��o de busca Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Elemento encontrado
        }
    }
    return -1; // Elemento n�o encontrado
}

// Fun��o de busca Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; // Elemento encontrado

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Elemento n�o encontrado
}

// Fun��o para medir o tempo de execu��o
double measureExecutionTime(void (*func)(int[], int), int arr[], int size) {
    clock_t start = clock();
    func(arr, size);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Fun��o wrapper para Quick Sort
void quickSortWrapper(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

// Fun��o principal
int main() {
    int arr[MAX_SIZE];
    int n, choice, key;

    printf("Digite o tamanho da lista (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Gerar uma lista aleat�ria
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // N�meros aleat�rios entre 0 e 999
    }

    printf("\nEscolha o algoritmo de ordena��o:\n");
    printf("1. Bubble Sort\n2. Quick Sort\n3. Selection Sort\n");
    printf("Escolha: ");
    scanf("%d", &choice);

    double sortTime;
    switch (choice) {
        case 1:
            sortTime = measureExecutionTime(bubbleSort, arr, n);
            break;
        case 2:
            sortTime = measureExecutionTime(quickSortWrapper, arr, n);
            break;
        case 3:
            sortTime = measureExecutionTime(selectionSort, arr, n);
            break;
        default:
            printf("Op��o inv�lida!\n");
            return 1;
    }

    printf("\nLista ordenada:\n");
    printArray(arr, n);
    printf("Tempo de ordena��o: %.6f segundos\n", sortTime);

    printf("\nEscolha o algoritmo de busca:\n");
    printf("1. Linear Search\n2. Binary Search\n");
    printf("Escolha: ");
    scanf("%d", &choice);

    printf("\nDigite o valor a ser procurado: ");
    scanf("%d", &key);

    int result;
    double searchTime;
    switch (choice) {
        case 1:
            searchTime = measureExecutionTime((void (*)(int[], int))linearSearch, arr, n);
            result = linearSearch(arr, n, key);
            break;
        case 2:
            searchTime = measureExecutionTime((void (*)(int[], int))binarySearch, arr, n);
            result = binarySearch(arr, 0, n - 1, key);
            break;
        default:
            printf("Op��o inv�lida!\n");
            return 1;
    }

    if (result != -1) {
        printf("\nElemento %d encontrado na posi��o %d.\n", key, result);
    } else {
        printf("\nElemento %d n�o encontrado.\n", key);
    }
    
    printf("Tempo de busca: %.6f segundos\n", searchTime);

    return 0;
}

