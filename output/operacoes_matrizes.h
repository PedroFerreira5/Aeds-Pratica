#ifndef OPERACOES_MATRIZES_H
#define OPERACOES_MATRIZES_H

const int TAM = 128;
typedef int Vetor[TAM][TAM];

// Multiplica todos os elementos da matriz por um valor
void multiplicar_matriz(Vetor *matriz, int escalar);

// Encontra a matriz transposta
void transpor_matriz(Vetor *matriz);

// Inverte as colunas na horizontal (primeira se torna a última, etc.)
void inverter_colunas(Vetor *matriz);

// Inverte as linhas na vertical (primeira se torna a última, etc.)
void inverter_linhas(Vetor *matriz);

#endif // OPERACOES_MATRIZES_H
