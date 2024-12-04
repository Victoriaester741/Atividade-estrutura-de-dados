#include <stdio.h>
#include <stdlib.h>

// Função de ordenação por inserção
void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para Bucket Sort para inteiros
void bucketSortIntegers(int arr[], int n, int range_size) {
    int bucketCount = (100 / range_size) + 1; // Determina o número de baldes
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *sizes = (int *)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        sizes[i] = 0;
    }

    // Distribuir os números nos baldes
    for (int i = 0; i < n; i++) {
        int index = arr[i] / range_size; // Determina o balde
        buckets[index][sizes[index]++] = arr[i];
    }

    // Ordenar cada balde
    for (int i = 0; i < bucketCount; i++) {
        insertionSortInt(buckets[i], sizes[i]);
    }

    // Combinar os baldes
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Liberar memória dos baldes
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(sizes);
}

// Função principal
int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range_size = 10; // Intervalo dos baldes

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSortIntegers(arr, n, range_size);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

