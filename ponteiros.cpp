#include <cstdlib>
#include <iostream>
using namespace std;




int main(){


   int x=10, y=12, z=17;   
   int *p;
   int v[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // Vetor de inteiros
  
  
   p = &x; // Ponteiro p aponta para x
   printf("\nO valor de &x é: %p e o valor de x é %d\n", &x, x);
   printf("\nO valor de p é: %p e o valor de *p é %d\n", p, *p);


   p++; // Incrementa o ponteiro p para apontar para o próximo endereço de memória
   printf("\nO valor de p é : %p e o valor de *p é: %d", p, *p);


  /*  printf("\nValores do Vetor");
   for(int i = 0; i < 10; i++) {
       printf("\nO valor de &v[i] é: %p e o valor de v[i] é %d", &v[i], v[i]);
   }
  */


   printf("\n\nValores do Vetor");
   for(int *q = v ; q < v + 10 ; q++) {
       printf("\nO valor de &v[i] é: %p e o valor de v[i] é %d", q, *q);
   }


   printf("\n\nValores do Vetor");
   for(int *q = v+10-1 ; q >= v ; q--) {
       printf("\nO valor de &v[i] é: %p e o valor de v[i] é %d", q, *q);
   }




   return 0;
}

