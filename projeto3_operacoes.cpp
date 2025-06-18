/*
 * Aluno: Pedro Ferreira Prado - 2025.1.08.028
 * Professor : Paulo Bressan
 * Data: 20/05/2025
 * 
 * Objetivo: Criar um projeto que insira valores inteiros num vetor de 100 posições e
 * apresente um menu de operações que podem ser realizadas no vetor quantas vezes o
 * usuário desejar.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    const int MAX = 100; // TAMANHO DO VETOR
    int vetor[MAX];
    int i = 0, valor = 0, tam = 0;

    //PUXAR DADOS DE UM TXT COM 100 NUMEROS ALEATORIOS 
    ifstream arquivo("tamanho");
    if (not arquivo.is_open()) {
        cout << "\n\tErro: Arquivo não encontrado. \n";
        return 1;
    }
    //MANDA OS VALORES DO ARQUIVO PARA O VETOR
    while (arquivo >> valor && tam < MAX) {
        vetor[tam] = valor;
        tam++;
    }
    arquivo.close();

    // MOSTRA TODOS OS VALORES DO VETOR (ANTES DE QUALQUER ALTERAÇÃO)
    cout << "Valores atuais no vetor: ";
    for (i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    // MENU DE OPÇÕES PARA USUARIO 
    int opcao=11; //OPCAO COMEÇANDO EM UM NUMERO ALEATORIO
    cout << "\nEscolha uma operação:";
    cout << "\n1 - Visualize o vetor";
    cout << "\n2 - Contar a quantidade de ocorrências que um valor aparece";
    cout << "\n3 - Contar a quantidade de ocorrências de valores de um intervalo";
    cout << "\n4 - Buscar pela primeira ocorrência de um valor e informar a posição";
    cout << "\n5 - Excluir a primeira ocorrência de um valor informado";
    cout << "\n6 - Inserir um valor informado numa posição também informada";
    cout << "\n7 - Retirar todos os valores repetidos";
    cout << "\n0 - Sair";
    cout << "\nOpção: ";
    cin >> opcao;

    //REPETIR OPÇÃO ATE QUE O USUARIO DIGITE 0
    while (opcao != 0) {
        switch (opcao) {
            case 1:
            {   //USUARIO VER O QUE ESTÁ NO VETOR 
                cout << "Valores atuais no vetor: ";
                for (i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;
            }
            case 2:
            { // QUANTIDADE DE OCORRENCIAS DE UM VALOR NO VETOR
                int vdesejado, ocorrencias = 0;
                cout << "\nDigite o valor a ser encontrado: ";
                cin >> vdesejado;
                for (i = 0; i < tam; i++) {
                    if (vetor[i] == vdesejado) {
                        ocorrencias++;
                    }
                }
                cout << "O valor " << vdesejado << " apareceu " << ocorrencias << " vez(es) no vetor ";
                break;
            }
            case 3:
            {   // QUANTIDADE DE OCORRENCIAS EM UM DETERMINADO INTERVALO 
                int limiteI, limiteS;
                int valorDesejado, ocorrencias = 0;

                cout << "\nDigite o valor do limite inferior do intervalo: ";
                cin >> limiteI;
                cout << "Digite o valor do limite superior do intervalo: ";
                cin >> limiteS;

                // limiteI tem que ser < que limiteS
                if (limiteI > limiteS) {
                    int temp = limiteI;
                    limiteI = limiteS;
                    limiteS = temp;
                }

                cout << "Digite o valor que deseja buscar dentro do intervalo: " << endl;
                cin >> valorDesejado;
                
                cout << "Valores atuais no vetor: ";
                for (i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                

                if (valorDesejado < limiteI || valorDesejado > limiteS) {
                    cout << "\nO valor " << valorDesejado << " não está no intervalo ["
                            << limiteI << ", " << limiteS << "]." << endl;
                } else {
                    for (i = 0; i < tam; i++) {
                        if (vetor[i] == valorDesejado) {
                            ocorrencias++;
                        }
                    }
                    cout << "\nO valor " << valorDesejado << " aparece " << ocorrencias
                            << " vez(es) no vetor dentro do intervalo informado." << endl;
                }

                break;
            }
            case 4:
            { // Buscar pela primeira ocorrência de um valor e informar a posição
                int vdesejado;
                cout << "\nDigite o valor desejado: ";
                cin >> vdesejado;

                int primeirapos = -1;
                for (i = 0; i < tam; i++) {
                    if (vetor[i] == vdesejado) {
                        primeirapos = i;
                        break;
                    }
                }
                cout << "\nA primeira posição do valor " << vdesejado << " está na " << (primeirapos + 1) << "ª posição." << endl;
                break;
            }
            case 5:
            { // Excluir a primeira ocorrência de um valor informado
                int vremovido, posicao = -1;
                cout << "Digite o valor a ser removido: ";
                cin >> vremovido;

                for (i = 0; i < tam; i++) {
                    if (vetor[i] == vremovido) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao != -1) {
                    for (i = posicao; i < tam - 1; i++) {
                        vetor[i] = vetor[i + 1];
                    }
                    tam--;

                    cout << "\nValor removido. Vetor atualizado: ";
                    for (i = 0; i < tam; i++) {
                        cout << vetor[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "\nValor não encontrado no vetor.\n";
                }
                break;
            }
            case 6:
            { // Inserir um valor informado numa posição também informada se o vetor nao estiver cheio
                if (tam >= MAX) {
                    cout << "\nNão é possível, o vetor já está cheio!" << endl;
                    break;
                }

                int avalor = 0, aposicao = 0;
                cout << "Digite o valor a ser adicionado: ";
                cin >> avalor;
                cout << "Digite a posição onde deseja inserir (1 a " << tam + 1 << "): ";
                cin >> aposicao;

                // Ajuste para índice (usuário digita de 1 a N)
                aposicao--;

                if (aposicao < 0 || aposicao > tam) {
                    cout << "\nPosição inválida!" << endl;
                    break;
                }

                // Desloca os elementos para a direita para abrir espaço
                for (int j = tam; j > aposicao; j--) {
                    vetor[j] = vetor[j - 1];
                }

                vetor[aposicao] = avalor;
                tam++; // Atualiza o número de elementos

                cout << "\nValor inserido com sucesso. Vetor atualizado:\n";
                for (i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;

                break;
            }
            case 7:
            {   //RETIRAR TODOS OS VALORES REPETIDOS 
                for (int i = 0; i < tam; i++) {
                    for (int J = i + 1; J < tam;) { // J compara os próximos valores com vetor[i] e ve quais estao duplicados.
                        if (vetor[i] == vetor[J]) {
                            cout << "\-Valor repetido encontrado: " << vetor[i] << endl;
                            for (int K = J; K < tam - 1; K++) { // K move o vetor para esquerda, tampar os buracos
                                vetor[K] = vetor[K + 1];
                            }
                            tam--;
                        } else {
                            J++; // avança se não houve remoção
                        }
                    }
                }
                cout << "\nVetor sem valores repetidos: ";
                for (int i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;
            }
            default:
            {
                cout << "\nOpção inválida!\n";
                break;
            }
        }

        // Exibe o menu novamente após a operação e le a próxima opção
        cout << "\nEscolha uma operação:";
        cout << "\n1 - Visualize o vetor";
        cout << "\n2 - Contar a quantidade de ocorrências que um valor aparece";
        cout << "\n3 - Contar a quantidade de ocorrências de valores de um intervalo";
        cout << "\n4 - Buscar pela primeira ocorrência de um valor e informar a posição";
        cout << "\n5 - Excluir a primeira ocorrência de um valor informado";
        cout << "\n6 - Inserir um valor informado numa posição também informada";
        cout << "\n7 - Retirar todos os valores repetidos";
        cout << "\n0 - Sair";
        cout << "\nOpção: ";
        cin >> opcao;
    }
    //DIGITOU 0 encerra o programa
    cout << "\nPrograma encerrado! \n";
    return 0;
}
