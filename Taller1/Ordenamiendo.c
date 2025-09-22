#include <stdio.h>


void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int tiempos[10] = {45, 23, 89, 12, 56, 78, 34, 67, 91, 5};
    int n = 10;

    printf("Arreglo original: ");
    imprimirArreglo(tiempos, n);

    
    selectionSort(tiempos, n);
    printf("Arreglo ordenado con Selection Sort (menor a mayor): ");
    imprimirArreglo(tiempos, n);
    

    insertionSort(tiempos, n);
    printf("Arreglo ordenado con Insertion Sort (mayor a menor): ");
    imprimirArreglo(tiempos, n);

    return 0;
}