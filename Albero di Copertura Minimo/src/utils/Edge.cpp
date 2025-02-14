#include "Edge.hpp"

namespace UnionFind
{
    Edge::Edge(V src, V dst, int weight): src(src), dst(dst), weight(weight) {}

    void Edge::setSrc(V src)
    {
        this->src=src;
    }

    V Edge::getSrc() const
    {
        return src;
    }

    void Edge::setDst(V dst)
    {
        this->dst=dst;
    }

    V Edge::getDst() const
    {
        return dst;
    }

    void Edge::setWeight(int weight)
    {
        this->weight=weight;
    }

    int Edge::getWeight() const
    {
        return weight;
    }

    std::string Edge::leggiEdge() const
    {
        return "source vertex: " + std::string(1,src) + " destination vertex: " + std::string(1,dst) + " edge weight: " + std::to_string(weight);
    }

    void Edge::stampa() const
    {
        std::cout<<leggiEdge()<<std::endl;
    }

    bool operator <(const Edge&a, const Edge&b)
    {
        return (a.getWeight()<b.getWeight());
    }

    bool operator >(const Edge&a, const Edge&b)
    {
        return (a.getWeight()>b.getWeight());
    }

    bool operator <=(const Edge&a, const Edge&b)
    {
        return (a.getWeight()<=b.getWeight());
    }

    bool operator >=(const Edge&a, const Edge&b)
    {
        return (a.getWeight()>=b.getWeight());
    }

    bool operator ==(const Edge&a, const Edge&b)
    {
        return (a.getWeight()==b.getWeight());
    }

    bool operator !=(const Edge&a, const Edge&b)
    {
        return (a.getWeight()!=b.getWeight());
    }

    std::ostream &operator<<(std::ostream &str, const Edge &e)
    {
        str<<e.leggiEdge();
        return str;
    }
};