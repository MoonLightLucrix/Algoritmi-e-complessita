#ifndef DISJOINTSETUNION
#define DISJOINTSETUNION

#include<iostream>
#include<cstdlib>
#include<cstring>
#include "Edge.hpp"

namespace UnionFind
{
    class DSU
    {
        private:
            int*p;
            int*rank;

            /**
             * @brief Unisce due set in base al rango.
             * 
             * Collega il set contenente l'elemento `v` al set contenente l'elemento `u` in base al rango.
             * Se i ranghi sono uguali, incrementa il rango del nuovo rappresentante.
             * 
             * @param u Il rappresentante di uno dei set da unire.
             * @param v Il rappresentante dell'altro set da unire.
             */
            void link(int u, int v);

        public:

            /**
             * @brief Costruttore della classe DSU.
             * 
             * Inizializza un nuovo oggetto DSU con `n` elementi, creando i set disgiunti iniziali.
             * 
             * @param n Il numero di elementi.
             */
            DSU(int n);

            /**
             * @brief Distruttore della classe DSU.
             * 
             * Libera la memoria allocata per gli array `p` e `rank`.
             */
            ~DSU();

            /**
             * @brief Crea un nuovo set contenente l'elemento specificato.
             * 
             * Inizializza il vertice `v` come un set disgiunto, impostando il suo genitore a se stesso e il suo rango a `0`.
             * 
             * @param v L'elemento da inizializzare come set disgiunto.
             */
            void makeSet(int v);

            /**
             * @brief Trova il rappresentante del set contenente l'elemento specificato.
             * 
             * Utilizza la compressione dei percorsi per ottimizzare le future operazioni di ricerca.
             * 
             * @param v L'elemento di cui trovare il set rappresentante.
             * @return Il rappresentante del set contenente l'elemento `v`.
             */
            int findSet(int v) const;

            /**
             * @brief Unisce i set contenenti due elementi specificati.
             * 
             * Trova i rappresentanti dei set contenenti gli elementi `u` e `v` e li unisce.
             * 
             * @param u Uno degli elementi di cui unire i set.
             * @param v L'altro elemento di cui unire i set.
             */
            void unite(int u, int v);
    };
};

#endif