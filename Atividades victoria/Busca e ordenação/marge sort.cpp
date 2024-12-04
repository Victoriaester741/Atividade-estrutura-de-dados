#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função de merge
void merge(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char* leftArr[n1], *rightArr[n2];
    
    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) 
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função de merge sort
void mergeSort(char* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    char* words[] = {"banana", "apple", "grape", "orange", "kiwi"};
    int size = sizeof(words) / sizeof(words[0]);
    
    printf("Antes de ordenar:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    mergeSort(words, 0, size - 1);

    printf("\nApós ordenar:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

