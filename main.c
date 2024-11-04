#include <stdio.h>
#include <stdlib.h>


typedef enum {q0, q1, q2, q3} stan;


stan zmienStan(stan aktualny, char wejscie) {
    switch (aktualny)
    {
    case q0: return (wejscie == '0') ? q1 : q2;
    break;
    case q1: return (wejscie == '0') ? q3 : q0;
    break;
    case q2: return (wejscie == '0') ? q0 : q3;
    break;
    case q3: return (wejscie == '0') ? q1 : q2;
    break;
    default : return q0; //bazowo wracamy na start  
    }
}  



int main(int argc, char *argv[]) {
    char wejscia[] = argc > 1 ? argv[1] : '1111';
    printf("%s", wejscia);

}