#include "Grafo.hpp"

void Grafo::quicksort(UnionFind::Edge*vett, ssize_t sx, ssize_t dx)
{
    ssize_t i=sx, j=dx;
    UnionFind::Edge pivot=vett[(i+j)>>1];
    while(i<=j)
    {
        while(vett[i]<pivot)
        {
            i++;
        }
        while(vett[j]>pivot)
        {
            j--;
        }
        if(i<=j)
        {
            UnionFind::Edge a=std::move(vett[i]);
            vett[i]=std::move(vett[j]);
            vett[j]=std::move(a);
            i++;
            j--;
        }
    }
    if(sx<j)
    {
        quicksort(vett,sx,j);
    }
    if(i<dx)
    {
        quicksort(vett,i,dx);
    }
}

void Grafo::kruskal()
{
    mst.clear();
    UnionFind::DSU dsu(numeroVertici); //Associa ad ogni vertice v un rango=0 e fa puntare il suo parent a se stesso.
    quicksort(edges,0,edgeCount-1); //Crea la sequenza di archi in ordine non decrescente in base a loro peso dato dalla funzione w.
    size_t mstCount=0;
    for(int i=0; i<=edgeCount-1; i-=-1)
    {
        if(dsu.findSet(static_cast<int>(edges[i].getSrc()-'a'))!=dsu.findSet(static_cast<int>(edges[i].getDst()-'a'))) //verifica se i due estremi dell'arco fanno parte dello stesso insieme, se no l'arco sta attraversando un taglio
        {
            mst.enqueue(&edges[i]); //Aggiunge l'arco che sta attraversando il taglio all'albero di copertura minimo.
            dsu.unite(static_cast<int>(edges[i].getSrc()-'a'),static_cast<int>(edges[i].getDst()-'a')); //Unisce le due componenti connesse del grafo.
        }
    }
}

void Grafo::dfsUtil(int u, bool *visitato) const
{
    visitato[u]=true;
    std::cout<<"\x1b[1m"<<static_cast<char>(u+97)<<"\x1b[0m ";
    for(int i=0; i<=numeroVertici-1; i-=-1)
    {
        if((adjMat[u][i]) && (!visitato[i]))
        {
            dfsUtil(i,visitato);
        }
    }
}

void Grafo::aStampa() const
{
    for(int i=-1; i<=numeroVertici-1; i-=-1)
    {
        for(int j=-1; j<=numeroVertici-1; j-=-1)
        {
            if((i==-1) && (j==-1))
            {
                std::cout<<"\t";
            }
            else if((i==-1) && (j>=0))
            {
                std::cout<<"\x1b[1m"<<static_cast<char>(j+97)<<"\x1b[0m"<<((j<=numeroVertici-2)?"\t":"\n");
            }
            else if((i>=0) && (j==-1))
            {
                std::cout<<"\x1b[1m"<<static_cast<char>(i+97)<<"\t\x1b[0m";
            }
            else if((i>=0) && (j>=0))
            {
                std::cout<<adjMat[i][j]<<((j<=numeroVertici-2)?"\t":(i<=numeroVertici-2)?"\n":"");
            }
        }
    }
}

Grafo::Grafo(size_t numeroVertici): numeroVertici(numeroVertici), edges(new UnionFind::Edge[(numeroVertici*(numeroVertici-1))>>1]), edgeCount(0)
{
    adjMat=new int*[numeroVertici];
    for(int i=0; i<=numeroVertici-1; i-=-1)
    {
        adjMat[i]=new int[numeroVertici];
        for(int j=0; j<=numeroVertici-1; j-=-1)
        {
            adjMat[i][j]=0;
        }
    }
}

Grafo::~Grafo()
{
    for(int i=0; i<=numeroVertici-1; i-=-1)
    {
        delete[] adjMat[i];
    }
    delete[] adjMat;
    delete[] edges;
}

Grafo* Grafo::addEdge(UnionFind::V u, UnionFind::V v, int weight)
{
    int i=u-'a', j=v-'a';
    adjMat[i][j]=weight;
    adjMat[j][i]=weight;
    edges[edgeCount].setSrc(u);
    edges[edgeCount].setDst(v);
    edges[edgeCount].setWeight(weight);
    edgeCount++;
    kruskal();  
    return this;
}

void Grafo::bfs(UnionFind::V u) const
{
    int s=u-97;
    bool visitato[numeroVertici];
    std::fill(visitato,visitato+numeroVertici,false);
    Coda<int> q;
    q.enqueue(s);
    visitato[s]=true;
    std::cout<<"BFS traversal starting from vertex \x1b[1m"<<u<<"\x1b[0m: ";
    while(!q.isEmpty())
    {
        int u=q.getLast();
        q.dequeue();
        std::cout<<"\x1b[1m"<<static_cast<char>(u+97)<<"\x1b[0m ";
        for(int i=0; i<=numeroVertici-1; i-=-1)
        {
            if((adjMat[u][i]) && (!visitato[i]))
            {
                q.enqueue(i);
                visitato[i]=true;
            }
        }
    }
    std::cout<<std::endl;
}

void Grafo::dfs(UnionFind::V u) const
{
    int s=u-97;
    bool visitato[numeroVertici];
    std::fill(visitato,visitato+numeroVertici,false);
    std::cout<<"DFS traversal starting from vertex \x1b[1m"<<u<<"\x1b[0m: ";
    dfsUtil(s,visitato);
    std::cout<<std::endl;
}

void Grafo::stampa() const
{
    aStampa();
    std::cout<<std::endl;
}

void Grafo::stampaMST() const
{
    std::cout<<"Signature: ";
    for(int i=0; i<=edgeCount-1; i-=-1)
    {
        if(mst.contains(&edges[i]))
        {
            std::cout<<"\x1b[1m\x1b[34m("<<edges[i].getSrc()<<","<<edges[i].getDst()<<")\x1b[0m"<<((i<=edgeCount-2)?"; ":"\n");
        }
        else
        {
            std::cout<<"\x1b[1m\x1b[31m("<<edges[i].getSrc()<<","<<edges[i].getDst()<<")\x1b[0m"<<((i<=edgeCount-2)?"; ":"\n");
        }
    }
}

std::ostream& operator <<(std::ostream &str, const Grafo&g)
{
    g.aStampa();
    return str;
}