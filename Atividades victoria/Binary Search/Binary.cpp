#include <stdio.h>

// Fun��o para implementar o algoritmo de Binary Search
int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;  // Encontra o �ndice do meio
        
        if (arr[mid] == target) {
            return mid;  // Elemento encontrado, retorna o �ndice
        }
        else if (arr[mid] < target) {
            low = mid + 1;  // O alvo est� � direita
        } else {
            high = mid - 1;  // O alvo est� � esquerda
        }
    }
    
    return -1;  // Elemento n�o encontrado
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};  // Lista ordenada
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binary_search(arr, size, target);
    
    if (result != -1) {
        printf("Elemento encontrado no indice %d\n", result);
    } else {
        printf("Elemento n�o encontrado\n");
    }
    
    return 0;
}

