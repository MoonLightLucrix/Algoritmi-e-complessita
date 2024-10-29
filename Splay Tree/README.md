# Splay Tree
## Introduzione
Gli Splay Tree sono una struttura dati ad albero binario di ricerca inventata da Tarjan e Sleator nel 1985. Come altri alberi di ricerca, permettono di eseguire le operazioni di:
- Inserimento
- Cancellazione
- Ricerca

## Procedura di Splay
Si assume che un nodo, oggetto di una di queste operazioni, nel tempo venga riutilizzato a breve, quindi si cerca di farlo diventare radice o di mantenerlo il più vicino possibile a quest'ultima.

La caratteristica distintiva degli Splay Tree è la procedura di **splay**, che sfrutta il principio di località temporale, cioè l'ipotesi che un nodo recentemente usato abbia una buona probabilità di essere riutilizzato a breve.
Lo splay consente di spostare il nodo oggetto dell'ultima operazione fino alla radice, oppure vicino a essa, ottimizzando le operazioni future senza violare le proprietà dell'albero binario di ricerca.

### Operazioni di rotazione nello Splay Tree
La procedura di splay si basa su una serie di rotazioni per spostare il nodo selezionato verso la radice dell'albero.
Le principali operazioni di rotazione sono:

- Zig<br> <div align="center"> <img src="Image/Zig.png" alt="Zig operation" width="30%" height="30%"/> </p>
- Zig-Zig<br> <div align="center"> <img src="Image/Zig-zig.png" alt="Zig-zig operation" width="30%" height="30%"/> </p>
- Zig-Zag<br> <div align="center"> <img src="Image/Zig-zag.png" alt="Zig-zag operation" width="30%" height="30%"/> </p>
- Zag<br> <div align="center"> <img src="Image/Zag.png" alt="Zag operation" width="30%" height="30%"/> </p>
- Zag-Zag<br> <div align="center"> <img src="Image/Zag-zag.png" alt="Zag-zag operation" width="30%" height="30%"/> </p>
- Zag-Zig<br> <div align="center"> <img src="Image/Zag-zig.png" alt="Zag-zig operation" width="30%" height="30%"/> </p>

## Analisi ammortizzata
La complessità ammortizzata per ciascuna rotazione della procedura di splay è di $O(\log_2(n))$, con $n$ numero di nodi.
In termini di complessità, su una sequenza di $m$ operazioni di inserimento, cancellazione o ricerca, il costo totale risulterà $O(m \cdot \log_2(n))$.

### Costi di rotazione
Ogni tipo di rotazione ha un costo definito come segue:

| Rotazione | Costo |
|----------|----------|
| Zig | 1 |
| Zig-zig | 2 |
| Zig-zag | 2 |

Per calcolare il costo ammortizzato della procedura di splay, possiamo utilizzare il **metodo del potenziale**.
Definiamo le seguenti grandezze:

- $S(\nu)$: numeri di nodi del sotto albero radicato in $\nu$.
- $R(\nu)=_{DEF} \log_2(S(\nu))$: rango del nodo $\nu$.
- $\Phi(T)=\sum _{\nu \in T}R(\nu)$: funzione potenziale dell'albero $T$.

### Teorema sul costo ammortizzato
> Il costo ammortizzato della procedura di splay è al più
>
> $$
> 3 \cdot (R(ROOT(T))-R(x))+1
> $$
>
> dove $x$ è il nodo in cui viene eseguita la splay.

### Dimostrazione per casi
#### Caso Zig
<p align="center"> <img src="Image/ZigDim.png" alt="Zig dimostration" width="50%" height="50%"/>

Si consideri il nodo $x$.
Dopo la rotazione Zig, $S_f(x)\leq S_i(x)$, quindi $R_f(x)\leq R_i(x)$.
Il cambiamento nella funzione potenziale risulta:

$$
\Delta \Phi(T)=R_f(x)-R_i(x) \leq 3 \cdot (R_f(x)-R_i(x))
$$

Pertanto, il costo ammortizzato della rotazione Zig è:

$$
\hat{c}_{zig} \leq 3 \cdot (R_f(x)-R_i(x))+1
$$

#### Caso Zig-zig
<p align="center"> <img src="Image/ZigzigDim.png" alt="Zig-zig dimostration" width="50%" height="50%"/>

La differenza della funzione potenziale è dato da:

$$
\Delta \Phi(T)=R_f(x)+R_f(p)+R_f(n)-R_i(x)-R_i(p)-R_i(n)
$$

Dove $S_i(n)=S_f(x) \rightarrow R_i(n)=R_f(x)$, da cui segue:

$$
\Delta \Phi(T)=R_f(p)+R_f(n)-R_i(x)-R_i(p)
$$

Si può maggiorare:

$$
S_f(x) \geq S_f(p) \rightarrow R_f(x) \geq R_f(p)
$$

Ottenendo:

$$
\Delta \Phi(T) \leq R_f(x)+R_f(n)-R_i(x)-R_i(p)
$$

$$
\Delta \Phi(T) \leq R_f(x)+R_f(n)-R_i(x)-R_i(p)+R_i(x)-R_i(x)
$$

Applicando il _lemma tecnico_ $S_i(x)+S_f(n) \leq S_f(x) \rightarrow R_i(x)+R_f(n) \leq 2\ R_f(x)-2$ si ottiene:

$$
\Delta \Phi(T) \leq 2 \cdot R_f(x)-2+R_f(x)-2 \cdot R_i(x)-R_i(p)
$$

Si sottrae a $\Delta \Phi(T)$ la quantità $R_i(x)$ anziché $R_i(p)$, in questo modo la maggiorazione continua ancora a valere

$$
\Delta \Phi(T) \leq 3 \cdot R_f(x)-2-2 \cdot R_i(x)-R_i(x)
$$

$$
\Delta \Phi(T) \leq 3 \cdot R_f(x)-2-3 \cdot R_i(x)
$$

$$
\Delta \Phi(T) \leq 3 \cdot (R_f(x)-R_i(x))-2
$$

E il costo ammortizzato della rotazione Zig-Zig è quindi:

$$
\hat{c}_{zig-zig} \leq 3 \cdot (R_f(x)-R_i(x))
$$

#### Caso Zig-zag
<p align="center"> <img src="Image/ZigzagDim.png" alt="Zig-zag dimostration" width="50%" height="50%"/>

$$
\Delta \Phi(T)=R_f(x)+R_f(p)+R_f(n)-R_i(x)-R_i(p)-R_i(n)
$$

Si osserva che:

$$
S_i(n)=S_f(x) \rightarrow R_i(n)=R_f(x)
$$

Quindi:

$$
\Delta \Phi(T)=R_f(p)+R_f(n)-R_i(x)-R_i(p)
$$

Usando il _lemma tecnico_:

$$
\Delta \Phi(T) \leq 2\ R_f(x)-2-R_i(x)-R_i(p)
$$

Si sottrae a $\Delta \Phi(T)$ la quantità $R_i(x)$ anziché $R_i(p)$, in questo modo la maggiorazione continua ancora a valere

$$
\Delta \Phi(T) \leq 2\ R_f(x)-2-R_i(x)-R_i(x)
$$

$$
\Delta \Phi(T) \leq 2\ R_f(x)-2-2\ R_i(x)
$$

$$
\Delta \Phi(T) \leq 2\ (R_f(x)-R_i(x))-2
$$

Maggiorando per 3 anziché 2 vale ancora la maggiorazione:

$$
\Delta \Phi(T) \leq 3\ (R_f(x)-R_i(x))-2
$$

Si può quindi definire il costo ammortizzato del caso Zig-zag come:

$$
\hat{c}_{zig-zag} \leq 3\ (R_f(x)-R_i(x))
$$

#### Costo ammortizzato di uno splay

Quindi sia definito il costo ammortizzato di uno splay considerando tutte le possibili rotazioni possibili come:

$$
\hat{c}_{splay} \leq \sum _{j=0}^{n} 3\ (R _f^{(j)}(x)-R _i^{(j)}(x))+1
$$

Equivale a scrivere:

$$
\hat{c}_{splay} \leq \sum _{j=0}^{n} 3\ (R _f^{(j)}(x)-R _f^{(j-1)}(x))+1
$$

La sommatoria può essere svolta come _serie telescopica_:

$$
\hat{c}_{splay} \leq 3\ (R _f^{(n)}(x)-R _f^{(1)}(x))+1
$$

Dove $R _f^{(n)}(x)$ equivale alla posizione del nodo $x$ dopo aver eseguito tutte le rotazioni quindi al rango quando $x$ si troverà alla radice, mentre $R _f^{(1)}(x)$ il rango del nodo quando è stato appena inserito.

Quindi si può riscrivere la disequazione come:

$$
\hat{c}_{splay} \leq 3\ (R(ROOT(T))-R(x))+1
$$

Continuando si può ancora maggiorare:

$$
\hat{c}_{splay} \leq 3\ (R(ROOT(T))-R(x))+1 \leq 3\ (R(ROOT(T)))+1
$$

Considerando che $R(ROOT(T))$ è $\log_2(n)$ si ottiene:

$$
\hat{c}_{splay} \leq 3\ \log_2(n)+1
$$

Si ricava il costo armortizzato della procedura splay come:

$$
O(\log_2(n))
$$

Se consideriamo il fatto che può essere eseguito su $m$ operazioni di _inserimento_, _cancellazione_ e _ricerca_ si ottiene una complessità armortizzata di:

$$
O(m\ \log_2(n))\ \square
$$
