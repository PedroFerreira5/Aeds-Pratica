#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

	int varinteira = 47;
	float varfloat = 47.0;
	char varchar = 81;
	long int varlongint = 47;
	double vardouble = 48.0;
	short int varshortint = 47;
	int i;
    
 //   printf(" \n   ------------------------------------------------------ ");
 //   printf("\n 	Caracteristicas de variaveis e alocação de memoria ");
 //   printf(" \n   ------------------------------------------------------ ");
 //   printf("\n	Tipo	|	Valor   |  	Endereço 	|  Tamanho");
 //   printf(" \n   ------------------------------------------------------ ");
 //   printf("\n	Int       	%d     	%p    	%li", varinteira, &varinteira, sizeof(int)); //&varinteira (endereço dela) //sizeof = tamanho em bits
 //   printf("\n	Float   	%.2f    	%p    	%li", varfloat, &varfloat, sizeof(float));
 //   printf("\n	Char      	%c      	%p    	%li", varchar, &varchar, sizeof(char));
 //   printf("\n	Char      	%d     	%p    	%li", varchar, &varchar, sizeof(char));
 //   printf("\n	LongInt   	%li     	%p    	%li", varlongint, &varlongint, sizeof(long int));
 //   printf("\n	Double  	%.2f    	%p    	%li", vardouble, &vardouble, sizeof(double));
 //   printf("\n	ShortInt  	%d     	%p    	%li", varshortint, &varshortint, sizeof(short int));
    
 //   printf("\n\n");
    
 //   printf("\n   	Tabela ASCII");
 //   printf("\n 	-------------------");
 //   printf("\n 	Int   |   Caracter ");
 //   printf("\n 	-------------------");
    
  //  i = 0;
  //  while (i < 256){
  //  	printf("\n  	%d      	%c", i, i);
  //  	i = i + 1;   	 
//}   	 
    	 
	printf(" \n   ------------------------------------------------------ ");
	printf("\n            	Limites das Variaveis ");
	printf(" \n   ------------------------------------------------------ ");
	printf("\n  	Tipo	|  	Inferior   	|  	Superior ");
	printf(" \n   ------------------------------------------------------ ");
    
	//int a,b;
	//a = 0;
	//b = 1;
	//while(a < b){
	//	a = b;
	//	b = b + 1;
	//}
	// 	printf("\n  	Int      	%d       	%d", b, a);
    
	//printf("\n\n\n\n\n\n\n");
    	 
	long int inf, sup;
	inf = 0;
	sup = 1;
	while(inf < sup){
    	inf = sup;
    	sup = sup + 1;
	}
     	printf("\n  	Int      	%li       	%li",sup, inf);
    
	printf("\n\n\n\n\n\n\n");
    
    
	return 0;
}



