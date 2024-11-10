#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "state.h"

void sprawdz_wynik(stan_t stan) {
   if(stan == q3){
      printf("Poprawne wejście, symulacja zakończona sukcesem.\n");
   } else {
      printf("Niepoprawne wejście, symulacja zakończona niepowodzeniem.\n");
   }

}

char* pobierz_wejscie(int dlugosc){
   char *ciag = malloc((dlugosc+1) * sizeof(char)); //alokowanie miejsca w pamięci dla ciągu wejściowego (+1 ponieważ jeszcze znak końca \0)
   if(ciag == NULL) { //sprawdzenie czy alokowanie pamięci zakończyło się poprawnie
      fprintf(stderr, "Bład alokacji pamięci");
      return NULL;
   }

   printf("Podaj ciąg wejściowy: ");
   fgets(ciag, dlugosc+1, stdin); //pobieranie ciągu wejściowego (dlugosc+1 ponieważ dodajemy miejsce na znak końca linii, która funkcja automatycznie dodaje)
   return ciag;
}

int main() {
   // char wejscie[7] = "0010112"; 
   // Pobieranie długości wejścia od użytkownika
   char dlugosc_str[10];
   printf("Podaj długość ciągu wejściowego: ");
   fgets(dlugosc_str, sizeof(dlugosc_str), stdin);
   int dlugosc = atoi(dlugosc_str);


   // Pobieranie ciągu wejściowego
   char* wejscie = pobierz_wejscie(dlugosc);
   if (!wejscie){
      return EXIT_FAILURE;
   }
   //TODO: sprawdzic czy podana ilosc znakow i ta wpisana jest taka sama.
   // if(strlen(wejscie) != dlugosc){
   //    fprintf(stderr, "Podano błędą ilość znaków.\n");
   //    return EXIT_FAILURE;
   // }
   
   stan_t obecny_stan = q0; //ustawienie stanu początkowego
   
   printf("sprawdzany ciąg wejściowy: %s\n", wejscie);
   printf("START -> (q%d)", obecny_stan);

   //Przetwarzanie ciągu wejściowego
   for(int i = 0; i < dlugosc; i++){
      if(wejscie[i] != '0' && wejscie[i] != '1'){
         printf(" | próba zmiany stanu wejściem %c\n", wejscie[i]);
         fprintf(stderr, "Niedozwolone wejście, dozwolone wejścia to {0,1}. Błąd.\n");
         return EXIT_FAILURE;
      } else {
         obecny_stan = zmienStan(obecny_stan, wejscie[i]);
         printf(" -%c-> (q%d)", wejscie[i], obecny_stan);
      }
   }
   free(wejscie);
   printf(" -> KONIEC\n");

   sprawdz_wynik(obecny_stan);

   return EXIT_SUCCESS;
}
