#include <cstdlib>
#include <iostream>
#include <fstream>    
    
using namespace std;

int main(int argc, char** argv) {
 	const int TAM = 5;
	// Declarar o vetor

	float alturas[TAM], media, soma, maior, pedido,r;

	// Variavel de auxiliar

	int i;
   
    
	// Leitura do vetor
	i = 0;
	media=0, soma=0, maior=0, pedido=0, r=0;
	while (i < TAM) {
    	cout << "Digite o " << i + 1 << "º valor : ";
    	cin >> alturas[i];
    	i++;
	}
	// Calculo da media
	i = 0;
	while (i < TAM) {
    	soma = soma + alturas[i];
    	i++;
  	 
	}   
    
	media = soma / i;
 
    
	// Escrita do vetor
	cout << "Digite o valor desejado : " << endl;
	cin >> r;
	i = 0;
	while (i < TAM) {
    	cout << "O " << i + 1 << " º valor é : " << alturas[i] << endl;
   	 
    	// Contar quantos estao acima da media
    	if(alturas[i] > media){
    	maior++;
	}
    	if(r == alturas[i]){
    	pedido++;
    	}
       	 
    	i++;
   	 
	}
    
	cout << "\nA media das " << i << " alturas é de : " << media << endl;
	cout << "\nA quantidade de números maior que a média é de : " << maior << endl;
	cout << "\nExiste " << pedido << " número " << r <<" dentre todos os " << TAM << " números escritos "  << endl;
    
	return 0;
}



