# 6 Move-to-Front

## Indice
- [6.1 Introduzione](#61-introduzione)
- [6.2 Analisi del costo](#62-analisi-del-costo)
- [6.3 Analisi competitiva](#63-analisi-competitiva)
  - [6.3.1 Teorema della 4-competitività](#631-teorema-della-4-competitività)
  - [6.3.2 Definizione di inversione](#632-definizione-di-inversione)
  - [6.3.3 Dimostrazione della 4-competitività mediante analisi ammortizzata](#633-dimostrazione-della-4-competitività-mediante-analisi-ammortizzata)

## 6.1 Introduzione
Considerando una lista di $n$ elementi:

<p align="center" id="6-1">
  <img src="Image/Lista.png" alt="Lista" width="80%" height="80%">
  <br>
  <em><font size="1">Figura 6.1: Descrizione della lista</font></em>
</p>

L'obiettivo è quello di portare in **testa** alla lista l'ultimo elemento cercato. Questa scelta si basa sull'assunzione che, dopo aver effettuato l'accesso, l'elemento potrebbe essere richiesto nuovamente nell'immediato futuro.

## 6.2 Analisi del costo
Si consideri il caso in cui l'ultimo elemento ricercato sia _f_, il quale si trova nella posizione $k$ all'interno della lista.
Per localizzare l'elemento _f_, è necessario scorrere sequenzialmente la lista fino a raggiungere la posizione $k$, il che comporta un costo pari a $k$.

L'euristica **Move-to-Front** prevede che, una volta individuato l'elemento _f_, esso venga spostato progressivamente verso la testa della lista mediante una serie di scambi tra nodi adiacenti.
In particolare, saranno necessari $k-1$ scambi per portare l'elemento _f_ alla posizione iniziale.
Pertanto, il costo associato agli scambi dopo la ricerca risulta essere pari a $k-1$.

Questa strategia ha lo scopo di migliorare l'efficienza negli accessi successivi, privilegiando gli elementi più frequentemente utilizzati, che vengono collocati in posizioni facilmente accessibili.
Il diagramma seguente ([Figura 6.2](#6-2)) illustra il processo di spostamento dell'elemento _f_ verso la testa della lista.

<p align="center" id="6-2"> 
  <img src="Image/Lista MF.png" alt="Lista MF" width="80%" height="80%"><br>
  <em>
    <font size="1">Figura 6.2: Procedura per portare l'elemento f in testa alla lista.</font>
  </em>
</p>

In sintesi, il costo totale per la ricerca e il successivo spostamento di _f_ alla testa della lista è dato da:

$$
c_i=k + (k-1) = 2k - 1
$$

Tuttavia, tale costo iniziale potrebbe essere compensato dal risparmio di tempo ottenuto in ricerche future, specialmente nel caso in cui l'elemento _f_ venga richiesto frequentemente.

## 6.3 Analisi competitiva

### 6.3.1 Teorema della 4-competitività
Si consideri l'insieme $A = \{a_1, a_2, a_3, \dots, a_n\}$, che rappresenta una sequenza di accessi a una lista generica $L$.
Si definiscano $C_i^{MF}$ e $C_i^{AL}$ come le configurazioni della lista $L$ dopo l'accesso $a_i$, ottenute rispettivamente con l'algoritmo _Move-to-Front_ e con un algoritmo generico _AL_ (anche ottimale).
Inoltre, siano $c_i^{MF}$ e $c_i^{AL}$ i costi reali associati al $i$-esimo accesso alla lista per _Move-to-Front_ e per l'algoritmo generico _AL_, rispettivamente.

Si afferma che _Move-to-Front_ è **4-competitivo** rispetto a un algoritmo _AL_ generico se risulta soddisfatta la seguente relazione:

$$
\sum_{i=1}^{n}c_i^{MF} \leq 4 \cdot \sum_{i=1}^{n}c_i^{AL}
$$

In altre parole, il costo totale degli accessi effettuati con l'algoritmo Move-to-Front non eccede 4 volte il costo totale degli accessi effettuati con qualsiasi altro algoritmo, anche ottimale.

### 6.3.2 Definizione di inversione
Siano $L_1$ e $L_2$ due liste che contengono gli stessi elementi, ma disposti in ordine diverso

<p align="center" id="6-3">
  <img src="Image/Inversioni.png" alt="Inversioni" width="60%" height="60%">
  <br>
  <em><font size="1">Figura 6.3: Due liste con configurazioni diverse.</font></em>
</p>

si considera una coppia $G =\{g_i,g_j\}$ con $g_i, g_j \in L_1 \cap L_2$ dove $\forall i,j \in \mathbb{N} \mid 1 \leq i,j \leq n \land i≠j$.

$G$ è un'**inversione** tra $L_1$ e $L_2$ se:
- in $L_1$, $g_i$ si trova prima di $g_j$ (cioè $i < j$);
- in $L_2$, $g_j$ si trova prima di $g_i$ (cioè $i > j$).

### 6.3.3 Dimostrazione della 4-competitività mediante analisi ammortizzata

Per dimostrare l'efficacia dell'euristica Move-to-Front, si utilizzerà l'**analisi ammortizzata** applicando il **metodo del potenziale**.
Questo approccio consente di mostrare che l'algoritmo Move-to-Front ha una complessità al più 4 volte superiore rispetto a qualsiasi altro algoritmo, anche ottimale.

Si definisca **accesso** ad un elemento della lista come:

$$
accesso=ricerca+scambi
$$

ed il costo reale  $c_i^{MF}$ il costo dell'$i$-esimo accesso da parte dell'algoritmo Move-to-Front come:

$$
c_i^{MF}=k+(k-1)=2k-1
$$

sia, inoltre, definita la funzione potenziale $\Phi : \mathbb{N} \rightarrow \mathbb{N}$ come:

$$
\Phi(i)=
\begin{cases}
  0 & \text{se } i = 0\\
  2 \cdot (\text{numero di inversioni tra } C_i^{MF} \text{ e } C_i^{AL}) & \text{altrimenti}
\end{cases}
$$

ed il costo ammortizzato $\hat{c}_i^{MF}$ come:

$$
\hat{c}_i^{MF}=c_i^{MF}+\Phi(i)-\Phi(i-1)
$$

data una lista $L$ dove vengono eseguiti contemporaneamente sia _Move-to-Front_ e _AL_

<p align="center" id="6-4">
  <img src="Image/Schema delle liste.png" alt="Schema delle liste" width="80%" height="80%">
  <br>
  <em><font size="1">Figura 6.4: Configurazioni con entrambi gli algoritmi.</font></em>
</p>

sia definita tramite $s=c_i^{AL}$ il costo reale dell'$i$-esimo accesso da parte del generico algoritmo _AL_ e $a$, $b$ e $b'$ le inversioni tra $C_{i-1}^{MF}$ e $C_{i-1}^{AL}$, tra $C_i^{MF}$ e $C_i^{AL}$ e tra $C_i^{MF}$ e $C_{i-1}^{AL}$ rispettivamente.

Si definisce il costo ammortizzato $\hat{c}_i^{MF}$ come:

$$
\hat{c}_i^{MF}=2k-1+2 \cdot (b-a)
$$

sicuramente

$$
b \leq b'+s-j
$$

dove $s-j$ è l'accesso senza ricerca.

Tra $C_{i-1}^{MF}$ e $C_i^{MF}$ ci sono $k-1$ inversioni, ovvero, quelle che servono per portare $a_i$ in testa.
Rispetto a $C_{i-1}^{AL}$ ognuna di queste inversioni o è **creata** o è **distrutta**, quindi:

$$
\text{numero di inversioni create} + \text{numero di inversioni distrutte}=k-1
$$

le **inversioni create** sono le inversioni che avvengono da $C_{i-1}^{MF}$ a $C_i^{MF}$ e che non sono presenti in $C_{i-1}^{AL}$, mentre le **inversioni distrutte** sono le inversioni che avvengono da $C_{i-1}^{MF}$ a $C_i^{MF}$ e che sono presenti anche in $C_{i-1}^{AL}$.

Sapendo che le inversioni sono sicuramente create quando $a_i$ entra nella regione $A$ in $C_{i-1}^{MF}$ e $C_i^{MF}$ e nella regione $B$ in $C_{i-1}^{AL}$ allora il numero di inversioni create sarà sicuramente:

$$
\text{numero di inversioni create}=A \cap B=\min(A,B)=\min(k-1,j-1)
$$

le inversioni distrutte possono essere banalmente ottenute come:

$$
\text{numero di inversione distrutte}=k-1- \text{numero di inversioni create}
$$

ovvero:

$$
\text{numero di inversioni distrutte}=k-1- \min(k-1,j-1)
$$

quindi togliendo alle inversioni $a$ il numero di inversioni distrutte ed aggiungendo il numero delle inversioni create si ottengono le inversioni $b'$, ovvero:

$$
b'=a+ \text{numero di inversioni create} - \text{numero di inversioni distrutte}
$$

ovvero:

$$
b'=a+ \min(k-1,j-1)-((k-1)- \min(k-1,j-1))
$$

siccome sarà sempre verificata la condizione:

$$
\min(k-1,j-1) \leq j-1
$$

si può maggiorare:

$$
b' \leq a+j-1-(k-1-(j-1))=a+2j-k-1
$$

tornando al costo ammortizzato $\hat{c}_i^{MF}$ si ottiene:

$$
\hat{c}_i^{MF}=2k-1+2 \cdot (b-a) \leq 2k-1+2 \cdot (b'+s-j-a)
$$

sostituendo si ottiene:

$$
\hat{c}_i^{MF} \leq 2k-1+2 \cdot ((a+2j-k-1)+s-j-a)
$$

semplificando:

$$
\hat{c}_i^{MF} \leq 2k-1+2 \cdot (j-k-1+s)
$$

sapendo che $j \leq s$ si può ancora maggiorare:

$$
\hat{c}_i^{MF} \leq 2k-1+2 \cdot (2s-k-1)
$$

$$
\hat{c}_i^{MF} \leq 2k-1+4s-2k-2
$$

$$
\hat{c}_i^{MF} \leq 4s-3 \leq 4s
$$

considerando che $s=c_i^{AL}$ possiamo riscrivere la disugualianza come:

$$
\hat{c}_i^{MF} \leq 4 \cdot c_i^{AL}
$$

considerando pure tutti gli accessi contenuti nell'insieme $A$, si ottiene:

$$
\sum_{i=1}^n \hat{c}_i^{MF} \leq 4 \cdot \sum_{i=1}^n c_i^{AL}
$$

sapendo che $\Phi(0)$ equivale alla lista $L$ con $0$ inversioni si ha che:

$$
\Phi(i) \geq \Phi(i-1)
$$

e sapendo che:

$$
\sum_{i=1}^{n} c_i \leq \sum_{i=1}^{n} \hat{c}_i \leftrightarrow \Phi(i) \geq \Phi(i-1)
$$

allora:

$$
\sum_{i=1}^{n} c_i^{MF} \leq \sum_{i=1}^n \hat{c}_i^{MF} \leq 4 \cdot \sum_{i=1}^n c_i^{AL}
$$

quindi:

$$
\sum_{i=1}^{n} c_i^{MF} \leq 4 \cdot \sum_{i=1}^n c_i^{AL} \quad \square
$$