#include <stdio.h>

// Função para Binary Search
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

// Função para Interpolation Search
int interpolation_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[high] == arr[low]) {
            break;
        }
        
        // Calcular a posição estimada com base na fórmula de interpolação
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

void test_search_algorithms() {
    // Lista com intervalo uniforme
    int arr_uniform[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size_uniform = sizeof(arr_uniform) / sizeof(arr_uniform[0]);
    
    int target;
    printf("Digite o numero que voce deseja buscar: ");
    scanf("%d", &target);
    
    printf("\nTestando Binary Search com intervalo uniforme:\n");
    int result_binary = binary_search(arr_uniform, size_uniform, target);
    if (result_binary != -1) {
        printf("Elemento encontrado no indice %d\n", result_binary);
    } else {
        printf("Elemento não encontrado\n");
    }

    printf("Testando Interpolation Search com intervalo uniforme:\n");
    int result_interpolation = interpolation_search(arr_uniform, size_uniform, target);
    if (result_interpolation != -1) {
        printf("Elemento encontrado no indice %d\n", result_interpolation);
    } else {
        printf("Elemento não encontrado\n");
    }
    
    // Lista com intervalo não uniforme
    int arr_non_uniform[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int size_non_uniform = sizeof(arr_non_uniform) / sizeof(arr_non_uniform[0]);
    
    printf("\nTestando Binary Search com intervalo nao uniforme:\n");
    result_binary = binary_search(arr_non_uniform, size_non_uniform, target);
    if (result_binary != -1) {
        printf("Elemento encontrado no indice %d\n", result_binary);
    } else {
        printf("Elemento não encontrado\n");
    }

    printf("Testando Interpolation Search com intervalo nao uniforme:\n");
    result_interpolation = interpolation_search(arr_non_uniform, size_non_uniform, target);
    if (result_interpolation != -1) {
        printf("Elemento encontrado no indice %d\n", result_interpolation);
    } else {
        printf("Elemento não encontrado\n");
    }
}

int main() {
    test_search_algorithms();
    return 0;
}


