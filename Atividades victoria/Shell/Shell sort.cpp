#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar o Shell Sort com a sequência de intervalos de Shell
void shellSortShell(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para realizar o Shell Sort com a sequência de intervalos de Knuth
void shellSortKnuth(int arr[], int n) {
    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    for (; gap > 0; gap /= 3) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para realizar o Shell Sort com a sequência de intervalos de Hibbard
void shellSortHibbard(int arr[], int n) {
    int gap = 1;
    while (gap < n) {
        gap = 2 * gap + 1;
    }

    for (; gap > 0; gap = (gap - 1) / 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para medir o tempo de execução do algoritmo
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal para testar as implementações
int main() {
    int n = 1000;  // Tamanho do array
    int arrShell[n], arrKnuth[n], arrHibbard[n];
    
    // Preenche os arrays com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int value = rand() % 1000;
        arrShell[i] = value;
        arrKnuth[i] = value;
        arrHibbard[i] = value;
    }

    // Testa o Shell Sort com a sequência de intervalos de Shell
    double timeShell = measureTime(shellSortShell, arrShell, n);
    printf("Shell Sort (Shell): %.6f segundos\n", timeShell);

    // Testa o Shell Sort com a sequência de intervalos de Knuth
    double timeKnuth = measureTime(shellSortKnuth, arrKnuth, n);
    printf("Shell Sort (Knuth): %.6f segundos\n", timeKnuth);

    // Testa o Shell Sort com a sequência de intervalos de Hibbard
    double timeHibbard = measureTime(shellSortHibbard, arrHibbard, n);
    printf("Shell Sort (Hibbard): %.6f segundos\n", timeHibbard);

    return 0;
}

