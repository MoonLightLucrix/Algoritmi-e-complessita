# Splay Tree
## Introduzione
Ideati da Tarjan e Sleator nel 1985 gli **Splay Tree** sono un tipo di struttura dati ad albero binario di ricerca e di conseguenza hanno le stesse operazioni principali:
- Inserimento
- Cancellazione
- Ricerca

## Procedura di Splay
Si assume che un nodo, oggetto di una di queste operazioni, nel tempo venga riutilizzato a breve, quindi si cerca di farlo diventare radice o di mantenerlo il più vicino possibile a quest'ultima.

L'operazione di ricerca all'interno di uno Splay Tree viene effettuata attravarso una procedura di **Splay**.
La procedura di Splay permette all'ultimo nodo su cui è stata effettuata una delle tre operazioni di essere spostato alla radice senza però andare contro la proprietà dell'albero binario di ricerca, ciò viene fatto attraverso una serie di rotazioni tra i nodi:
- Zig<br> <p align="center"> <img src="Image/Zig.png" alt="Zig operation" width="30%" height="30%"/> </p>
- Zig-Zig<br> <p align="center"> <img src="Image/Zig-zig.png" alt="Zig-zig operation" width="30%" height="30%"/> </p>
- Zig-Zag<br> <p align="center"> <img src="Image/Zig-zag.png" alt="Zig-zag operation" width="30%" height="30%"/> </p>
- Zag<br> <p align="center"> <img src="Image/Zag.png" alt="Zag operation" width="30%" height="30%"/> </p>
- Zag-Zag<br> <p align="center"> <img src="Image/Zag-zag.png" alt="Zag-zag operation" width="30%" height="30%"/> </p>
- Zag-Zig<br> <p align="center"> <img src="Image/Zag-zig.png" alt="Zag-zig operation" width="30%" height="30%"/> </p>

## Analisi armortizzata
Il costo ammortizzato di ogni aggiustamento dovuto alla procedura di splay sarà $O(\log_2(n))$, quindi sia $m$ il numero di operazioni principali eseguite, si avrà un costo ammortizzato di $O(m\ \log_2(n))$, dove $n$ è il numero di nodi all'interno dell'albero.

In particolare si definiscano i costi per ognuna delle rotazioni:
| Rotazione | Costo |
|----------|----------|
| Zig | 1 |
| Zig-zig | 2 |
| Zig-zag | 2 |

Utilizzando il metodo del potenziale per calcolare il costo ammortizzato della procedura splay, si definiscano:

<p align=center>$S(\nu)=_{DEF}\text{numeri di nodi del sotto albero radicato in}\ \nu$</p>
<p align=center>$R(\nu)=_{DEF}\text{Il rango di}\ \nu\text{, definito come}\ \log_2(S(\nu))$</p>
<p align=center>$\Phi(T)=_{DEF}\text{La funzione potenziale, definita come}\ \sum_{\nu \in T}R(\nu)$</p>

### Teorema
> Sia data la procedura di splay, il suo costo ammortizzato è al più
> <p align="center">$3\ (R\ (ROOT(T))-R(x))+1$</p>

### Dimostrazione
#### Caso Zig
<p align="center"> <img src="Image/ZigDim.png" alt="Zig dimostration" width="50%" height="50%"/>

Si può facilmente osservare che, prendendo in considerazione il nodo $x$:

<p align=center>$S_f(x) \geq S_i(x)$</p>

Quindi

<p align=center>$R_f(x) \geq R_i(x)$</p>
<p align=center>$\Delta \Phi(T)=R_f(x)-R_i(x)$</p>
<p align=center>$\Delta \Phi(T) \leq 3\ (R_f(x)-R_i(x))$</p>

Si può quindi definire il costo ammortizzato del caso Zig come:

<table align="center">
  <tr>
    <td> 
      $\hat{c}_{zig} \leq 3\ (R_f(x)-R_i(x))+1$
    </td>
  </tr>
</table>

#### Caso Zig-zig
<p align="center"> <img src="Image/ZigzigDim.png" alt="Zig dimostration" width="50%" height="50%"/>
