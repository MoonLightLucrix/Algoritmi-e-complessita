# Splay Tree
Ideati da Tarjan e Sleator nel 1985 gli **Splay Tree** sono un tipo di struttura dati ad albero binario di ricerca e di conseguenza hanno le stesse operazioni principali:
- Inserimento
- Cancellazione
- Ricerca

Si assume che il nodo oggetto di una di queste operazioni, nel tempo venga riutilizzato a breve, quindi si cerca di farlo diventare radice o di mantenerlo il più vicino possibile a quest'ultima.

L'operazione di ricerca all'interno di uno Splay Tree viene effettuata attravarso una procedura di **Splay**.
La procedura di Splay permette all'ultimo nodo su cui è stata effettuata una delle tre operazioni di essere spostato alla radice senza però andare contro la proprietà dell'albero binario di ricerca, ciò viene fatto attraverso una serie di rotazioni tra i nodi:
- Zig 
- Zig-Zig
- Zig-Zag
