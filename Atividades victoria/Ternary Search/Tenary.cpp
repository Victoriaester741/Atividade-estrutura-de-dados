#include <stdio.h>

// Função de Ternary Search
int ternarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == target) {
            return mid1; // Elemento encontrado em mid1
        }
        if (arr[mid2] == target) {
            return mid2; // Elemento encontrado em mid2
        }

        if (target < arr[mid1]) {
            high = mid1 - 1; // Reduz a busca ao primeiro terço
        } else if (target > arr[mid2]) {
            low = mid2 + 1; // Reduz a busca ao último terço
        } else {
            low = mid1 + 1;
            high = mid2 - 1; // Reduz a busca ao terço central
        }
    }
    return -1; // Elemento não encontrado
}

// Função de Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // Elemento encontrado
        }
        if (target < arr[mid]) {
            high = mid - 1; // Busca na metade inferior
        } else {
            low = mid + 1; // Busca na metade superior
        }
    }
    return -1; // Elemento não encontrado
}

// Função principal para comparar os algoritmos
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Ternary Search
    int resultTernary = ternarySearch(arr, 0, n - 1, target);
    if (resultTernary != -1) {
        printf("Ternary Search: Elemento encontrado no indice %d\n", resultTernary);
    } else {
        printf("Ternary Search: Elemento não encontrado\n");
    }

    // Binary Search
    int resultBinary = binarySearch(arr, 0, n - 1, target);
    if (resultBinary != -1) {
        printf("Binary Search: Elemento encontrado no indice %d\n", resultBinary);
    } else {
        printf("Binary Search: Elemento não encontrado\n");
    }

    return 0;
}

