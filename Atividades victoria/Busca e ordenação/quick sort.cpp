#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função de partição
int partition(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    char* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// Função de quick sort
void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char* words[] = {"banana", "apple", "grape", "orange", "kiwi"};
    int size = sizeof(words) / sizeof(words[0]);
    
    printf("Antes de ordenar:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    quickSort(words, 0, size - 1);

    printf("\nApós ordenar:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

