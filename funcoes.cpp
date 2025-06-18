#include <iostream>
using namespace std;

// Função para exibir os elementos do vetor
void listagem(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Bubble Sort tradicional (ordem crescente)
void bubbleSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Insertion Sort tradicional (ordem crescente)
void insertionSort(int v[], int tam) {
    for (int i = 1; i < tam; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// Selection Sort tradicional (ordem crescente)
void selectionSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

// Bubble Sort com ponteiros (ordem crescente)
void bubbleSortPonteiros(int v[], int tam) {
    for (int *p = v; p < v + tam - 1; p++) {
        for (int *q = v; q < v + tam - 1 - (p - v); q++) {
            if (*q > *(q + 1)) {
                int aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
        }
    }
}

// Insertion Sort com ponteiros (ordem crescente)
void insertionSortPonteiros(int v[], int tam) {
    for (int *i = v + 1; i < v + tam; i++) {
        int chave = *i;
        int *j = i - 1;
        while (j >= v && *j > chave) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = chave;
    }
}

// Selection Sort com ponteiros (ordem crescente)
void selectionSortPonteiros(int v[], int tam) {
    for (int *i = v; i < v + tam - 1; i++) {
        int *min = i;
        for (int *j = i + 1; j < v + tam; j++) {
            if (*j < *min) {
                min = j;
            }
        }
        int aux = *i;
        *i = *min;
        *min = aux;
    }
}
