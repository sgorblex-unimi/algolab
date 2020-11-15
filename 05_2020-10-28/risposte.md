# Lezione 5


## 1. La vostra malloc
1. controlla se la malloc ha fallito;
2. il codice di errore del sistema (prob. 1);
3. esce dal programma con il codice di errore specificato;
4. "Allocazione di memoria fallita";
5. eh;
6. EH

## 2. Tanti elementi
1. popolare l'array allocato;
2. `scanf("%d", a+i);`;
3. stack;
4. heap: gli indirizzi allocati di a (a e successivi) sono allocati dalla malloc nello heap precedentemente;
5. in modo che il chiamante abbia al ritorno la lunghezza dell'array allocato;
6. il puntatore/array a;
7. modifica stdin e la zona di memoria di num e alloca memoria. Può produrre stdout se la malloc fallisce;
8. la read ha 3 variabili sullo stack; lo heap ha la roba allocata da my_malloc; il main dipende come l'hai fatto, il mio ha 3 variabili;
9. int -> char e %d -> %c.

## 3. Rovescia
1. ok
2. 5;
3. 3;
4. size è la dimensione totale, i è l'indice corrente;
5. l'array;
6. rappresenta l'ultimo indice scritto (viene passato per riferimento);
7. il programma alloca un'array di numeri terminati da 0 in una dimensione di memoria man mano crescente in modo da poterlo contenere, quindi stampa gli elementi dell'array al contrario;
8. riga 18: `size*=2`

## 5. Matrice
1. ad allocare l'array di puntatori (frastagliato non frastagliato);
2. `m[r]=...`;
3. ad allocare i singoli array (righe della matrice);
4. `*(*(m+r)+c)`;
5. puntatore a array di puntatori, array di puntatori, vari array di int indicati dall'array di puntatori;
6. il puntatore all'array """frastagliato""".
