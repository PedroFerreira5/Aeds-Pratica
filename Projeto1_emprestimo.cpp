/*
 * Author: Pedro Ferreira Prado
 * RA : 2025.1.08.028   
 * Disciplina : AEDS 1 PRÁTICA
 * Created on 24 de março de 2025, 10:15
 * *  OBJETIVO : Um algoritmo que avalia a solicitação de um empréstimo bancário, classificando o solicitante em categorias.
 */


#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
    // Variaveis 
    int idade, negativado, parcelas_atraso, parcelas_2anos;
    float renda;
    
    // Entrada de dados
    printf("\nDigite sua idade: ");
    scanf("%d", &idade);
    printf("\nDigite o valor da sua renda mensal: ");
    scanf("%f", &renda);
    printf("\nDigite 1 se seu nome está negativado, ou 0 se não: ");
    scanf("%d", &negativado);
    printf("\nDigite o número de parcelas atrasadas atualmente: ");
    scanf("%d", &parcelas_atraso);
    printf("\nDigite o número de parcelas atrasadas nos últimos 2 anos: ");
    scanf("%d", &parcelas_2anos);
    
    // Verificação das condições de reprovação
    if (renda < 2000 || negativado == 1 || idade < 18 || idade > 70) {
        printf("\nEmpréstimo Negado"); //NAO ESTÁ APTO EM NENHUMA DAS CONDIÇÕES
        return 0;
    }
    
    // Avaliação das categorias de empréstimo
    if (renda >= 2000 && renda < 5000 && parcelas_atraso <= 2) {
        printf("\nLiberado Empréstimo de Baixo Valor (até R$ 5.000,00)");
    } else if (renda >= 5000 && renda < 10000 && parcelas_2anos <= 4 && parcelas_atraso == 0) {
        printf("\nLiberado Empréstimo de Médio Valor (até R$ 20.000,00)");
    } else if (renda >= 10000 && parcelas_2anos == 0) {
        printf("\nLiberado Empréstimo de Alto Valor (acima de R$ 20.000,00)");
    } else {
        printf("\nEmpréstimo Negado"); //NAO ESTÁ APTO EM NENHUMA DAS CONDIÇÕES
    }
    
    return 0;
}
