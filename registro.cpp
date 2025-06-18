#include <iostream>
#include <string>
#include <fstream>
using namespace std;


typedef struct {
   string nome;
   string email;
   string celular;
   string cidade;
} Tamigo;


int main() {
   const int TAMANHO_MAXIMO = 100; // Valor fixo, mas não é #define
   Tamigo lista[100];
   int X = 0;


   cout << "Digite a quantidade de amigos a ser cadastrados (max 100): ";
   cin >> X;
   if (X > TAMANHO_MAXIMO) X = TAMANHO_MAXIMO;
   for (int i = 0; i < X; i++) {
       cout << "\nAmigo " << i+1 << ":\n";
       cout << "Digite o nome (sem espaço): ";
       cin >> lista[i].nome;
       cout << "Digite seu email (sem espaço): ";
       cin >> lista[i].email;
       cout << "Digite seu telefone (sem espaço): ";
       cin >> lista[i].celular;
       cout << "Digite sua cidade (sem espaço): ";
       cin >> lista[i].cidade;
   }


   // Salvar no arquivo
   ofstream arquivo("agenda.txt");
   if (arquivo.is_open()) {
       for (int i = 0; i < X; i++) {
           arquivo << lista[i].nome << " " << lista[i].email << " " << lista[i].celular << " " << lista[i].cidade << endl;
       }
       arquivo.close();
   } else {
       cout << "Erro ao abrir o arquivo!" << endl;
       return 1;
   }


   int opcao = -1;
   while (opcao != 0) {
       cout << "\nMenu:\n";
       cout << "1. Listar amigos\n";
       cout << "2. Incluir amigo\n";
       cout << "3. Excluir\n";
       cout << "4. Buscar dados da lista\n";
       cout << "5. Alterar dados da lista\n";
       cout << "0. Sair\n";
       cout << "Escolha uma opcao: ";
       cin >> opcao;


       switch (opcao) {
           case 1: {
               cout << "\nLista de amigos:\n";
               for (int i = 0; i < X; i++) {
                   cout << "Amigo " << i+1 << ": " << lista[i].nome << ", " << lista[i].email << ", "
                        << lista[i].celular << ", " << lista[i].cidade << endl;
               }
               break;
           }
           case 2: {
               if (X < TAMANHO_MAXIMO) {
                   cout << "\nIncluir novo amigo:\n";
                   cout << "Digite o nome (sem espaço): ";
                   cin >> lista[X].nome;
                   cout << "Digite seu email (sem espaço): ";
                   cin >> lista[X].email;
                   cout << "Digite seu telefone (sem espaço): ";
                   cin >> lista[X].celular;
                   cout << "Digite sua cidade (sem espaço): ";
                   cin >> lista[X].cidade;
                   X++;
                   cout << "Amigo incluído com sucesso!\n";
               } else {
                   cout << "Limite máximo de amigos atingido!\n";
               }
               break;
           }
           case 3: {
               cout << "\nExcluir amigo:\n";
               string nomeExcluir;
               cout << "Digite o nome do amigo a ser excluído: ";
               cin >> nomeExcluir;
               int i;
               for (i = 0; i < X; i++) {
                   if (lista[i].nome == nomeExcluir) {
                       for (int j = i; j < X - 1; j++) {
                           lista[j] = lista[j + 1];
                       }
                       X--;
                       cout << "Amigo " << nomeExcluir << " excluído com sucesso!\n";
                       break;
                   }
               }
               if (i == X) {
                   cout << "Amigo não encontrado!\n";
               }
               break;
           }
           case 4: {
               cout << "\nBuscar dados da lista:\n";
               string nomeBuscar;
               cout << "Digite o nome do amigo a ser buscado: ";
               cin >> nomeBuscar;
               int i;
               for (i = 0; i < X; i++) {
                   if (lista[i].nome == nomeBuscar) {
                       cout << "Amigo encontrado: " << lista[i].nome << ", "
                            << lista[i].email << ", " << lista[i].celular
                            << ", " << lista[i].cidade << endl;
                       break;
                   }
               }
               if (i == X) {
                   cout << "Amigo não encontrado!\n";
               }
               break;
           }
           case 5: {
               cout << "\nAlterar dados da lista:\n";
               string nomeAlterar;
               cout << "Digite o nome do amigo a ser alterado: ";
               cin >> nomeAlterar;
               int i;
               for (i = 0; i < X; i++) {
                   if (lista[i].nome == nomeAlterar) {
                       cout << "Amigo encontrado. Digite os novos dados:\n";
                       cout << "Novo nome (sem espaço): ";
                       cin >> lista[i].nome;
                       cout << "Novo email (sem espaço): ";
                       cin >> lista[i].email;
                       cout << "Novo telefone (sem espaço): ";
                       cin >> lista[i].celular;
                       cout << "Nova cidade (sem espaço): ";
                       cin >> lista[i].cidade;
                       cout << "Dados alterados com sucesso!\n";
                       break;
                   }
               }
               if (i == X) {
                   cout << "Amigo não encontrado!\n";
               }
               break;
           }
           case 0:
               cout << "Saindo do programa...\n";
               break;
           default:
               cout << "Opção inválida!\n";
       }


       // editar agenda.txt
       ofstream arquivo("agenda.txt");
       if (arquivo.is_open()) {
           for (int i = 0; i < X; i++) {
               arquivo << lista[i].nome << " " << lista[i].email << " " << lista[i].celular << " " << lista[i].cidade << endl;
           }
           arquivo.close();
       }
   }


   return 0;
}







