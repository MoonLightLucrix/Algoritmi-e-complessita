#ifndef EDGE
#define EDGE

#include<iostream>
#include<cstdlib>
#include<cstring>

namespace UnionFind
{
    using V=char;
    class Edge
    {
        private:
            V src;
            V dst;
            int weight;
        public:

            /**
             * @brief Costruttore della classe Edge.
             * 
             * Inizializza un nuovo oggetto Edge con i vertici di origine e destinazione ed il peso specificati.
             * 
             * @param src Il vertice di origine.
             * @param dst Il vertice di destinazione.
             * @param weight Il peso dell'arco.
             */
            Edge(V src='\0', V dst='\0', int weight=1);

            ~Edge()=default;

            Edge(const Edge&other)=default;

            Edge& operator=(const Edge&other)=default;

            Edge(Edge&&other) noexcept=default;

            Edge& operator=(Edge&&other) noexcept=default;

            /**
             * @brief Imposta il vertice di origine dell'arco.
             * 
             * @param src Il nuovo vertice di origine.
             */
            void setSrc(V src);

            /**
             * @brief Restituisce il vertice di origine dell'arco.
             * 
             * @return Il vertice di origine.
             */
            V getSrc() const;

            /**
             * @brief Imposta il vertice di destinazione dell'arco.
             * 
             * @param dst Il nuovo vertice di destinazione.
             */
            void setDst(V dst);

            /**
             * @brief Restituisce il vertice di destinazione dell'arco.
             * 
             * @return Il vertice di destinazione.
             */
            V getDst() const;

            /**
             * @brief Imposta il peso dell'arco.
             * 
             * @param weight Il nuovo peso dell'arco.
             */
            void setWeight(int weight);

            /**
             * @brief Restituisce il peso dell'arco.
             * 
             * @return Il peso dell'arco.
             */
            int getWeight() const;

            /**
             * @brief Restituisce una rappresentazione testuale dell'arco.
             * 
             * @return Una stringa contenente il vertice di origine, il vertice di destinazione e il peso dell'arco.
             */
            std::string leggiEdge() const;

            /**
             * @brief Stampa una rappresentazione testuale dell'arco.
             * 
             * Stampa su standard output la rappresentazione testuale dell'arco.
             */
            void stampa() const;

            friend bool operator <(const Edge&a, const Edge&b);

            friend bool operator >(const Edge&a, const Edge&b);

            friend bool operator <=(const Edge&a, const Edge&b);

            friend bool operator >=(const Edge&a, const Edge&b);

            friend bool operator ==(const Edge&a, const Edge&b);

            friend bool operator !=(const Edge&a, const Edge&b);
            
            friend std::ostream& operator <<(std::ostream &str, const Edge&e);
    };

};

#endif