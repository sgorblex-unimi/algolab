# Lezione 7


## 1.
- A: non viene creato un nodo;
- B: non viene aggiornato tail;
- C: non viene inserito il nodo;
- D: giusto;
- E: non aggiorna il campo tail (e fa schifo).


## 2.
- A: bisogna comunque scorrere la lista;
- B: bisogna comunque scorrere la lista;
- C: non trae vantaggio dall'informazione in più;
- D: non trae vantaggio dall'informazione in più (non basta il riferimento all'ultimo elemento per rimuoverlo in quanto è necessario aggiornare anche il riferimento dell'elemento precedente);
- E: non trae vantaggio dall'informazione in più;
- F: giusto, trae vantaggio dall'informazione in più (come già visto).


## 3.
- A: le implementazioni possono differire per molti aspetti, non è una buona idea;
- B: addAtEnd può essere molto efficiente anche per le liste monodirezionali con riferimento all'ultimo elemento;
- C: se la lista è semplice con un solo riferimento al primo elemento ambe le funzioni sono poco efficienti;
- D: non c'è correlazione;
- E: giusto.


## 4.
non so, restituisce il nodo precedente al valore oppure l'ultimo se non lo trova, null se è il primo o la lista è vuota;


## 5.
D, implemento una classica pila (se la cronologia è illimitata).
