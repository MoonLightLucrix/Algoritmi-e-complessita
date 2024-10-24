#ifndef BST_hpp
#define BST_hpp

#include<stdexcept>

template<class T>
class Nodo
{
    private:
        Nodo<T>*up;
        Nodo<T>*sx;
        Nodo<T>*dx;
        T info;
    public:

        /**
         * @brief Costruttore della classe Nodo.
         *
         * Inizializza un nuovo nodo con il valore specificato e i puntatori ai nodi padre, sinistro e destro.
         *
         * @param info Il valore da memorizzare nel nodo.
         * @param up Il puntatore al nodo padre.
         * @param sx Il puntatore al nodo figlio sinistro.
         * @param dx Il puntatore al nodo figlio destro.
         */
        Nodo<T>(T info, Nodo<T>*up=nullptr, Nodo<T>*sx=nullptr, Nodo<T>*dx=nullptr);

        /**
         * @brief Distruttore della classe Nodo.
         *
         * Questo metodo distrugge l'oggetto Nodo. Non esegue alcuna operazione specifica
         * poiché la gestione della memoria dei nodi è gestita dalla classe BST.
         */
        ~Nodo<T>();

        /**
         * @brief Imposta il nodo padre.
         *
         * Questo metodo imposta il nodo padre del nodo corrente.
         *
         * @param up Il puntatore al nodo padre.
         */
        void setUp(Nodo<T>*up);

        /**
         * @brief Restituisce il nodo padre.
         *
         * Questo metodo restituisce il puntatore al nodo padre del nodo corrente.
         *
         * @return Il puntatore al nodo padre.
         */
        Nodo<T>*getUp() const;

        /**
         * @brief Imposta il nodo figlio sinistro.
         *
         * Questo metodo imposta il nodo figlio sinistro del nodo corrente.
         *
         * @param sx Il puntatore al nodo figlio sinistro.
         */
        void setSx(Nodo<T>*sx);

        /**
         * @brief Restituisce il nodo figlio sinistro.
         *
         * Questo metodo restituisce il puntatore al nodo figlio sinistro del nodo corrente.
         *
         * @return Il puntatore al nodo figlio sinistro.
         */
        Nodo<T>*getSx() const;

        /**
         * @brief Imposta il nodo figlio destro.
         *
         * Questo metodo imposta il nodo figlio destro del nodo corrente.
         *
         * @param dx Il puntatore al nodo figlio destro.
         */
        void setDx(Nodo<T>*dx);

        /**
         * @brief Restituisce il nodo figlio destro.
         *
         * Questo metodo restituisce il puntatore al nodo figlio destro del nodo corrente.
         *
         * @return Il puntatore al nodo figlio destro.
         */
        Nodo<T>*getDx() const;

        /**
         * @brief Imposta il valore del nodo.
         *
         * Questo metodo imposta il valore memorizzato nel nodo corrente.
         *
         * @param info Il valore da memorizzare nel nodo.
         */
        void setInfo(T info);

        /**
         * @brief Restituisce il valore del nodo.
         *
         * Questo metodo restituisce il valore memorizzato nel nodo corrente.
         *
         * @return Il valore memorizzato nel nodo.
         */
        T getInfo() const;
};

template<class T>
class BST
{
    private:

        /**
         * @brief Sostituisce il sottoalbero radicato nel nodo `a` con il sottoalbero radicato nel nodo `b`.
         *
         * Questo metodo trapianta il sottoalbero radicato nel nodo `b` al posto del sottoalbero radicato nel nodo `a`.
         * Se `a` non ha un nodo padre, `b` diventa la nuova radice dell'albero. Altrimenti, `b` diventa il figlio
         * sinistro o destro del nodo padre di `a`, a seconda della posizione di `a`.
         * Inoltre, se `b` non è nullo, il suo nodo padre viene aggiornato per essere il nodo padre di `a`.
         *
         * @param a Il nodo da sostituire.
         * @param b Il nodo che sostituirà `a`.
         */
        void trapianta(Nodo<T>*a, Nodo<T>*b);

        /**
         * @brief Stampa gli elementi dell'albero in ordine inorder.
         *
         * Questo metodo visita ricorsivamente l'albero in ordine inorder (sinistro, radice, destro)
         * e stampa gli elementi. Gli elementi sono separati da una virgola e uno spazio, e l'output
         * è racchiuso tra parentesi quadre.
         *
         * @param a Il nodo corrente da cui iniziare la visita inorder.
         * @param i Un contatore che tiene traccia della posizione corrente durante la stampa.
         *          Viene utilizzato per formattare correttamente l'output.
         */
        void inorder(Nodo<T>*a, size_t&i) const;

        /**
         * @brief Stampa gli elementi dell'albero in ordine postorder.
         *
         * Questo metodo visita ricorsivamente l'albero in ordine postorder (sinistro, destro, radice)
         * e stampa gli elementi. Gli elementi sono separati da una virgola e uno spazio, e l'output
         * è racchiuso tra parentesi quadre.
         *
         * @param a Il nodo corrente da cui iniziare la visita postorder.
         * @param i Un contatore che tiene traccia della posizione corrente durante la stampa.
         *          Viene utilizzato per formattare correttamente l'output.
         */
        void postorder(Nodo<T>*a, size_t&i) const;

        /**
         * @brief Stampa gli elementi dell'albero in ordine preorder.
         *
         * Questo metodo visita ricorsivamente l'albero in ordine preorder (radice, sinistro, destro)
         * e stampa gli elementi. Gli elementi sono separati da una virgola e uno spazio, e l'output
         * è racchiuso tra parentesi quadre.
         *
         * @param a Il nodo corrente da cui iniziare la visita preorder.
         * @param i Un contatore che tiene traccia della posizione corrente durante la stampa.
         *          Viene utilizzato per formattare correttamente l'output.
         */
        void preorder(Nodo<T>*a, size_t&i) const;

        /**
         * @brief Trova il nodo con il valore minimo nel sottoalbero radicato nel nodo dato.
         *
         * Questo metodo percorre il sottoalbero sinistro del nodo dato fino a trovare il nodo
         * più a sinistra, che contiene il valore minimo.
         *
         * @param a Il nodo radice del sottoalbero in cui cercare il valore minimo.
         * @return Il nodo che contiene il valore minimo nel sottoalbero, o nullptr se il nodo dato è nullo.
         */
        Nodo<T>*min(Nodo<T>*a) const;

        /**
         * @brief Trova il nodo con il valore massimo nel sottoalbero radicato nel nodo dato.
         *
         * Questo metodo percorre il sottoalbero destro del nodo dato fino a trovare il nodo
         * più a destra, che contiene il valore massimo.
         *
         * @param a Il nodo radice del sottoalbero in cui cercare il valore massimo.
         * @return Il nodo che contiene il valore massimo nel sottoalbero, o nullptr se il nodo dato è nullo.
         */
        Nodo<T>*max(Nodo<T>*a) const;

        /**
         * @brief Cancella ricorsivamente tutti i nodi dell'albero in ordine postorder.
         *
         * Questo metodo visita ricorsivamente l'albero in ordine postorder (sinistro, destro, radice)
         * e cancella tutti i nodi. Dopo aver cancellato un nodo, decrementa il contatore `s` che tiene
         * traccia del numero di nodi nell'albero.
         *
         * @param a Il nodo corrente da cui iniziare la cancellazione postorder.
         */
        void postorderClear(Nodo<T>*a);

    protected:
        size_t s;
        Nodo<T>*radice;
        Nodo<T>*lastInsert;

        /**
         * @brief Trova un nodo con un valore specifico nel BST.
         *
         * Questo metodo cerca un nodo con il valore specificato `x` nel Binary Search Tree (BST).
         * La ricerca inizia dalla radice e procede verso il basso, scegliendo il sottoalbero sinistro
         * o destro in base al confronto del valore `x` con il valore del nodo corrente.
         *
         * @param x Il valore da cercare nel BST.
         * @return Il puntatore al nodo che contiene il valore `x`, o nullptr se il valore non è trovato.
         */
        virtual Nodo<T>*find(T x);

        /**
         * @brief Esegue una rotazione a sinistra sul nodo specificato.
         *
         * Questo metodo esegue una rotazione a sinistra sul nodo dato `a` nel Binary Search Tree (BST).
         * La rotazione a sinistra sposta il nodo `a` verso il basso e il suo figlio destro verso l'alto,
         * mantenendo la proprietà di ordinamento del BST.
         *
         * @param a Il nodo su cui eseguire la rotazione a sinistra.
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*sxRotate(Nodo<T>*a);

        /**
         * @brief Esegue una rotazione a destra sul nodo specificato.
         *
         * Questo metodo esegue una rotazione a destra sul nodo dato `a` nel Binary Search Tree (BST).
         * La rotazione a destra sposta il nodo `a` verso il basso e il suo figlio sinistro verso l'alto,
         * mantenendo la proprietà di ordinamento del BST.
         *
         * @param a Il nodo su cui eseguire la rotazione a destra.
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*dxRotate(Nodo<T>*a);

    public:

        /**
         * @brief Costruttore di default per la classe BST.
         *
         * Inizializza un nuovo albero binario di ricerca (BST) vuoto.
         * Il puntatore alla radice, il puntatore all'ultimo nodo inserito e la dimensione dell'albero
         * vengono inizializzati a valori predefiniti.
         */
        BST<T>();

        /**
         * @brief Distruttore della classe BST.
         *
         * Questo metodo distrugge l'oggetto BST e libera tutta la memoria allocata
         * per i nodi dell'albero chiamando il metodo `clear()`.
         */
        ~BST<T>();

        /**
         * @brief Restituisce la dimensione dell'albero.
         *
         * Questo metodo restituisce il numero di nodi presenti nell'albero binario di ricerca (BST).
         *
         * @return La dimensione dell'albero, ovvero il numero di nodi.
         */
        size_t getSize() const;

        /**
         * @brief Verifica se l'albero è vuoto.
         *
         * Questo metodo controlla se l'albero binario di ricerca (BST) è vuoto, ovvero se il numero
         * di nodi nell'albero è zero.
         *
         * @return `true` se l'albero è vuoto, `false` altrimenti.
         */
        bool isEmpty() const;

        /**
         * @brief Inserisce un nuovo nodo con il valore specificato nell'albero.
         *
         * Questo metodo crea un nuovo nodo con il valore `x` e lo inserisce nel Binary Search Tree (BST).
         * Se l'albero è vuoto, il nuovo nodo diventa la radice. Altrimenti, il metodo trova la posizione
         * corretta per il nuovo nodo confrontando `x` con i valori dei nodi esistenti e lo inserisce come
         * figlio sinistro o destro del nodo appropriato.
         *
         * @param x Il valore da inserire nel BST.
         * @return Un puntatore all'oggetto BST modificato.
         */
        virtual BST<T>*insert(T x);

        /**
         * @brief Rimuove un nodo con il valore specificato dall'albero.
         *
         * Questo metodo cerca un nodo con il valore `x` nel Binary Search Tree (BST) e lo rimuove.
         * Se il nodo ha un solo figlio, il nodo viene sostituito con il suo figlio. Se il nodo ha due figli,
         * viene trovato il massimo nel sottoalbero sinistro per sostituire il nodo da rimuovere.
         *
         * @param x Il valore del nodo da rimuovere.
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*remove(T x);

        /**
         * @brief Verifica se un valore è presente nell'albero.
         *
         * Questo metodo controlla se un nodo con il valore specificato `x` è presente nel Binary Search Tree (BST).
         *
         * @param x Il valore da cercare nel BST.
         * @return `true` se il valore è presente nell'albero, `false` altrimenti.
         */
        bool contains(T x);

        //BST<T>*sxRotate(T x);

        //BST<T>*dxRotate(T x);

        /**
         * @brief Cancella tutti i nodi dell'albero.
         *
         * Questo metodo cancella ricorsivamente tutti i nodi dell'albero binario di ricerca (BST)
         * utilizzando una visita postorder e libera la memoria allocata per i nodi.
         *
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*clear();

        /**
         * @brief Stampa gli elementi dell'albero in ordine inorder.
         *
         * Questo metodo stampa tutti gli elementi dell'albero binario di ricerca (BST) in ordine inorder
         * (sinistro, radice, destro). Gli elementi sono stampati in una singola riga, separati da virgole
         * e racchiusi tra parentesi quadre.
         */
        void stampaInorder() const;

        /**
         * @brief Stampa gli elementi dell'albero in ordine postorder.
         *
         * Questo metodo stampa tutti gli elementi dell'albero binario di ricerca (BST) in ordine postorder
         * (sinistro, destro, radice). Gli elementi sono stampati in una singola riga, separati da virgole
         * e racchiusi tra parentesi quadre.
         */
        void stampaPostorder() const;

        /**
         * @brief Stampa gli elementi dell'albero in ordine preorder.
         *
         * Questo metodo stampa tutti gli elementi dell'albero binario di ricerca (BST) in ordine preorder
         * (radice, sinistro, destro). Gli elementi sono stampati in una singola riga, separati da virgole
         * e racchiusi tra parentesi quadre.
         */
        void stampaPreorder() const;

        template<class U>
        friend std::ostream& operator <<(std::ostream &str, BST<U>&t);
};

template<class T>
class SplayTree: public BST<T>
{
    private:
        using BST<T>::radice;
        using BST<T>::lastInsert;
        using BST<T>::s;
        using BST<T>::sxRotate;
        using BST<T>::dxRotate;

        /**
         * @brief Trova un nodo con un valore specifico nel Splay Tree.
         *
         * Questo metodo cerca un nodo con il valore specificato `x` nel Splay Tree.
         * La ricerca inizia dalla radice e procede verso il basso, scegliendo il sottoalbero sinistro
         * o destro in base al confronto del valore `x` con il valore del nodo corrente.
         * Dopo aver trovato il nodo, o il nodo più vicino se il valore non è presente, il metodo
         * esegue l'operazione di splay sul nodo trovato o sul nodo più vicino.
         *
         * @param x Il valore da cercare nel Splay Tree.
         * @return Il puntatore al nodo che contiene il valore `x`, o nullptr se il valore non è trovato.
         */
        Nodo<T>*find(T x) override;

        /**
         * @brief Verifica se il nodo è un figlio sinistro.
         *
         * Questo metodo controlla se il nodo `a` è il figlio sinistro del suo nodo padre.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è il figlio sinistro, `false` altrimenti.
         */
        bool zig(Nodo<T>*a) const;

        /**
         * @brief Verifica se il nodo è in una configurazione zig-zig.
         *
         * Questo metodo controlla se il nodo `a` e il suo nodo padre sono entrambi figli sinistri.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è in una configurazione zig-zig, `false` altrimenti.
         */
        bool zigzig(Nodo<T>*a) const;

        /**
         * @brief Verifica se il nodo è in una configurazione zig-zag.
         *
         * Questo metodo controlla se il nodo `a` è un figlio destro e il suo nodo padre è un figlio sinistro.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è in una configurazione zig-zag, `false` altrimenti.
         */
        bool zigzag(Nodo<T>*a) const;

        /**
         * @brief Verifica se il nodo è un figlio destro.
         *
         * Questo metodo controlla se il nodo `a` è il figlio destro del suo nodo padre.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è il figlio destro, `false` altrimenti.
         */
        bool zag(Nodo<T>*a) const;

        /**
         * @brief Verifica se il nodo è in una configurazione zag-zag.
         *
         * Questo metodo controlla se il nodo `a` e il suo nodo padre sono entrambi figli destri.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è in una configurazione zag-zag, `false` altrimenti.
         */
        bool zagzag(Nodo<T>*a) const;

        /**
         * @brief Verifica se il nodo è in una configurazione zag-zig.
         *
         * Questo metodo controlla se il nodo `a` è un figlio sinistro e il suo nodo padre è un figlio destro.
         *
         * @param a Il nodo da verificare.
         * @return `true` se il nodo `a` è in una configurazione zag-zig, `false` altrimenti.
         */
        bool zagzig(Nodo<T>*a) const;

        /**
         * @brief Esegue l'operazione di splay sul nodo specificato.
         *
         * Questo metodo esegue l'operazione di splay sul nodo dato `a` nel Splay Tree.
         * L'operazione di splay sposta il nodo `a` alla radice dell'albero attraverso una serie di rotazioni.
         * Le rotazioni eseguite dipendono dalla configurazione del nodo `a` e dei suoi antenati.
         *
         * @param a Il nodo su cui eseguire l'operazione di splay.
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*splay(Nodo<T>*a);

    public:
        using BST<T>::getSize;
        using BST<T>::isEmpty;
        using BST<T>::remove;
        using BST<T>::contains;
        using BST<T>::clear;
        using BST<T>::stampaInorder;
        using BST<T>::stampaPostorder;
        using BST<T>::stampaPreorder;

        /**
         * @brief Costruttore della classe SplayTree.
         *
         * Inizializza un nuovo albero SplayTree vuoto. Questo costruttore chiama il costruttore
         * della classe base BST per inizializzare l'albero.
         */
        SplayTree<T>();

        /**
         * @brief Distruttore della classe SplayTree.
         *
         * Questo metodo distrugge l'oggetto SplayTree e libera tutte le risorse allocate.
         * Non esegue alcuna operazione specifica poiché la gestione della memoria dei nodi
         * è gestita dalla classe base BST.
         */
        ~SplayTree<T>();

        /**
         * @brief Inserisce un nuovo nodo con il valore specificato nell'albero SplayTree.
         *
         * Questo metodo inserisce un nuovo nodo con il valore `x` nel SplayTree utilizzando il metodo
         * di inserimento della classe base BST. Dopo l'inserimento, esegue l'operazione di splay sul
         * nodo appena inserito per portarlo alla radice dell'albero.
         *
         * @param x Il valore da inserire nel SplayTree.
         * @return Un puntatore all'oggetto BST modificato.
         */
        BST<T>*insert(T x) override;
};

#include "BST.cpp"

#endif