#include <cstdlib>
#include <iostream>
#include "funcoes.h"

using namespace std;

int main() {
    const int TAM = 10;
    int vAleat[] = {17, 14, 16, 12, 20, 15, 19, 11, 13, 18}; // MÉDIO CASO
    int vCresc[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // MELHOR CASO
    int vDecresc[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11}; // PIOR CASO

    int opcao;
    cout << "Escolha uma opção de ordenação:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Bubble Sort com Ponteiros\n";
    cout << "5. Insertion Sort com Ponteiros\n";
    cout << "6. Selection Sort com Ponteiros\n";
    cout << "Opção: ";
    cin >> opcao;
    cout << endl;

    switch (opcao) {
        case 1:
            cout << "Você escolheu Bubble Sort.\n";
            listagem(vAleat, TAM);
            bubbleSort(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            bubbleSort(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            bubbleSort(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        case 2:
            cout << "Você escolheu Insertion Sort.\n";
            listagem(vAleat, TAM);
            insertionSort(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            insertionSort(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            insertionSort(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        case 3:
            cout << "Você escolheu Selection Sort.\n";
            listagem(vAleat, TAM);
            selectionSort(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            selectionSort(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            selectionSort(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        case 4:
            cout << "Você escolheu Bubble Sort com Ponteiros.\n";
            listagem(vAleat, TAM);
            bubbleSortPonteiros(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            bubbleSortPonteiros(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            bubbleSortPonteiros(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        case 5:
            cout << "Você escolheu Insertion Sort com Ponteiros.\n";
            listagem(vAleat, TAM);
            insertionSortPonteiros(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            insertionSortPonteiros(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            insertionSortPonteiros(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        case 6:
            cout << "Você escolheu Selection Sort com Ponteiros.\n";
            listagem(vAleat, TAM);
            selectionSortPonteiros(vAleat, TAM);
            listagem(vAleat, TAM);
            listagem(vCresc, TAM);
            selectionSortPonteiros(vCresc, TAM);
            listagem(vCresc, TAM);
            listagem(vDecresc, TAM);
            selectionSortPonteiros(vDecresc, TAM);
            listagem(vDecresc, TAM);
            break;
        default:
            cout << "Opção inválida.\n";
            break;
    }

    return 0;
}
