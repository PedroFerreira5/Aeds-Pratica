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
    int *orig = &(*matriz)[0][0];
    int *dest;

    for (int offset = 0; offset < TAM * TAM; offset++) {
        int linha = offset / TAM; //offset deslocamento em relação ao início
        int coluna = offset % TAM;
        dest = temp + coluna * TAM + linha;

        *dest = *(orig + offset);
    }

    // Copiar de volta usando apenas ponteiros
    int *src = temp;
    int *dst = &(*matriz)[0][0];
    int *fim = dst + TAM * TAM;
    while (dst < fim) {
        *dst++ = *src++;
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
