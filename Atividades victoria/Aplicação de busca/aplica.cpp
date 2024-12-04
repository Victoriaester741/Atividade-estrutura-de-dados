#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados do livro
typedef struct {
    char titulo[100];
    char autor[100];
    char isbn[20];  // ISBN como string (para suportar diferentes formatos)
} Livro;

// Função de comparação para ordenar os livros por ISBN (usando strcmp)
int compararISBN(const void* a, const void* b) {
    return strcmp(((Livro*)a)->isbn, ((Livro*)b)->isbn);
}

// Função de busca binária para procurar um livro pelo ISBN
int binarySearch(Livro livros[], int tamanho, const char* isbn) {
    int low = 0, high = tamanho - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(livros[mid].isbn, isbn);
        
        if (cmp == 0) {
            return mid;  // ISBN encontrado
        }
        else if (cmp < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return -1;  // ISBN não encontrado
}

int main() {
    // Lista de livros (não ordenada inicialmente)
    Livro biblioteca[] = {
        {"O Alquimista", "Paulo Coelho", "978-85-325-0109-3"},
        {"1984", "George Orwell", "978-0-452-28423-4"},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", "978-0-345-33973-3"},
        {"Dom Quixote", "Miguel de Cervantes", "978-85-359-0277-5"},
        {"Cem Anos de Solidão", "Gabriel García Márquez", "978-85-207-5074-0"}
    };
    
    int tamanho = sizeof(biblioteca) / sizeof(biblioteca[0]);

    // Ordenar a lista de livros por ISBN
    qsort(biblioteca, tamanho, sizeof(Livro), compararISBN);

    // ISBN a ser procurado
    char isbnProcurado[] = "978-0-452-28423-4";

    // Busca binária para encontrar o livro pelo ISBN
    int index = binarySearch(biblioteca, tamanho, isbnProcurado);

    if (index != -1) {
        printf("Livro encontrado:\n");
        printf("Título: %s\n", biblioteca[index].titulo);
        printf("Autor: %s\n", biblioteca[index].autor);
        printf("ISBN: %s\n", biblioteca[index].isbn);
    } else {
        printf("Livro com ISBN %s não encontrado.\n", isbnProcurado);
    }

    return 0;
}

