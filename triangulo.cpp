#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 *
 * se a soma dos dois lados menores for maior que o terceiro lado.
 */
int main(int argc, char** argv) {

	float L1, L2, L3;

	printf("\n\tDigite o valor de lado 1: ");
	scanf("%f", &L1);
	printf("\n\tDigite o valor de lado 2: ");
	scanf("%f", &L2);
	printf("\n\tDigite o valor de lado 3: ");
	scanf("%f", &L3);

	if ((L1 > 0) or (L2 > 0) or (L3 > 0)) {

    	if (L1 < L2 + L3 or L2 < L1 + L3 or L3 < L2 + L1) {
        	printf("\n\t O triângulo é válido");


        	if (L1 != L2 && L1 != L3 && L2 != L3) {
            	printf("\n\t O triângulo é Escaleno!");
            	if ((L1*L1 == (L2 * L2)+(L3 * L3)) or (L2*L2 == (L1 * L1)+(L3 * L3)) or (L3*L3 == (L1 * L1)+(L2 * L2))) {
                	printf("\n\t E é um triângulo retângulo");
            	}
        	} else if ((L1 == L2 and L2 != L3) or (L3 == L1 and L1 != L2) or (L3 == L2 and L2 != L1)) {
            	printf("\n\t O triângulo é Isóceles");
        	} else if (L1 == L2 and L2 == L3) {
            	printf("\n\t O triângulo é Equilatero");
        	}

    	} else {
        	printf("\n\t Esse triângulo não é valido!");
    	}
	} else {
    	printf("\n\t Esse triângulo não existe!");
	}

	return 0;

}


