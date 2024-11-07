#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "state.h"

int main() {
   //wejscie zdefiniowane na sztywno TODO: dynamiczna alokacja i pobierane
   char wejscie[7] = "0010111"; 
   stan_t obecny_stan = q0; // ustawiam stan początkowy (default case)
   
   printf("sprawdzany ciąg wejściowy: %s\n", wejscie);
   printf("START -> (q%d)", obecny_stan);


   for(int i = 0; i < strlen(wejscie); i++){
      if(wejscie[i] != '0' && wejscie[i] != '1'){
         printf("%c", wejscie[i]);
         fprintf(stderr, "Niedozwolone wejście. Błąd.\n");
         return EXIT_FAILURE;
      } else {
         obecny_stan = zmienStan(obecny_stan, wejscie[i]);
         printf("-%c->(q%d)", wejscie[i], obecny_stan);
      }
   }
   printf(" -> KONIEC\n");

   if(obecny_stan == q3){
      printf("Poprawne wejście, symulacja zakończona sukcesem.\n");
   } else {
      printf("Niepoprawne wejście, symulacja zakończona niepowodzeniem.\n");
   }

   return EXIT_SUCCESS;
}
