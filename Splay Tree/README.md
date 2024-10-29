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
- Zig<br> <div align="center"> <img src="Image/Zig.png" alt="Zig operation" width="30%" height="30%"/> </p>
- Zig-Zig<br> <div align="center"> <img src="Image/Zig-zig.png" alt="Zig-zig operation" width="30%" height="30%"/> </p>
- Zig-Zag<br> <div align="center"> <img src="Image/Zig-zag.png" alt="Zig-zag operation" width="30%" height="30%"/> </p>
- Zag<br> <div align="center"> <img src="Image/Zag.png" alt="Zag operation" width="30%" height="30%"/> </p>
- Zag-Zag<br> <div align="center"> <img src="Image/Zag-zag.png" alt="Zag-zag operation" width="30%" height="30%"/> </p>
- Zag-Zig<br> <div align="center"> <img src="Image/Zag-zig.png" alt="Zag-zig operation" width="30%" height="30%"/> </p>

## Analisi armortizzata
Il costo ammortizzato di ogni aggiustamento dovuto alla procedura di splay sarà $O(\log_2(n))$, quindi sia $m$ il numero di operazioni principali eseguite, si avrà un costo ammortizzato di $O(m\ \log_2(n))$, dove $n$ è il numero di nodi all'interno dell'albero.

In particolare si definiscano i costi per ognuna delle rotazioni:
| Rotazione | Costo |
|----------|----------|
| Zig | 1 |
| Zig-zig | 2 |
| Zig-zag | 2 |

Utilizzando il metodo del potenziale per calcolare il costo ammortizzato della procedura splay, si definiscano:

$$
S(\nu)=_{DEF}\text{numeri di nodi del sotto albero radicato in}\ \nu
$$

$$
R(\nu)=_{DEF}\text{Il rango di}\ \nu\text{, definito come}\ \log_2(S(\nu))
$$

$$
\Phi(T)=_{DEF}\text{La funzione potenziale, definita come} \sum _{\nu \in T} R(\nu)
$$

### Teorema
> Sia data la procedura di splay, il suo costo ammortizzato è al più

$$
3\ (R\ (ROOT(T))-R(x))+1
$$

### Dimostrazione
#### Caso Zig
<p align="center"> <img src="Image/ZigDim.png" alt="Zig dimostration" width="50%" height="50%"/>

Si può facilmente osservare che, prendendo in considerazione il nodo $x$:

$$
S_f(x) \geq S_i(x)
$$

Quindi:

$$
R_f(x) \geq R_i(x)
$$


$$
\Delta \Phi(T)=R_f(x)-R_i(x)
$$

$$
\Delta \Phi(T) \leq 3\ (R_f(x)-R_i(x))
$$

Si può quindi definire il costo ammortizzato del caso Zig come:

$$
\hat{c}_{zig} \leq 3\ (R_f(x)-R_i(x))+1
$$

#### Caso Zig-zig
<p align="center"> <img src="Image/ZigzigDim.png" alt="Zig-zig dimostration" width="50%" height="50%"/>
<p align=center>$\Delta \Phi(T)=R_f(x)+R_f(p)+R_f(n)-R_i(x)-R_i(p)-R_i(n)$</p>

Si nota immediatamente che:

<p align=center>$S_i(n)=S_f(x) \rightarrow R_i(n)=R_f(x)$</p>

Quindi:

<p align=center>$\Delta \Phi(T)=R_f(p)+R_f(n)-R_i(x)-R_i(p)$</p>

Si può maggiorare:

<p align=center>$S_f(x) \geq S_f(p) \rightarrow R_f(x) \geq R_f(p)$</p>

Ottenendo:

<p align=center>$\Delta \Phi(T) \leq R_f(x)+R_f(n)-R_i(x)-R_i(p)$</p>
<p align=center>$\Delta \Phi(T) \leq R_f(x)+R_f(n)-R_i(x)-R_i(p)+R_i(x)-R_i(x)$</p>

Applicando il _lemma tecnico_:

<p align=center>$S_i(x)+S_f(n) \leq S_f(x) \rightarrow R_i(x)+R_f(n) \leq 2\ R_f(x)-2$</p>
<p align=center>$\Delta \Phi(T) \leq 2\ R_f(x)-2+R_f(x)-2\ R_i(x)-R_i(p)$</p>

Si sottrae a $\Delta \Phi(T)$ la quantità $R_i(x)$ anziché $R_i(p)$, in questo modo la maggiorazione continua ancora a valere

<p align=center>$\Delta \Phi(T) \leq 3\ R_f(x)-2-2\ R_i(x)-R_i(x)$</p>
<p align=center>$\Delta \Phi(T) \leq 3\ R_f(x)-2-3\ R_i(x)$</p>
<p align=center>$\Delta \Phi(T) \leq 3\ (R_f(x)-R_i(x))-2$</p>

Si può quindi definire il costo ammortizzato del caso Zig-zig come:

<table align="center">
  <tr>
    <td> 
      $\hat{c}_{zig-zig} \leq 3\ (R_f(x)-R_i(x))$
    </td>
  </tr>
</table>

#### Caso Zig-zag
<p align="center"> <img src="Image/ZigzagDim.png" alt="Zig-zag dimostration" width="50%" height="50%"/>
<p align="center">$\Delta \Phi(T)=R_f(x)+R_f(p)+R_f(n)-R_i(x)-R_i(p)-R_i(n)$</p>

Si osserva che:

<p align="center">$S_i(n)=S_f(x) \rightarrow R_i(n)=R_f(x)$</p>

Quindi:

$$
\Delta \Phi(T)=R_f(p)+R_f(n)-R_i(x)-R_i(p)
$$

Usando il _lemma tecnico_:

$$
\Delta \Phi(T) \leq 2\ R_f(x)-2-R_i(x)-R_i(p)
$$

Si sottrae a $\Delta \Phi(T)$ la quantità $R_i(x)$ anziché $R_i(p)$, in questo modo la maggiorazione continua ancora a valere

<p align="center">$\Delta \Phi(T) \leq 2\ R_f(x)-2-R_i(x)-R_i(x)$</p>
<p align="center">$\Delta \Phi(T) \leq 2\ R_f(x)-2-2\ R_i(x)$</p>
<p align="center">$\Delta \Phi(T) \leq 2\ (R_f(x)-R_i(x))-2$</p>

Maggiorando per 3 anziché 2 vale ancora la maggiorazione:

$$
  \Delta \Phi(T) \leq 3\ (R_f(x)-R_i(x))-2
$$

Si può quindi definire il costo ammortizzato del caso Zig-zag come:

<table align="center">
  <tr>
    <td>
      $\hat{c}_{zig-zag} \leq 3\ (R_f(x)-R_i(x))$
    </td>
  </tr>
</table>
