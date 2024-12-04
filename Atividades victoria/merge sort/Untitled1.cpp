#include <stdio.h>
#include <string.h>

// Função para mesclar dois subarrays de strings ordenados
void mergeStrings(char arr[][50], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][50], R[n2][50];

    // Copiar elementos para subarrays temporários
    for (int i = 0; i < n1; i++)
        strcpy(L[i], arr[left + i]);
    for (int j = 0; j < n2; j++)
        strcpy(R[j], arr[mid + 1 + j]);

    int i = 0, j = 0, k = left;

    // Mesclar os subarrays
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

// Função recursiva do Merge Sort para strings
void mergeSortStrings(char arr[][50], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortStrings(arr, left, mid);
        mergeSortStrings(arr, mid + 1, right);

        mergeStrings(arr, left, mid, right);
    }
}

// Função principal
int main() {
    char arr[][50] = {"banana", "laranja", "maca", "uva", "abacaxi"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    mergeSortStrings(arr, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}

