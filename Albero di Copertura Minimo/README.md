# 8 Alberi di copertura minimi

# Indice

- **8.1** [Definizione](#81-definizione)
- **8.2** [Taglio](#82-taglio)
- **8.3** [Processi di "Passi blu" e "Passi rossi"](#83-processi-di-passi-blu-e-passi-rossi)
- **8.4** [Invariante del colore](#84-invariante-del-colore)
    - **8.4.1** [Teorema dell'invariante del colore](#841-teorema-dellinvariante-del-colore)
    - **8.4.2** [Corollario dell'invariante del colore](#842-corollario-dellinvariante-del-colore)
    - **8.4.3** [Dimostrazione dell'invariante del colore](#843-dimostrazione-dellinvariante-del-colore)
    - **8.4.4** [Lemma dell'invariante del colore](#844-lemma-dellinvariante-del-colore)
    - **8.4.5** [Dimostrazione per l'applicazione dei passi blu e passi rossi](#845-dimostrazione-per-lapplicazione-dei-passi-blu-e-passi-rossi)
- **8.5** [Algoritmo di Kruskal (1956)](#85-algoritmo-di-kruskal-1956)
    - **8.5.1** [Definizione dell'algoritmo di Kruskal](#851-definizione-dellalgoritmo-di-kruskal)
    - **8.5.2** [Correttezza dell'algoritmo di Kruskal](#852-correttezza-dellalgoritmo-di-kruskal)
    - **8.5.3** [Complessità dell'algoritmo di Kruskal](#853-complessità-dellalgoritmo-di-kruskal)

## 8.1 Definizione

Sia $(G,w)$ dove $G=(V,E)$ un grafo connesso, non orientato e pesato tramite la funzione $w: E \to \mathbb{R}$, un **albero di copertura minimo** $T=(V,E')$ è un sottografo di $G$ dove $|E'| = |V| - 1$ ed è scelto in maniera tale che:

$$
T = \arg \min_{E' \subseteq E} \sum_{e \in E'} w(e)
$$

## 8.2 Taglio

Sia $(G,w)$ dove $G=(V,E)$ un grafo connesso, non orientato e pesato tramite la funzione $w: E \to \mathbb{R}$, si dice **taglio** di $G$ una partizione $(V_1,V_2)$ non banale (ad esempio $V_1=\emptyset$ e $V_2=\emptyset$). Si dice che un arco $(u,v)$ attraversa il taglio se $u \in V_1$ e $v \in V_2$.

## 8.3 Processi di "Passi blu" e "Passi rossi"

Sia $(G,w)$ dove $G=(V,E)$ un grafo connesso, non orientato e pesato tramite la funzione $w: E \to \mathbb{R}$.

Inizialmente nessun arco $(u,v) \in E$ è colorato.

Si procede con un **passo blu**:

- Si seleziona un taglio all'interno del grafo.
- Si colora di blu l'arco di peso minore che attraversa il taglio.

Si procede con un **passo rosso**:

- Si seleziona un ciclo all'interno del grafo.
- Si colora di rosso l'arco di peso maggiore che forma il ciclo.

## 8.4 Invariante del colore

Ad ogni passo durante la procedura di colorazione esiste un albero di copertura minimo $T \subseteq G$ con tutti gli archi colorati di blu e nessuno di rosso.

### 8.4.1 Teorema dell'invariante del colore

Ogni esecuzione del processo di colorazione colora tutti gli alberi di blu mantenendo l'invariante del colore.

### 8.4.2 Corollario dell'invariante del colore

Alla fine del processo di colorazione tutti gli archi blu formano un albero di copertura minimo.

### 8.4.3 Dimostrazione dell'invariante del colore

Si definisce $E'$ come l'insieme di tutti gli archi colorati di blu all'interno del grafo connesso, non orientato e pesato $G=(V,E)$, sia $T=(V,E'')$ un albero di copertura minimo di $G$, quindi per l'invariante del colore $E' \subseteq E''$.
Per il teorema dell'invariante del colore anche $E''$ deve essere un insieme di archi tutti colorati di blu, ovvero $E'' \subseteq E'$, allora in conclusione $E'=E''$, quindi anche $(V,E')$ è un albero di copertura minimo.

Per dimostrare che l'invariante del colore sia verificata ad ogni passo, si procederà per **induzione**:

- **Caso base**: All'inizio nessun arco è colorato, l'invariante del colore è banalmente soddisfatta.

- **Passo $k$**: Al passo $k$ esiste un albero di copertura minimo $T=(V,E')$ con tutti gli archi colorati di blu e nessuno di rosso.

- **Passo $k+1$**:
    - **Passo blu**: Supponiamo che al passo $k+1$ si sia colorato di blu $e=(u,v)$, ora se $e \in T$ l'invariante del colore è soddisfatta anche al passo $k+1$, se no si prenda in cosiderazione un percorso $\pi_{u,v}$ (che esiste perché $T$ è un albero di copertura minimo) e si individua più in particolare l'arco $(u',v') \in \pi_{u,v}$ che attraversa il taglio $(V_1,V_2)$.
    Adesso $(u',v')$ non può essere colorato di blu perché attraversa il taglio e non può essere rosso perché fa parte dell'albero di copertura minimo, quindi si decida di colorare $(u,v)$ di blu scoprendo di avere una situazione del tipo $w((u,v)) \leq w((u',v'))$ generando un nuovo albero chiamato $T'$ sí formato: $T'.E=(T.E' \setminus \{(u',v')\}) \cup \{(u,v)\}$, ora sapendo che il peso dell'arco $(u,v)$ può essere al più lo stesso dell'arco $(u',v')$ quindi segue che $w(T') \leq w(T)$ e sapendo che $T$ è un albero di copertura minimo, i due pesi degli alberi devono necessariamente coincidere $w(T)=w(T')$ quindi $T'$ è una albero di copertura minimo che al passo $k+1$ contiene tutti gli archi blu e nessun arco rosso.
    - **Passo rosso**: Supponiamo che al passo $k+1$ si sia colorato di rosso $e=(u,v)$, ora se $e \notin T$ l'invariante del colore è soddisfatta anche al passo $k+1$, se no $T \setminus \{e\}$ indentifica due **componenti connesse** rappresentate dal taglio $(V_1,V_2)$ di $V$, quindi si prenda in considerazione il ciclo $(u_1,u_2), (u_2,u_3),…,(u_k,u_1)$ e si individua più in particolare l'arco $f$ di peso minore che attraversa il taglio $(V_1,V_2)$.
    Adesso $f$ non può essere blu perché non appartiene a $T$ e non può essere rosso perché fa parte del ciclo scelto, adesso si decida di colorare $f$ di blu per via della situazione del tipo $w(f) \leq w(e)$ generando un nuovo albero di copertura minimo chiamata $T''$ sí formato $T''.E=(T.E' \setminus \{e\}) \cup \{f\}$, ora sapendo che il peso dell'arco $f$ può essere al più lo stesso dell'arco $e$ quindi segue $w(T'') \leq w(T)$ e sapendo che $T$ è un albero di copertura minimo, i due pesi degli alberi devono necessariamente coincidere $w(T)=w(T'')$ quindi $T''$ è un albero di copertura minimo che al passo $k+1$ contiene tutti gli archi blu e nessun arco rosso. $\quad \square$

### 8.4.4 Lemma dell'invariante del colore

Alla fine dell'esecuzione del processo di colorazione tutti gli archi del grafo connesso, non orientato e pesato $G=(V,E)$ sono colorati.

### 8.4.5 Dimostrazione per l'applicazione dei passi blu e passi rossi

Si dimostri per assurdo che dopo il processo di colorazione rimanga un arco $e=(u,v)$ non ancora colorato.
Sia $T$ un albero di copertura minimo che verifica l'invariante del colore, quindi se $e \in T$, cancellandolo si ottengono due componenti connesse rappresentate dal taglio $(V_1,V_2)$ questo taglio non è attraversato da nessun arco colorato di blu, ne di nessun altro colore, quindi si procede con un **passo blu**.
Se $e \notin T$, allora esiste un percorso $\pi_{u,v}$ che collega $u$ a $v$, quindi si consideri il ciclo $\pi_{u,v} \cup \{e\}$ che non contiene archi colorati di rosso, ne di nessun altro colore, quindi si procede con un **passo rosso**. $\quad \square$

## 8.5 Algoritmo di Kruskal (1956)

Si tratta di un algoritmo **greedy**, basato su un processo **non deterministico** di colorazione che mantiene l'**invariante del colore**.

### 8.5.1 Definizione dell'algoritmo di Kruskal

Sia $(G,w)$ dove $G=(V,E)$ un grafo non orientato, connesso e pesato tramite la funzione $w: E \to \mathbb{R}$ e sia la **segnatura** di $G$ definita come

$$
\Sigma_w(G)=(e_1, e_2, e_3,…,e_k)
$$

la sequenza di $e \in E$ in ordine **non decrescente** in base al loro peso

$$
w(e_1) \leq w(e_2) \leq w(e_3) \leq … \leq w(e_k)
$$

allora seguendo tale ordinamento se $e_i$ attraversa un taglio $(V_1,V_2)$ lo si colori di **blu**, altrimenti lo si colori di **rosso**.

#### Pseudo-codice di Kruskal

```
kruskal(G,w):
    T←(V,Ø);
    for v in G.V
    do
        makeSet(v);
    sort(G.E,w);
    for (u,v) in G.E
    do
        if(findSet(u)≠findSet(v))
        then
            T.E←T.E+(u,v); 
            unite(u,v);
        end if
    return T;
```

### 8.5.2 Correttezza dell'algoritmo di Kruskal

Sia $w(e_1) \leq w(e_2) \leq w(e_3) \leq … \leq w(e_k)$ l'ordinamento di $E$ utilizzato e siano $op(e_1), op(e_2), op(e_3),…,op(e_k)$ le operazioni di colorazione effettuate dall'algoritmo di Kruskal si proceda per induzione per $i=1,…,k$:
- **Passo blu**: Sia $e_i$ l'arco che collega i vertici $u_i$ e $v_i$, si definiscano le due componenti connesse $S_i$ e $V \setminus S_i$ che formano il taglio $(S_i.V, V \setminus S_i.V)$ e sia $e_i$ l'arco di peso minimo che lo attraversa, mentre tutti gli archi $e \in S_i.E$ di peso minore $w(e) \leq w(e_i)$ sono già colorati, allora si può procedere con un passo blu.
- **Passo rosso**: Sia $e_i$ l'arco che collega i vertici $u_i$ e $v_i$ i quali sono connessi da un percorso $\pi_{u_i,v_i}$ all'interno dello stesso albero di copertura minimo $T$, sia quindi $\pi_{u_i,v_i} \cup e_i$ un ciclo dove $e_i$ è l'unico arco non colorato, allora si può colorare $e_i$ di rosso con un passo rosso.

### 8.5.3 Complessità dell'algoritmo di Kruskal

Si ha che l'ordinamento degli archi ha costo $\mathcal{O}(|E| \cdot \log_2{|V|})$, mentre il costo per la **Union-Find** è dato da:
- $|V|$ chiamate a `makeSet`;
- $2 \cdot |E|$ chiamate a `findSet`;
- $|V|-1$ chiamate a `unite`.

ovvero un costo di $\mathcal{O}((|E| \cdot \log_2(|V|)) \cdot \alpha(|V|))$.

Ma poiché la complessità di $|V| = \mathcal{O}(|E|)$ la complessità sarà $\mathcal{O}(|E| \cdot \log_2(|V|))$.