#include <stdio.h>

// Função para exibir a lista
void exibirLista(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i; // Índice do menor elemento

        // Encontrar o menor elemento na parte não ordenada
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[menor]) {
                menor = j;
            }
        }

        // Trocar o menor elemento com o primeiro da parte não ordenada
        int temp = arr[menor];
        arr[menor] = arr[i];
        arr[i] = temp;

        // Mostrar a lista após cada iteração
        printf("Iteracao %d: ", i + 1);
        exibirLista(arr, n);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Lista original: ");
    exibirLista(arr, n);

    selectionSort(arr, n);

    printf("Lista ordenada: ");
    exibirLista(arr, n);

    return 0;
}

