#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int MAX = 10;
    int vetor[MAX];
    int i = 0, valor = 0, tam = 0;

    ifstream arquivo("valores");
    if (!arquivo.is_open()) {
        cout << "\n\tErro: Arquivo não encontrado.\n";
        return 1;
    }

    while (arquivo >> valor && tam < MAX) {
        vetor[tam] = valor;
        tam++;
    }
    arquivo.close();

    cout << "Valores atuais no vetor: ";
    for (i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Menu de opções
    int opcao;
    cout << "\nEscolha uma operação:";
    cout << "\n1 - Buscar valor no vetor (primeira ocorrência e todas as posições)";
    cout << "\n2 - Inverter valores";
    cout << "\n3 - Adicionar valor a todos os elementos";
    cout << "\n4 - Adicionar valor aos que não são divisíveis por 3";
    cout << "\n5 - Remover uma ocorrência de um valor";
    cout << "\n6 - Remover todas as ocorrências de um valor";
    cout << "\n7 - Inserir um valor no vetor se ele não estiver cheio";
    cout << "\n8 - Inserir um valor em uma posição determinada";
    cout << "\n9 - Remover todos os valores repetidos de um vetor";
    cout << "\n0 - Sair";
    cout << "\nOpção: ";
    cin >> opcao;

    switch (opcao) {
        case 0:
        {
            cout << "\nSaindo do programa...\n";
            break;
        }
        case 1:
        {
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

            if (primeirapos != -1) {
                cout << "\nA primeira posição do valor " << vdesejado << " está na " << (primeirapos + 1) << "ª posição." << endl;
                cout << "\nO valor aparece nas posições: ";
                for (i = 0; i < tam; i++) {
                    if (vetor[i] == vdesejado) {
                        cout << (i + 1) << " ";
                    }
                }
                cout << endl;
            } else {
                cout << "\nValor não encontrado no vetor.\n";
            }
            break;
        }
        case 2:
        {
            for (i = 0; i < tam / 2; i++) {
                int temp = vetor[i];
                vetor[i] = vetor[tam - i - 1];
                vetor[tam - i - 1] = temp;
            }

            cout << "\nValores invertidos: ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3:
        {
            int valord;
            cout << "Digite o valor a ser adicionado: ";
            cin >> valord;

            for (i = 0; i < tam; i++) {
                vetor[i] += valord;
            }

            cout << "\nValores com +" << valord << ": ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
            break;
        }
        case 4:
        {
            int valord;
            cout << "Digite o valor a ser adicionado aos que não são divisíveis por 3: ";
            cin >> valord;

            for (i = 0; i < tam; i++) {
                if (vetor[i] % 3 != 0) {
                    vetor[i] += valord;
                }
            }

            cout << "\nValores atualizados (+" << valord << " nos não divisíveis por 3): ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
            break;
        }
        case 5:
        {
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
        {
            int vremovido;
            cout << "Digite o valor a ser removido (todas as ocorrências): ";
            cin >> vremovido;

            int j = 0;
            for (i = 0; i < tam; i++) {
                if (vetor[i] != vremovido) {
                    vetor[j++] = vetor[i];
                }
            }

            if (j < tam) {
                tam = j;
                cout << "\nTodas as ocorrências removidas. Vetor atualizado: ";
                for (i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
            } else {
                cout << "\nO valor não estava presente no vetor.\n";
            }

            break;
        }
        case 7:
        {
            int add = 0;

            if (tam < MAX) {
                cout << "Digite o valor a ser adicionado: ";
                cin >> add;
                vetor[tam] = add;
                tam++;
                cout << "\nValor inserido com sucesso. Vetor atualizado: " << endl;
            } else {
                cout << "\nNão é possivel, o vetor já está cheio!" << endl;
            }
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
        }

            break;

        case 8:
        {
            int avalor = 0, aposicao = 0;
            cout << "Digite o valor a ser adicionado : ";
            cin >> avalor;
            cout << "Digite a posição a ser alterada : ";
            cin >> aposicao;
            for (i = 0; i < tam; i++) {
                if (aposicao >= 0 && aposicao < tam) {
                    vetor[aposicao - 1] = avalor;
                }
            }
            cout << "\nValor alterado com sucesso. Vetor atualizado: " << endl;
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;

            break;
        }
        case 9:
        {
            for (int i = 0; i < tam; i++) {
                for (int J = i + 1; J < tam;) { //J compara os próximos valores com vetor[i] e ve quais estao duplicados.
                    if (vetor[i] == vetor[J]) {
                        cout << "\-Valor repetido encontrado: " << vetor[i] << endl;
                        for (int K = J; K < tam - 1; K++) { // K move o vetor para esquerda, tampar os burracos
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

    return 0;
}



