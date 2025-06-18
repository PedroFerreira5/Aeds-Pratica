#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>
using namespace std;

/*
 * Author: Pedro Ferreira Prado
 * RA : 2025.1.08.028   
 * Disciplina : AEDS 1 PRÁTICA
 * Created on 22 de abril de 2025, 13:45
 *
 *  OBJETIVO : Permitir ao usuário descrever as figuras de uma cena gráfica por meio de um menu e escrever esses dados em um arquivo de saída.
 */
int main(int argc, char** argv) {

    // CRIA O EMPTY FILE 
    ofstream arquivo("cenagrafica.txt");
    if (not arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    string figura;
    int opcao;
    
    // USUARIO ESCOLHE A FIGURA DESEJADA
    
    cout << "\n Deseja calcular a área de qual figura? \n Cubo(1) \t Esfera(2) \t Triangulo(3) \t Cilindro(4) \t Fim(0) \n Quadrado(5) \t Retangulo(6) \t Circulo(7) \t Trapezio(8)" << endl;
    cin >> opcao;
    
    // TRANSFORMA A FIGURA EM UM NUMERO DE ESCOLHA PARA O USUARIO
    if (opcao == 0) {
        figura = "fim";
    } else if (opcao == 1) {
        figura = "Cubo";
    } else if (opcao == 2) {
        figura = "Esfera";
    } else if (opcao == 3) {
        figura = "Piramide";
    } else if (opcao == 4) {
        figura = "Cilindro";
    } else if(opcao == 5){
        figura = "Quadrado";
    } else if(opcao == 6){
        figura = "Retangulo";
    } else if(opcao == 7){
        figura = "Circulo";
    } else if(opcao == 8){
        figura = "Trapezio";
    }

    // FAZ COM QUE O USUARIO ESCOLHA VALORES PARA CADA LADO, ALTURA OU RAIO DA FIGURA
    while (figura != "fim") {
        if (figura == "Cubo") {
            double aresta;
            cout << "Digite o valor da aresta: ";
            cin >> aresta;
            arquivo << figura << "\t" << aresta << endl;
        } else if (figura == "Esfera") {
            double raio;
            cout << "Digite o valor do raio: ";
            cin >> raio;
            arquivo << figura << "\t" << raio << endl;
        } else if (figura == "Piramide") {
            double altura, profundidade, base;
            cout << "Digite a altura: ";
            cin >> altura;
            cout << "Digite a profundidade: ";
            cin >> profundidade;
            cout << "Digite a base: ";
            cin >> base;
            arquivo << figura << "\t" << altura << "\t" << profundidade << "\t" << base << "\t" << endl;
        } else if (figura == "Cilindro") {
            double raio, altura;
            cout << "Digite o raio: ";
            cin >> raio;
            cout << "Digite a altura: ";
            cin >> altura;
            arquivo << figura << "\t" << raio << "\t" << altura << endl;
        } else if (figura == "Quadrado"){
            double lado;
            cout << "Digite o valor do lado: ";
            cin >> lado;
            arquivo << figura << "\t" << lado << endl;
        }else if (figura == "Retangulo"){
            double base, altura;
             cout << "Digite o valor da base: ";
             cin >> base;
             cout << "Digite o valor da altura: ";
             cin >> altura;
             arquivo << figura << "\t" << base << "\t" << altura << endl;
        }else if (figura == "Circulo"){
            double raio;
            cout << "Digite o valor do raio: ";
            cin >> raio;
            arquivo << figura << "\t" << raio << endl;
        }else if (figura == "Trapezio"){
            double Bmaior, bMenor, altura;
             cout << "Digite o valor da base maior: ";
             cin >> Bmaior;
              cout << "Digite o valor da base menor: ";
              cin >> bMenor;
               cout << "Digite o valor da altura: ";
               cin >> altura;
               arquivo << figura << "\t" << Bmaior << "\t" << bMenor << "\t" << altura << "\t" << endl;
        } else if (figura == "fim"){
            cout << "Lista Finalizada";
        }
        
        cout << "\nDeseja calcular a área de qual figura? \n Cubo(1) \t Esfera(2) \t Triangulo(3) \t Cilindro(4) \t Fim(0) \n Quadrado(5) \t Retangulo(6) \t Circulo(7) \t Trapezio(8)" << endl;
        cin >> opcao;

        if (opcao == 0) {
        figura = "fim";
    } else if (opcao == 1) {
        figura = "Cubo";
    } else if (opcao == 2) {
        figura = "Esfera";
    } else if (opcao == 3) {
        figura = "Piramide";
    } else if (opcao == 4) {
        figura = "Cilindro";
    } else if(opcao == 5){
        figura = "Quadrado";
    } else if(opcao == 6){
        figura = "Retangulo";
    } else if(opcao == 7){
        figura = "Circulo";
    } else if(opcao == 8){
        figura = "Trapezio";
    }

    }

    arquivo << "fim";    
    cout << "\nLista Finalizada";
    
    arquivo.close();
    return 0;
}


