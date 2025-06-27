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
    Vetor temp;
    int *src = &(*matriz)[0][0];
    int *dst = &temp[0][0];
    
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            *(&temp[j][i]) = *src;
            src++;
        }
    }
    
    // Copia a matriz transposta de volta
    src = &temp[0][0];
    dst = &(*matriz)[0][0];
    int *fim = dst + TAM * TAM;
    while (dst < fim) {
        *dst = *src;
        dst++;
        src++;
    }
}

void inverter_colunas(Vetor *matriz) {
    for (int i = 0; i < TAM; i++) {
        int *esquerda = &(*matriz)[i][0];
        int *direita = &(*matriz)[i][TAM - 1];
        
        while (esquerda < direita) {
            int temp = *esquerda;
            *esquerda = *direita;
            *direita = temp;
            esquerda++;
            direita--;
        }
    }
}

void inverter_linhas(Vetor *matriz) {
    int *cima = &(*matriz)[0][0];
    int *baixo = &(*matriz)[TAM - 1][0];
    
    while (cima < baixo) {
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
