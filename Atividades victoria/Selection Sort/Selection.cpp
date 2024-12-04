#include <stdio.h>

// Fun��o para exibir a lista
void exibirLista(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fun��o Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i; // �ndice do menor elemento

        // Encontrar o menor elemento na parte n�o ordenada
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[menor]) {
                menor = j;
            }
        }

        // Trocar o menor elemento com o primeiro da parte n�o ordenada
        int temp = arr[menor];
        arr[menor] = arr[i];
        arr[i] = temp;

        // Mostrar a lista ap�s cada itera��o
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

