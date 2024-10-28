# Splay Tree
Ideati da Tarjan e Sleator nel 1985 gli **Splay Tree** sono un tipo di struttura dati ad albero binario di ricerca e di conseguenza hanno le stesse operazioni principali:
- Inserimento
- Cancellazione
- Ricerca

Si assume che un nodo, oggetto di una di queste operazioni, nel tempo venga riutilizzato a breve, quindi si cerca di farlo diventare radice o di mantenerlo il più vicino possibile a quest'ultima.

L'operazione di ricerca all'interno di uno Splay Tree viene effettuata attravarso una procedura di **Splay**.
La procedura di Splay permette all'ultimo nodo su cui è stata effettuata una delle tre operazioni di essere spostato alla radice senza però andare contro la proprietà dell'albero binario di ricerca, ciò viene fatto attraverso una serie di rotazioni tra i nodi:
- Zig<br> <p align="center"> <img src="Image/Zig.png" alt="Zig operation" width="30%" height="30%"/> </p>
- Zig-Zig<br> <p align="center"> <img src="Image/Zig-zig.png" alt="Zig-zig operation" width="30%" height="30%"/> </p>
- Zig-Zag<br> <p align="center"> <img src="Image/Zig-zag.png" alt="Zig-zag operation" width="30%" height="30%"/> </p>
- Zag<br> <p align="center"> <img src="Image/Zag.png" alt="Zag operation" width="30%" height="30%"/> </p>
- Zag-Zag<br> <p align="center"> <img src="Image/Zag-zag.png" alt="Zag-zag operation" width="30%" height="30%"/> </p>
- Zag-Zig<br> <p align="center"> <img src="Image/Zag-zig.png" alt="Zag-zig operation" width="30%" height="30%"/> </p>

Il costo ammortizzato di ogni aggiustamento dovuto alla procedura di splay sarà **$O(\log_2(n))$**, quindi sia $m$ il numero di operazioni principali eseguite, si avrà un costo ammortizzato di **$O(m\ \log_2(n))$**
