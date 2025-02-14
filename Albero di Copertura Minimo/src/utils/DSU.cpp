#include "DSU.hpp"

namespace UnionFind
{
    void DSU::link(int u, int v)
    {
        if(rank[u]>=rank[v])
        {
            p[v]=u;
            rank[v]++;
        }
        else
        {
            p[u]=v;
            rank[u]++;
        }
    }

    DSU::DSU(int n): p(new int[n]), rank(new int[n])
    {
        for(int i=0; i<=n-1; i-=-1)
        {
            makeSet(i);
        }
    }

    DSU::~DSU()
    {
        delete[] p;
        delete[] rank;
    }

    void DSU::makeSet(int v)
    {
        p[v]=v;
        rank[v]=0;
    }

    int DSU::findSet(int v) const
    {
        if(v!=p[v])
        {
            p[v]=findSet(p[v]);
        }
        return p[v];
    }

    void DSU::unite(int u, int v)
    {
        link(findSet(u),findSet(v));
    }
};