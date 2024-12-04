#include <stdio.h>
#include <string.h>

int binarySearch(char* arr[], int size, char* target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(arr[mid], target);
        
        if (cmp == 0) {
            return mid;  // Palavra encontrada
        }
        else if (cmp < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return -1;  // Palavra n�o encontrada
}

int main() {
    char* words[] = {"apple", "banana", "grape", "kiwi", "orange"};
    int size = sizeof(words) / sizeof(words[0]);
    
    char* target = "kiwi";
    int index = binarySearch(words, size, target);
    
    if (index != -1) {
        printf("Palavra '%s' encontrada na posi��o %d.\n", target, index);
    } else {
        printf("Palavra '%s' n�o encontrada.\n", target);
    }

    return 0;
}

