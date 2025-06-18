#include <cstdlib>
#include <iostream>
#include "funcoes.h"
using namespace std;




int main(){
const int TAM = 10;
int vAleat[] = {17, 14, 16, 12, 20, 15, 19, 11, 13, 18}; // MÉDIO CASO
int vCresc[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // MELHOR CASO
int vDecresc[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11}; //PIOR CASO 
int opcao;
cout << "Escolha uma opção de ordenação:\n";
cout << "1. Bubble Sort\n";
cout << "2. Insertion Sort\n";
cout << "3. Selection Sort\n";
cout << "Opção: ";
cin >> opcao;
cout << endl;
switch (opcao)
{
case 1: // Bubble Sort
   cout << "Você escolheu Bubble Sort.\n";
   cout << "Vetor Aleatoria Original: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor original  
   bubbleSort(vAleat, TAM); // Chama a função bubbleSort para ordenar o vetor
   cout << "Listagem Aleatoria Ordenado: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor ordenado


   cout << "Listagem Crescente Original: ";
   listagem(vCresc, TAM); //
   bubbleSort(vCresc, TAM); //
   cout << "Listagem Crescente Ordenada: ";
   listagem(vCresc, TAM); //
  
   //
   cout << "Listagem Decrescente Original: ";
   listagem(vDecresc, TAM); //
   bubbleSort(vDecresc, TAM); //
   cout << "Listagem Decrescente Ordenada: ";
   listagem(vDecresc, TAM); //
   break;


   case 2:{ //INSERTION SORT
   cout << "Você escolheu Insertion Sort.\n";
   cout << "Vetor Aleatoria Original: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor original
   insertionSort(vAleat, TAM); // Chama a função insertionSort para ordenar o vetor
   cout << "Vetor Aleatoria Ordenado: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor ordenado
   cout << "Listagem Crescente Original: ";
   listagem(vCresc, TAM); //
   insertionSort(vCresc, TAM); //
   cout << "Listagem Crescente Ordenada: ";
   listagem(vCresc, TAM); //
   cout << "Listagem Decrescente Original: ";
   listagem(vDecresc, TAM); //
   insertionSort(vDecresc, TAM); //
   cout << "Listagem Decrescente Ordenada: ";
   listagem(vDecresc, TAM); //
   break;  
}
case 3:{ //SELECTION SORT
   cout << "Você escolheu Selection Sort.\n";
   cout << "Vetor Aleatoria Original: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor original
   selectionSort(vAleat, TAM); // Chama a função selectionSort para ordenar o vetor
   cout << "Vetor Aleatoria Ordenada: ";
   listagem(vAleat, TAM); // Chama a função listagem para exibir o vetor ordenado
   cout << "Listagem Crescente Original: ";
   listagem(vCresc, TAM); //
   selectionSort(vCresc, TAM); //
   cout << "Listagem Crescente Ordenada: ";
   listagem(vCresc, TAM); //
   cout << "Listagem Decrescente Original: ";
   listagem(vDecresc, TAM); //
   selectionSort(vDecresc, TAM); //
   cout << "Listagem Decrescente Ordenada: ";
   listagem(vDecresc, TAM); //
   break;
}


default:
   break;
}  
   return 0;
}







