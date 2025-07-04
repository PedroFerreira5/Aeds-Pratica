#include "operacoes_matrizes.h"

void multiplicar_matriz(Vetor *matriz, int escalar) {
    int *ptr = &(*matriz)[0][0];
    int *fim = ptr + TAM * TAM;

    while (ptr < fim) {
        *ptr *= escalar;
        ptr++;
    }
}

void transpor_matriz(Vetor *matriz) {
    int temp[TAM * TAM];
    int *src = &(*matriz)[0][0];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            *(temp + j * TAM + i) = *(src + i * TAM + j);
        }
    }

    int *dst = &(*matriz)[0][0];
    for (int i = 0; i < TAM * TAM; i++) {
        *(dst + i) = *(temp + i);
    }
}

void inverter_colunas(Vetor *matriz) {
    int *linha = &(*matriz)[0][0];

    for (int i = 0; i < TAM; i++) {
        int *esquerda = linha;
        int *direita = linha + TAM - 1;

        while (esquerda < direita) {
            int temp = *esquerda;
            *esquerda = *direita;
            *direita = temp;
            esquerda++;
            direita--;
        }

        linha += TAM;
    }
}

void inverter_linhas(Vetor *matriz) {
    int *cima = &(*matriz)[0][0];
    int *baixo = cima + (TAM - 1) * TAM;

    for (int i = 0; i < TAM / 2; i++) {
        int *ptr_cima = cima;
        int *ptr_baixo = baixo;

        for (int j = 0; j < TAM; j++) {
            int temp = *ptr_cima;
            *ptr_cima = *ptr_baixo;
            *ptr_baixo = temp;
            ptr_cima++;
            ptr_baixo++;
        }

        cima += TAM;
        baixo -= TAM;
    }
}
