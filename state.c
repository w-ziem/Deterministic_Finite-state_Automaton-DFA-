#include "state.h"

stan_t zmienStan(stan_t aktualny, char wejscie) {
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