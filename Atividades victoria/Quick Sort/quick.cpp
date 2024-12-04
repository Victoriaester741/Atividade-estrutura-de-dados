#include <stdio.h>

// Fun��o para trocar elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o de parti��o (escolha do piv� configur�vel)
int particionar(int arr[], int low, int high, int criterio) {
    int pivo;
    if (criterio == 1) { // Piv� como primeiro elemento
        pivo = arr[low];
    } else if (criterio == 2) { // Piv� como �ltimo elemento
        pivo = arr[high];
        trocar(&arr[low], &arr[high]);
    } else { // Piv� como elemento do meio
        int mid = low + (high - low) / 2;
        pivo = arr[mid];
        trocar(&arr[low], &arr[mid]);
    }

    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivo) i++;
        while (i <= j && arr[j] > pivo) j--;
        if (i < j) {
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[low], &arr[j]);
    return j;
}

// Fun��o Quick Sort recursiva
void quickSort(int arr[], int low, int high, int criterio) {
    if (low < high) {
        int p = particionar(arr, low, high, criterio);
        quickSort(arr, low, p - 1, criterio);
        quickSort(arr, p + 1, high, criterio);
    }
}

// Fun��o para exibir o array
void exibirLista(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fun��o principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    exibirLista(arr, n);

    // Quick Sort com piv� como primeiro elemento
    printf("\nQuick Sort com piv ocomo primeiro elemento:\n");
    int arr1[] = {10, 7, 8, 9, 1, 5};
    quickSort(arr1, 0, n - 1, 1);
    exibirLista(arr1, n);

    // Quick Sort com piv� como �ltimo elemento
    printf("\nQuick Sort com pivo como �ltimo elemento:\n");
    int arr2[] = {10, 7, 8, 9, 1, 5};
    quickSort(arr2, 0, n - 1, 2);
    exibirLista(arr2, n);

    // Quick Sort com piv� como elemento do meio
    printf("\nQuick Sort com pivo como elemento do meio:\n");
    int arr3[] = {10, 7, 8, 9, 1, 5};
    quickSort(arr3, 0, n - 1, 3);
    exibirLista(arr3, n);

    return 0;
}

