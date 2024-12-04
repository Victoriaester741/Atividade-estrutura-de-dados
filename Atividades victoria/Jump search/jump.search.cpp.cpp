#include <stdio.h>
#include <math.h>
#include <time.h>

// Fun��o para Binary Search
int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

// Fun��o para Jump Search
int jump_search(int arr[], int size, int target) {
    int step = sqrt(size);  // Tamanho do salto � a raiz quadrada do tamanho da lista
    int prev = 0;

    // Saltando at� encontrar um bloco onde o valor pode estar
    printf("Iniciando Jump Search...\n");
    while (arr[(step < size) ? step : size] < target) {
        printf("Saltando para o �ndice %d\n", step);
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // N�o encontrou
        }
    }

    // Realiza busca linear no bloco
    printf("Buscando linearmente no intervalo de %d a %d...\n", prev, step < size ? step : size);
    for (int i = prev; i < (step < size ? step : size); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    
    return -1;
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

    // Medir o tempo para Binary Search
    clock_t start = clock();
    int result_binary = binary_search(arr, size, target);
    clock_t end = clock();
    double time_binary = (double)(end - start) / CLOCKS_PER_SEC;

    // Medir o tempo para Jump Search
    start = clock();
    int result_jump = jump_search(arr, size, target);
    end = clock();
    double time_jump = (double)(end - start) / CLOCKS_PER_SEC;

    // Exibir os tempos de execu��o
    if (result_binary != -1) {
        printf("Elemento encontrado no Binary Search no �ndice %d\n", result_binary);
    } else {
        printf("Elemento n�o encontrado no Binary Search\n");
    }

    if (result_jump != -1) {
        printf("Elemento encontrado no Jump Search no �ndice %d\n", result_jump);
    } else {
        printf("Elemento n�o encontrado no Jump Search\n");
    }

    // Exibir os tempos de execu��o
    printf("\nTempo de execu��o do Binary Search: %.6f segundos\n", time_binary);
    printf("Tempo de execu��o do Jump Search: %.6f segundos\n", time_jump);
}

int main() {
    // Teste de Jump Search e Binary Search
    measure_time();
    return 0;
}

