#ifndef CODA
#define CODA

#include<functional>

template<class T>
class Nodo
{
    private:
        Nodo<T>*succ;
        T info;
    public:

        /**
         * @brief Costruttore della classe Nodo.
         * 
         * @param info Chiave contenuta nel nodo.
         * @param succ Puntatore al nodo successivo nella coda.
         */
        Nodo<T>(T info, Nodo<T>*succ=nullptr);

        ~Nodo<T>()=default;

        /**
         * @brief Imposta il nodo successivo.
         * 
         * @param succ Puntatore al nodo successivo.
         */
        void setSucc(Nodo<T>*succ);

        /**
         * @brief Restituisce il nodo successivo.
         * 
         * @return Puntatore al nodo successivo.
         */
        Nodo<T>*getSucc() const;

        /**
         * @brief Imposta la chiave contenuta nel nodo.
         * 
         * @param info Chiave da impostare.
         */
        void setInfo(T info);

        /**
         * @brief Restituisce l'informazione contenuta nel nodo.
         * 
         * @return L'informazione contenuta nel nodo.
         */
        T getInfo() const;
};

template<class T>
class Iterator
{
    private:
        Nodo<T>*a;
    public:

        /**
         * @brief Costruttore della classe Iterator.
         * 
         * @param a Puntatore al nodo iniziale dell'iteratore.
         */
        Iterator<T>(Nodo<T>*a=nullptr);

        ~Iterator<T>()=default;

        /**
         * @brief Incrementa l'iteratore al nodo successivo.
         * 
         * @return Riferimento all'iteratore incrementato.
         */
        Iterator<T>& operator++();

        /**
         * @brief Restituisce la chiave contenuta nel nodo corrente dell'iteratore.
         * 
         * @return La chiave contenuta nel nodo corrente.
         */
        T operator*();

        /**
         * @brief Confronta due iteratori per la disuguaglianza.
         * 
         * @param b L'iteratore con cui confrontare.
         * @return `true` se gli iteratori sono diversi, `false` altrimenti.
         */
        bool operator!=(const Iterator&b);
};

template<class T>
class Coda
{
    private:
        Nodo<T>*testa;
        Nodo<T>*coda;
        size_t s;

        /**
         * @brief Trova un nodo con l'informazione specificata.
         * 
         * @param x L'informazione da cercare.
         * @return Puntatore al nodo che contiene la chiave, o `nullptr` se non trovato.
         */
        Nodo<T>*find(T x) const;

        /**
         * @brief Stampa il contenuto della coda.
         * 
         * Stampa gli elementi della coda in formato di lista, separati da virgole.
         */
        void aStampa() const;

    public:

        /**
         * @brief Costruttore della classe Coda.
         * 
         * Inizializza una coda vuota.
         */
        Coda<T>();

        /**
         * @brief Distruttore della classe Coda.
         * 
         * Libera la memoria occupata dai nodi della coda.
         */
        ~Coda<T>();

        /**
         * @brief Restituisce un iteratore all'inizio della coda.
         * 
         * @return Un iteratore al primo nodo della coda.
         */
        Iterator<T> begin() const;

        /**
         * @brief Restituisce un iteratore alla fine della coda.
         * 
         * @return Un iteratore che rappresenta la fine della coda.
         */
        Iterator<T> end() const;

        /**
         * @brief Restituisce la dimensione della coda.
         * 
         * @return Il numero di elementi presenti nella coda.
         */
        size_t getSize() const;

        /**
         * @brief Verifica se la coda è vuota.
         * 
         * @return `true` se la coda è vuota, `false` altrimenti.
         */
        bool isEmpty() const;

        /**
         * @brief Rimuove tutti gli elementi dalla coda.
         * 
         * Libera la memoria occupata dai nodi della coda e reimposta la coda come vuota.
         * 
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*clear();

        /**
         * @brief Aggiunge un elemento alla coda.
         * 
         * @param x L'elemento da aggiungere alla coda.
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*enqueue(T x);

        /**
         * @brief Restituisce il primo elemento della coda.
         * 
         * @return Il primo elemento della coda.
         * @throws `std::runtime_error` se la coda è vuota.
         */
        T getFirst();

        /**
         * @brief Restituisce l'ultimo elemento della coda.
         * 
         * @return L'ultimo elemento della coda.
         * @throws `std::runtime_error` se la coda è vuota.
         */
        T getLast();

        /**
         * @brief Rimuove l'ultimo elemento dalla coda.
         * 
         * Se la coda è vuota, non fa nulla. Se la coda contiene un solo elemento, lo rimuove e imposta testa e coda a `nullptr`.
         * Altrimenti, rimuove l'ultimo elemento e aggiorna il puntatore della coda.
         * 
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*dequeue();

        /**
         * @brief Rimuove un elemento specifico dalla coda.
         * 
         * Cerca il nodo contenente la chiave specificata e lo rimuove dalla coda.
         * 
         * @param x La chiave dell'elemento da rimuovere.
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*remove(T x);

        /**
         * @brief Applica una funzione a ciascun elemento della coda.
         * 
         * La funzione specificata viene applicata a ogni elemento della coda, modificando il contenuto di ciascun nodo.
         * 
         * @param lambda La funzione da applicare a ciascun elemento.
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*map(std::function<T(T)> lambda);

        /**
         * @brief Filtra gli elementi della coda in base a un predicato.
         * 
         * Rimuove dalla coda tutti gli elementi che soddisfano il predicato specificato.
         * 
         * @param predicate La funzione predicato da applicare a ciascun elemento.
         * @return Puntatore alla coda stessa.
         */
        Coda<T>*filter(std::function<bool(T)> predicate);

        /**
         * @brief Riduce la coda a un singolo valore applicando una funzione di riduzione.
         * 
         * La funzione di riduzione viene applicata a ciascun elemento della coda e a un accumulatore, 
         * che viene aggiornato ad ogni passo.
         * 
         * @param lambda La funzione di riduzione da applicare a ciascun elemento e all'accumulatore.
         * @return Il valore accumulato risultante dalla riduzione.
         */
        template<class U>
        U reduce(std::function<U(T,U)> lambda);

        /**
         * @brief Verifica se la coda contiene un elemento specifico.
         * 
         * @param x L'elemento da cercare nella coda.
         * @return `true` se l'elemento è presente nella coda, `false` altrimenti.
         */
        bool contains(T x) const;

        /**
         * @brief Stampa il contenuto della coda seguito da una nuova riga.
         * 
         * Stampa gli elementi della coda e aggiunge una nuova riga alla fine.
         */
        void stampa() const;

        template<class U>
        friend std::ostream& operator <<(std::ostream &str, const Coda<U>&a);
};

#include "Coda.cpp"

#endif
