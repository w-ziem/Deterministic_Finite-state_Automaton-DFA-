# deterministyczny automat skonczony


- q0 jest stanem początkowym
- q3 jest stanem końcowym

program dostaje ciąg 01, który po kolei wykonuje kroki i sprawdza czy zakonczyl sie powodzeniem

./a.out  0010110010

wyciek działania programu (aktualny stan)
>001011

>(q0) -0-> (q1) -0-> (q3) -1-> (q2) -0-> (q0) -1-> (q2) -1-> (q3)

>stan: q3