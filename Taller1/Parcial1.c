#include <stdio.h>


typedef struct {
    int codigo;
    float nota;
} Estudiante;


Estudiante estudiantes[] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.8},
    {2024104, 3.9},
    {2024105, 4.8}
};
int n = sizeof(estudiantes) / sizeof(estudiantes[0]);


float notaMaxima(Estudiante arr[], int i, int n) {
    if (i == n - 1) 
        return arr[i].nota;  // caso base
    float maxRestante = notaMaxima(arr, i + 1, n);
    return (arr[i].nota > maxRestante) ? arr[i].nota : maxRestante;
}


float promedioNotas(Estudiante arr[], int i, int n) {
    if (i == n - 1)
        return arr[i].nota;  // caso base
    return arr[i].nota + promedioNotas(arr, i + 1, n);
}


int indiceMin(Estudiante arr[], int inicio, int n) {
    if (inicio == n - 1) return inicio;
    int idxMinResto = indiceMin(arr, inicio + 1, n);
    return (arr[inicio].codigo < arr[idxMinResto].codigo) ? inicio : idxMinResto;
}


void selectionSortRec(Estudiante arr[], int inicio, int n) {
    if (inicio >= n - 1) return;  // caso base
    int idxMin = indiceMin(arr, inicio, n);
    

    if (idxMin != inicio) {
        Estudiante temp = arr[inicio];
        arr[inicio] = arr[idxMin];
        arr[idxMin] = temp;
    }
    selectionSortRec(arr, inicio + 1, n);
}


void mostrarLista(Estudiante arr[], int n) {
    printf("\nLista de Estudiantes:\n");
    for (int i = 0; i < n; i++) {
        printf("Código: %d | Nota: %.2f\n", arr[i].codigo, arr[i].nota);
    }
    printf("\n");
}

int main() {
    int opcion;
    do {
        printf("\n===== MENÚ APLICACIÓN =====\n");
        printf("1. Buscar Nota Máxima\n");
        printf("2. Calcular Promedio del Curso\n");
        printf("3. Ordenar Códigos (Selection Sort Recursivo)\n");
        printf("4. Mostrar Lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                float max = notaMaxima(estudiantes, 0, n);
                printf("\nLa nota máxima es: %.2f\n", max);
                break;
            }
            case 2: {
                float suma = promedioNotas(estudiantes, 0, n);
                printf("\nEl promedio del curso es: %.2f\n", suma / n);
                break;
            }
            case 3:
                selectionSortRec(estudiantes, 0, n);
                printf("\nLista ordenada por código.\n");
                mostrarLista(estudiantes, n);
                break;
            case 4:
                mostrarLista(estudiantes, n);
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción inválida, intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
