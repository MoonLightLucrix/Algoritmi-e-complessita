#ifndef GRAFO
#define GRAFO

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
#include "Coda.hpp"
#include "DSU.hpp"

class Grafo
{
    private:
        int numeroVertici;
        int**adjMat;
        size_t edgeCount;
        UnionFind::Edge*edges;
        Coda<UnionFind::Edge*> mst;

        /**
         * @brief Ordina un array `UnionFind::Edge` utilizzando l'algoritmo QuickSort.
         * 
         * @param vett Puntatore all'array di `UnionFind::Edge` da ordinare.
         * @param sx Indice sinistro (iniziale) dell'intervallo da ordinare.
         * @param dx Indice destro (finale) dell'intervallo da ordinare.
         */
        void quicksort(UnionFind::Edge*vett, ssize_t sx, ssize_t dx);

        /**
         * @brief Calcola l'albero di copertura minimo (MST) del grafo utilizzando l'algoritmo di Kruskal.
         * 
         * Ordina gli archi del grafo per peso e utilizza una struttura dati Union-Find per unire i set disgiunti.
         * Aggiunge gli archi all'MST finché non si ottiene un albero di copertura minimo.
         */
        void kruskal();

        /**
         * @brief Funzione di utilità per l'attraversamento DFS (Depth-First Search).
         * 
         * Marca il vertice `u` come visitato e stampa il vertice. Quindi, ricorsivamente visita tutti i vertici adiacenti non ancora visitati.
         * 
         * @param u Il vertice corrente da visitare.
         * @param visitato Array di booleani che tiene traccia dei vertici visitati.
         */
        void dfsUtil(int a, bool*visitato) const;

        /**
         * @brief Stampa la matrice di adiacenza del grafo.
         * 
         * Stampa la matrice di adiacenza del grafo con i vertici etichettati in ordine alfabetico.
         * Le righe e le colonne della matrice sono separate da tabulazioni.
         */
        void aStampa() const;

    public:

        /**
         * @brief Costruttore della classe Grafo.
         * 
         * Inizializza un nuovo oggetto Grafo con il numero specificato di vertici. Alloca la memoria per la matrice di adiacenza e l'array degli archi, e inizializza la matrice di adiacenza a `0`.
         * 
         * @param numeroVertici Il numero di vertici nel grafo.
         */
        Grafo(size_t numeroVertici=0);

        /**
         * @brief Distruttore della classe Grafo.
         * 
         * Libera la memoria allocata per la matrice di adiacenza e l'array degli archi.
         */
        ~Grafo();

        /**
         * @brief Aggiunge un arco al grafo.
         * 
         * Aggiunge un arco tra i vertici `u` e `v` con il peso specificato. Aggiorna la matrice di adiacenza e l'array degli archi, e ricalcola l'albero di copertura minimo utilizzando l'algoritmo di Kruskal.
         * 
         * @param u Il vertice di origine.
         * @param v Il vertice di destinazione.
         * @param weight Il peso dell'arco (valore predefinito `1`).
         * @return Puntatore al grafo stesso.
         */
        Grafo*addEdge(UnionFind::V u, UnionFind::V v, int weight=1);

        /**
         * @brief Attraversamento BFS (Breadth-First Search) del grafo a partire da un vertice specificato.
         * 
         * Marca il vertice `u` come visitato e stampa il vertice. Quindi, visita tutti i vertici adiacenti non ancora visitati utilizzando una coda.
         * 
         * @param u Il vertice di partenza per l'attraversamento BFS.
         */
        void bfs(UnionFind::V u) const;

        /**
         * @brief Attraversamento DFS (Depth-First Search) del grafo a partire da un vertice specificato.
         * 
         * Marca il vertice `u` come visitato e stampa il vertice. Quindi, ricorsivamente visita tutti i vertici adiacenti non ancora visitati.
         * 
         * @param u Il vertice di partenza per l'attraversamento DFS.
         */
        void dfs(UnionFind::V u) const;

        /**
         * @brief Stampa la matrice di adiacenza del grafo seguita da una nuova riga.
         */
        void stampa() const;

        /**
         * @brief Stampa la segnatura dell'albero di copertura minimo (MST).
         * 
         * Stampa gli archi dell'MST in blu e gli archi non inclusi nell'MST in rosso.
         */
        void stampaMST() const;

        friend std::ostream& operator <<(std::ostream &str, const Grafo&g);
};

#endif