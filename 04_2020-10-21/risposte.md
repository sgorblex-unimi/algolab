# Lezione 4


## 1

### 1.1
1. Puntatori a intero. È un modo di poter restituire più valori;
2. Uno è il puntatore e l'altra è la porzione di memoria puntata da esso. 4, 12;
3. `&h, &m, &s`;
4. `*h`, `*m`, `*s`;

### 1.3
1. Puntatore a intero;
2. In quanto già indirizzo;
3. ok;
4. A riempire (parzialmente) l'array;
5. A stampare in ordine inverso gli elementi della porzione riempita dell'array;
6. A puntare all'elemento "di turno" nell'array.


## 2

### 2.1
1. Puntatore a char;
2. Per scambiare i valori di a[i] e a[n-1];
3. Perché non viene preso in considerazione il primo elemento degli argomenti (percorso dell'eseguibile);
4. ?
5. Stampa gli argomenti (meno 0) scambiando il quarto e l'ultimo;
6. ScambiaConUltimo;
7. Non funzionerebbe perché la strcpy scorrerebbe gli indirizzi successivi ad `a[i]` (e analoghi) alla ricerca di `'\0'`;
8. Il programma, chiamato con un certo numero di argomenti, richiede all'utente di scegliere una posizione, il cui rispettivo argomento verrà scambiato con l'ultimo.
