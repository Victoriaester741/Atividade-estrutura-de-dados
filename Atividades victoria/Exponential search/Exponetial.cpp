#include <stdio.h>
#include <math.h>
#include <time.h>

// Fun��o para Binary Search (usada ap�s encontrar o intervalo)
int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Fun��o para Exponential Search
int exponential_search(int arr[], int size, int target) {
    // Se o primeiro elemento � o alvo
    if (arr[0] == target) {
        return 0;
    }

    // Encontrando o intervalo onde o alvo pode estar
    int index = 1;
    while (index < size && arr[index] <= target) {
        index *= 2;  // Dobra o �ndice progressivamente
    }

    // Agora, fa�a Binary Search no intervalo encontrado
    return binary_search(arr, index / 2, index < size ? index : size - 1, target);
}

// Fun��o para medir o tempo de execu��o
void measure_time() {
    // Lista de teste com n�meros de 1 a 1 milh�o
    int size = 1000000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Preencher a lista com valores de 1 a 1 milh�o
    }

    int target = 999999;  // Valor a ser buscado

    // Medir o tempo para Exponential Search
    clock_t start = clock();
    int result_exp = exponential_search(arr, size, target);
    clock_t end = clock();
    double time_exp = (double)(end - start) / CLOCKS_PER_SEC;

    // Exibir o tempo de execu��o e o resultado da busca
    if (result_exp != -1) {
        printf("Elemento encontrado no Exponential Search no �ndice %d\n", result_exp);
    } else {
        printf("Elemento n�o encontrado no Exponential Search\n");
    }

    printf("\nTempo de execu��o do Exponential Search: %.6f segundos\n", time_exp);
}

int main() {
    // Teste de Exponential Search
    measure_time();
    return 0;
}

