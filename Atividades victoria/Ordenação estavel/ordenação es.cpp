#include <stdio.h>
#include <string.h>

// Estrutura para armazenar dados de aluno (nota, nome)
typedef struct {
    int nota;
    char nome[50];
} Aluno;

// Fun��o de ordena��o Bubble Sort (Est�vel)
void bubbleSort(Aluno alunos[], int n) {
    int i, j;
    Aluno temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (alunos[j].nota > alunos[j + 1].nota) {
                // Troca os alunos
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

// Fun��o de ordena��o Quick Sort (Inst�vel)
int partition(Aluno alunos[], int low, int high) {
    int pivot = alunos[high].nota;
    int i = low - 1;
    Aluno temp;

    for (int j = low; j < high; j++) {
        if (alunos[j].nota < pivot) {
            i++;
            temp = alunos[i];
            alunos[i] = alunos[j];
            alunos[j] = temp;
        }
    }

    temp = alunos[i + 1];
    alunos[i + 1] = alunos[high];
    alunos[high] = temp;
    return i + 1;
}

void quickSort(Aluno alunos[], int low, int high) {
    if (low < high) {
        int pi = partition(alunos, low, high);
        quickSort(alunos, low, pi - 1);
        quickSort(alunos, pi + 1, high);
    }
}

// Fun��o para imprimir a lista de alunos
void printAlunos(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nota: %d, Nome: %s\n", alunos[i].nota, alunos[i].nome);
    }
    printf("\n");
}

int main() {
    // Lista de alunos (nota, nome)
    Aluno alunos[] = {
        {85, "Alice"},
        {70, "Bob"},
        {85, "Carlos"},
        {50, "Diana"},
        {78, "Eva"}
    };
    int n = sizeof(alunos) / sizeof(alunos[0]);

    printf("Antes da ordena��o (Bubble Sort):\n");
    printAlunos(alunos, n);

    // Ordenando com Bubble Sort (est�vel)
    bubbleSort(alunos, n);
    printf("Ap�s Bubble Sort (Est�vel):\n");
    printAlunos(alunos, n);

    // Lista de alunos para Quick Sort (inst�vel)
    Aluno alunosQuick[] = {
        {85, "Alice"},
        {70, "Bob"},
        {85, "Carlos"},
        {50, "Diana"},
        {78, "Eva"}
    };

    printf("Antes da ordena��o (Quick Sort):\n");
    printAlunos(alunosQuick, n);

    // Ordenando com Quick Sort (inst�vel)
    quickSort(alunosQuick, 0, n - 1);
    printf("Ap�s Quick Sort (Inst�vel):\n");
    printAlunos(alunosQuick, n);

    return 0;
}

