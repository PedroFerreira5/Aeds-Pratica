#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Author: Pedro Ferreira Prado
 * RA : 2025.1.08.028   
 * Disciplina : AEDS 1 PRÁTICA
 * Created on 22 de abril de 2025, 13:45
 *
 *  OBJETIVO : Ler o arquivo gerado e calcular a área e o volume total da cena gráfica.
 */
int main(int argc, char** argv) {

	const double PI = 3.141592653589793; //VALOR DE PI
	string figura;
	
         // Abre o arquivo contendo os dados das figuras geométricas criado pelo ofstream no outro codigo
        ifstream arquivo("cenagrafica.txt"); 
	if (!arquivo.is_open()) {
    	cout << "\n\tErro: Arquivo não encontrado.\n";
    	return 1;
	}

	arquivo >> figura;
	double areatotal = 0, volumetotal = 0, area2 = 0;

        // Lê cada figura do arquivo até encontrar "fim"
	while (figura != "fim") {
    	if (figura == "Cubo") {  // Cálculo de área e volume para um Cubo
        	double aresta;
        	arquivo >> aresta;
        	areatotal += 6 * aresta * aresta;
        	volumetotal += aresta * aresta * aresta;  
    	} else if (figura == "Esfera") { // Cálculo de área e volume da esfera
        	double raio;
        	arquivo >> raio;
        	areatotal += 4 * PI * raio * raio;
        	volumetotal += (4.0 / 3.0) * PI * raio * raio * raio;
    	} else if (figura == "Piramide") { // Cálculo de área e volume da piramide
        	double altura, profundidade, base;
        	arquivo >> altura >> profundidade >> base;
        	double areabase = base * altura / 2.0;
        	areatotal += areabase;
        	volumetotal += areabase * profundidade;
    	} else if (figura == "Cilindro") { // Cálculo de área e volume de um cilindro
        	double raio, altura;
        	arquivo >> raio >> altura;
        	double areaBase = PI * raio * raio;
        	areatotal += 2 * PI * raio * altura + 2 * areaBase; // lateral + tampas
        	volumetotal += areaBase * altura;
   	 
    	} else if (figura == "Quadrado"){ // Cálculo de área de um quadrado
        	double lado;
        	arquivo >> lado;
        	area2 += lado*lado;
    	} else if (figura == "Retangulo"){ //Cálculo de área de um retangulo
        	double base, altura;
        	arquivo >> base >> altura;
        	area2 += base*altura;
    	}else if (figura == "Circulo"){ //Cálculo de área de um circulo
        	double raio;
        	arquivo >> raio;
        	area2 += PI*(raio*raio);
    	}else if (figura == "Trapezio"){ //Cálculo de área de um trapezio
        	double Bmaior, bMenor, altura;
        	arquivo >> Bmaior >> bMenor >> altura;
        	area2 += ((Bmaior*bMenor)*altura)/2;
    	}
        
        // Le a próxima figura
    	arquivo >> figura;
	}

        // Exibe o resultado ja somado das areas e volumes
	cout << "Área total : "  << areatotal << "m³" << "\nVolume total: " << volumetotal  <<  "v³" << endl;
	cout << "Área da Superfice total foi de : " << area2 << "m²" << endl;
	arquivo.close();
        return 0;
}

