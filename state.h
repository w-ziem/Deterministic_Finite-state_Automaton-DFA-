#ifndef _STATE_
#define STATE

typedef struct
{
    int nast_stan[2]; //kazdy stan będzie zawierał wskaźniki do dwóch stanów, do których może przejść - nast_stan[0] dla wejścia "0" oraz nast_stan[1] dla wejścia "1"
} state;

#endif

