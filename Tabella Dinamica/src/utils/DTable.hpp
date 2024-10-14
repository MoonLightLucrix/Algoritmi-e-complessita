#ifndef DTABLE
#define DTABLE

#include<algorithm>

template<class T>
class DTable
{
    private:
        T**table;
        size_t N;
        ssize_t s;
        const bool increase=true;
        const bool decrease=false;

        /**
         * @brief Ridimensiona la tabella dinamica.
         *
         * Questo metodo ridimensiona la tabella dinamica raddoppiando o dimezzando
         * la sua dimensione attuale in base al valore del parametro `op`.
         *
         * @param op Se `true`, la dimensione della tabella viene raddoppiata.
         *           Se `false`, la dimensione della tabella viene dimezzata.
         *
         * @note Se la dimensione attuale (`N`) è zero, viene impostata a 1.
         * @note La funzione dealloca la memoria della vecchia tabella e alloca
         *       una nuova tabella con la nuova dimensione.
         */
        void resize(bool op);

        /**
         * @brief Stampa gli elementi della tabella dinamica.
         *
         * Questo metodo stampa tutti gli elementi della tabella dinamica separati da una virgola.
         * L'ultimo elemento non è seguito da una virgola.
         *
         * @note Assicurati che gli elementi della tabella siano validi e dereferenziabili.
         */
        void aStampa();

    public:

        /**
         * @brief Costruttore per la classe DTable.
         *
         * Inizializza una nuova istanza della classe DTable con dimensione e limite iniziali pari a zero.
         * Alloca una tabella vuota.
         *
         * @note La tabella inizialmente allocata ha una dimensione di zero.
         */
        DTable();

        /**
         * @brief Distruttore della classe DTable.
         *
         * Questo metodo dealloca la memoria utilizzata dalla tabella dinamica.
         * Chiama il metodo `clear()` per liberare le risorse aggiuntive e poi dealloca la tabella.
         */
        ~DTable();

        /**
         * @brief Restituisce la dimensione attuale della tabella dinamica.
         *
         * Questo metodo restituisce il numero di elementi attualmente presenti nella tabella dinamica.
         *
         * @return La dimensione attuale della tabella dinamica.
         */
        ssize_t getSize();

        /**
         * @brief Restituisce il limite attuale della tabella dinamica.
         *
         * Questo metodo restituisce la capacità massima della tabella dinamica, ovvero il numero massimo di elementi che può contenere prima di dover essere ridimensionata.
         *
         * @return La capacità massima della tabella dinamica.
         */
        size_t getLimit();

        /**
         * @brief Restituisce l'indice di un elemento nella tabella dinamica.
         *
         * Questo metodo cerca l'elemento specificato nella tabella dinamica e restituisce il suo indice.
         * Se l'elemento non viene trovato, restituisce -1.
         *
         * @param x L'elemento da cercare nella tabella dinamica.
         * @return L'indice dell'elemento se trovato, altrimenti -1.
         */
        ssize_t getIndex(T x);

        /**
         * @brief Verifica se un elemento è presente nella tabella dinamica.
         *
         * Questo metodo controlla se l'elemento specificato è presente nella tabella dinamica.
         *
         * @param x L'elemento da cercare nella tabella dinamica.
         * @return `true` se l'elemento è presente, `false` altrimenti.
         */
        bool contains(T x);

        /**
         * @brief Inserisce un nuovo elemento nella tabella dinamica.
         *
         * Questo metodo inserisce un nuovo elemento nella tabella dinamica. Se la tabella è piena,
         * viene ridimensionata per fare spazio al nuovo elemento.
         *
         * @param x L'elemento da inserire nella tabella dinamica.
         * @return Un puntatore all'istanza corrente della tabella dinamica.
         *
         * @note Se la tabella è piena (`s >= N`), viene chiamato il metodo `resize` per aumentare la capacità.
         */
        DTable<T>*insert(T x);

        /**
         * @brief Rimuove l'ultimo elemento dalla tabella dinamica.
         *
         * Questo metodo rimuove l'ultimo elemento dalla tabella dinamica, deallocando la memoria associata.
         * Se la dimensione della tabella scende al di sotto della metà della capacità, la tabella viene ridimensionata.
         *
         * @return Un puntatore all'istanza corrente della tabella dinamica.
         *
         * @note Se la tabella è vuota (`s == 0`), il metodo non fa nulla.
         */
        DTable<T>*dequeue();

        /**
         * @brief Rimuove un elemento specificato dalla tabella dinamica.
         *
         * Questo metodo cerca l'elemento specificato nella tabella dinamica e lo rimuove se presente.
         * Se l'elemento viene trovato, viene scambiato con l'ultimo elemento e poi rimosso utilizzando il metodo `dequeue`.
         *
         * @param x L'elemento da rimuovere dalla tabella dinamica.
         * @return Un puntatore all'istanza corrente della tabella dinamica.
         *
         * @note Se l'elemento non viene trovato, il metodo non fa nulla.
         */
        DTable<T>*remove(T x);

        /**
         * @brief Rimuove tutti gli elementi dalla tabella dinamica.
         *
         * Questo metodo rimuove tutti gli elementi dalla tabella dinamica, deallocando la memoria associata a ciascun elemento.
         * Utilizza il metodo `dequeue` per rimuovere gli elementi uno alla volta fino a quando la tabella è vuota.
         *
         * @return Un puntatore all'istanza corrente della tabella dinamica.
         */
        DTable<T>*clear();

        /**
         * @brief Stampa gli elementi della tabella dinamica seguiti da una nuova riga.
         *
         * Questo metodo stampa tutti gli elementi della tabella dinamica utilizzando il metodo `aStampa`
         * e aggiunge una nuova riga alla fine.
         */
        void stampa();
        
        template<class U>
        friend std::ostream& operator <<(std::ostream &str, DTable<U>&a);
};

#include "DTable.cpp"

#endif