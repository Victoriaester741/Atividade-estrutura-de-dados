#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALUNOS 10
#define MAX_NOTA 100

// Estrutura para armazenar dados de um aluno
typedef struct {
    char nome[100];
    int nota;
} Aluno;

// Função para realizar a troca de dois alunos
void swap(Aluno* a, Aluno* b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação Insertion Sort para ordenar os baldes
void insertionSort(Aluno alunos[], int n) {
    int i, j;
    Aluno key;
    for (i = 1; i < n; i++) {
        key = alunos[i];
        j = i - 1;
        
        while (j >= 0 && alunos[j].nota > key.nota) {
            alunos[j + 1] = alunos[j];
            j = j - 1;
        }
        alunos[j + 1] = key;
    }
}

// Função para realizar o Bucket Sort nas notas dos alunos
void bucketSort(Aluno alunos[], int n) {
    // Criar 101 baldes para notas entre 0 e 100
    Aluno* buckets[MAX_NOTA + 1];
    int bucketSizes[MAX_NOTA + 1];
    
    // Inicializa os baldes
    for (int i = 0; i <= MAX_NOTA; i++) {
        buckets[i] = (Aluno*) malloc(sizeof(Aluno) * n);
        bucketSizes[i] = 0;
    }

    // Distribui os alunos nos baldes de acordo com suas notas
    for (int i = 0; i < n; i++) {
        int index = alunos[i].nota;  // A nota serve como índice do balde
        buckets[index][bucketSizes[index]] = alunos[i];
        bucketSizes[index]++;
    }

    // Ordena cada balde individualmente usando Insertion Sort
    for (int i = 0; i <= MAX_NOTA; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Combina os baldes ordenados em um único array
    int index = 0;
    for (int i = 0; i <= MAX_NOTA; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            alunos[index] = buckets[i][j];
            index++;
        }
    }
}

// Função para realizar a busca Interpolation Search para encontrar um aluno por nota
int interpolationSearch(Aluno alunos[], int n, int chave) {
    int low = 0, high = n - 1;
    
    while (low <= high && chave >= alunos[low].nota && chave <= alunos[high].nota) {
        // Calcula a posição estimada com base na interpolação
        int pos = low + ((double)(high - low) / (alunos[high].nota - alunos[low].nota)) * (chave - alunos[low].nota);
        
        if (alunos[pos].nota == chave) {
            return pos;
        }
        
        if (alunos[pos].nota < chave) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;  // Nota não encontrada
}

int main() {
    // Lista de alunos e suas notas
    Aluno alunos[NUM_ALUNOS] = {
        {"Alice", 85},
        {"Bob", 70},
        {"Carlos", 95},
        {"Diana", 50},
        {"Eva", 78},
        {"Felipe", 92},
        {"Gabriel", 65},
        {"Heloisa", 88},
        {"Igor", 73},
        {"Julia", 91}
    };

    // Exibe as notas antes da ordenação
    printf("Antes da ordenação:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("%s: %d\n", alunos[i].nome, alunos[i].nota);
    }

    // Ordena os alunos pelas notas usando Bucket Sort
    bucketSort(alunos, NUM_ALUNOS);

    // Exibe as notas após a ordenação
    printf("\nApós ordenação (Bucket Sort):\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("%s: %d\n", alunos[i].nome, alunos[i].nota);
    }

    // Procurando um aluno com uma nota específica usando Interpolation Search
    int notaProcurada = 78;
    int index = interpolationSearch(alunos, NUM_ALUNOS, notaProcurada);

    if (index != -1) {
        printf("\nAluno com nota %d encontrado:\n", notaProcurada);
        printf("Nome: %s, Nota: %d\n", alunos[index].nome, alunos[index].nota);
    } else {
        printf("\nAluno com nota %d não encontrado.\n", notaProcurada);
    }

    return 0;
}

