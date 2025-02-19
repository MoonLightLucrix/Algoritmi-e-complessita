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
- **8.6** [Algoritmo di Prim (1957)](#86-algoritmo-di-prim-1957)
    - **8.6.1** [Definizione dell'algoritmo di Prim](#861-definizione-dellalgoritmo-di-prim)
    - **8.6.2** [Correttezza dell'algoritmo di Prim](#862-correttezza-dellalgoritmo-di-prim)
    - **8.6.3** [Complessità dell'algoritmo di Prim](#863-complessità-dellalgoritmo-di-prim)
- **8.7** [Unicità dell'albero di copertura minimo](#87-unicità-dellalbero-di-copertura-minimo)
    - **8.7.1** [Lemma dell'unicità dell'albero di copertura minimo](#871-lemma-dellunicità-dellalbero-di-copertura-minimo)
    - **8.7.2** [Dimostrazione dell'unicità dell'albero di copertura minimo](#872-dimostrazione-dellunicità-dellalbero-di-copertura-minimo)

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

## 8.6 Algoritmo di Prim (1957)

### 8.6.1 Definizione dell'algoritmo di Prim

Sia $(G,w)$ dove $G=(V,E)$ un grafo connesso, non orientato e pesato tramite la funzione $w: E \to \mathbb{R}$ e sia $s \in V$ il vertice di partenza o **radice** per la costruzione dell'albero di copertura minimo $T$.
Allora si eseguino per $|V|-1$ volte le seguenti operazioni:
- Si consideri l'insieme di archi blu che fanno parte dell'albero $T$.
- Si selezioni l'arco di peso minimo che connette $T$ ad un vertice esterno.
- Si colori di blu tale arco aggiungendo il vertice a $T$.

#### Pseudo-codice di Prim

```
prim(G,w,s):
    for v in G.V
    do
        v.key←∞;
        v.pred←NIL;
    s.key=0;
    q←makeHeap(G.V);
    while(q≠Ø)
    do
        u←extractMin(q);
        for(v in adj[u])
        do
            if((v in q) && (w(u,v)<v.key))
            then
                decreaseKey(Q,v,w(u,v));
                v.pred←u;
            end if
    return {(v.pred,v) : v in G.V \ {s}};
```

### 8.6.2 Correttezza dell'algoritmo di Prim

Sia $(G,w)$ dove $G=(V,E)$ un grafo non orientato, connesso e pesato tramite la funzione $w: E \to \mathbb{R}$ e sia $T=(V,E')$ l'albero blu che viene costruito passo dopo passo della procedura dell'algoritmo di Prim aggiungendo ad $E'$ gli archi di $G$ di peso minimo che sono incidenti a $T$ e che collegano i vertici $v \in V \setminus T.V$.

Si dimostra per induzione su $|V|-1$ passi della procedura dell'algoritmo di Prim che vengono selezionati solo archi blu di peso minimo.
- **Caso base**: Non è stato selezionato nessun arco blu e l'unico vertice presente in $T$ è $s$ ovvero il vertice di partenza o radice dell'albero.
- **Passo $k$**: Sia $S$ l'insieme di tutti i vertici selezionati che formano l'albero blu parziale $T$ e si identifichi il taglio $(S,V \setminus S)$, dove $S \neq \emptyset$ perché deve contenere il vertice $s$ e $V \setminus S \neq \emptyset$ se no $T$ sarebbe già un albero di copertura minimo. Tutti gli archi che attraversano il taglio sono non colorati perché gli archi blu sono solo all'interno di $S$, la procedura trova l'arco di peso minimo che collega un vertice $u \in S$ ad un vertice $v \in V \setminus S$ e lo colora di blu.
- **Passo $|V|-1$**: Al passo $|V|-1$ viene selezionato l'ultimo arco blu, si noti che $T$ è un albero che collega tutti i vertici di $G$ e contenente $|V|-1$ archi blu.

Quindi l'albero $T$ costruito contiene solo archi blu, dato che ogni passo della procedura rispetta l'invariante del colore esiste un albero di copertura minimo che contiene tutti gli archi blu e nessun arco rosso, Dato che $T.E \subseteq MST.E$ segue $w(T) \leq w(MST)$, ma siccome l'albero di copertura minimo **deve** avere peso minore si ha

$$
w(MST) \leq w(T) \leq w(MST)
$$

quindi $T$ è un albero di copertura minimo. $\quad \square$

### 8.6.3 Complessità dell'algoritmo di Prim

La procedura di generazione dell'albero di copertura minimo di Prim prevede due fasi:
- **Inizializzazione**
- **Costruzione** `extractMin` e `decreaseKey`

Prim utilizza gli heap per tenere traccia degli archi di peso minimo ed utilizzado gli **Heap di Fibonacci** la complessità può essere diminuita:

|                            | Heap Binari                                | Heap Binomiali                           | Heap di Fibonacci                          |
|----------------------------|--------------------------------------------|------------------------------------------|--------------------------------------------|
| Inizializzazione           | $\mathcal{O}(\|V\|)$                       | $\mathcal{O}(\|V\|)$                     | $\mathcal{O}(\|V\|)$                         |
|  $\|V\|$ `extractMin`  | $\mathcal{O}(\|V\| \cdot \log_2(\|V\|))$ | $\mathcal{O}(\|V\| \cdot \log_2(\|V\|))$ | $\mathcal{O}(\|V\| \cdot \log_2(\|V\|))$       |
| $\|E\|$ `decreaseKey`       | $\mathcal{O}(\|E\| \cdot \log_2(\|V\|))$ | $\mathcal{O}(\|E\| \cdot \log_2(\|V\|))$ | $\mathcal{O}(\|E\| + \|V\| \cdot \log_2(\|V\|))$ |
|                            | $\mathcal{O}(\|E\| \cdot \log_2(\|V\|))$   | $\mathcal{O}(\|E\| \cdot \log_2(\|V\|))$ | $\mathcal{O}(\|E\| + \|V\| \cdot \log_2(\|V\|))$ |

## 8.7 Unicità dell'albero di copertura minimo

### 8.7.1 Lemma dell'unicità dell'albero di copertura minimo

Sia $(G,w)$ dove $G=(V,E)$ è un grafo non orientato, connesso e pesato tramite la funzione $w : E \to \mathbb{R}$ **iniettiva**.
Allora $G$ ammette un unico albero di copertura minimo.

### 8.7.2 Dimostrazione dell'unicità dell'albero di copertura minimo

Siano $T_1$ e $T_2$ dove $T_1 \neq T_2$ due alberi di copertura minimi di $G$.
Dalla differenza simmetrica di $T_1.E \Delta T_2.E$ si ha un arco $(u,v)$ di peso minore che supponiamo appartenga solo a $T_1$ e non a $T_2$.
Quindi sia $\pi$ un cammino in $T_2$ che connette $u$ a $v$, ovviamente che non contenga $(u,v)$, ma ci sia un arco all'interno di $\pi$ ovvero $(u',v')$ non appartenente a $T_1$ (se no creerebbe un ciclo).
Si ha
$$
w(u,v) < w(u',v')
$$
Quindi supponiamo di creare un albero di copertura minimo chiamato $T_2'$ dove
$$
T_2'=(T_2 \setminus \{(u',v')\}) \cup \{(u,v)\}
$$
Si ha quindi che
$$
w(T_2')=w(T_2)-w(u',v')+w(u,v)<w(T_2) 
$$
Essendo $T_2$ già un albero di copertura minimo è impossibile trovare un albero di copertura minimo $T_2'$ con costo minore, qui c'è l'assurdo. $\quad \square$