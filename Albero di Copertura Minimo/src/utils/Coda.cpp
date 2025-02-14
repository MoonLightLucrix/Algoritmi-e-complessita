#include "Coda.hpp"

template<class T>
Nodo<T>::Nodo(T info, Nodo<T>*succ): info(info), succ(succ) {}

template<class T>
void Nodo<T>::setSucc(Nodo<T>*succ)
{
    this->succ=succ;
}

template<class T>
Nodo<T>* Nodo<T>::getSucc() const
{
    return succ;
}

template<class T>
void Nodo<T>::setInfo(T info)
{
    this->info=info;
}

template<class T>
T Nodo<T>::getInfo() const
{
    return info;
}

template<class T>
Iterator<T>::Iterator(Nodo<T>*a): a(a) {}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
    a=a->getSucc();
    return *this;
}

template<class T>
T Iterator<T>::operator*()
{
    return a->getInfo();
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>&b)
{
    return (a!=b.a);
}

template<class T>
Nodo<T>* Coda<T>::find(T x) const
{
    Nodo<T>*a;
    for(a=testa; a; a=a->getSucc())
    {
        if(a->getInfo()==x)
        {
            break;
        }
    }
    return a;
}

template <class T>
void Coda<T>::aStampa() const
{
    Nodo<T>*a;
    std::cout<<"[";
    for(a=testa; a; a=a->getSucc())
    {
        std::cout<<a->getInfo()<<((a->getSucc())?", ":"");
    }
    std::cout<<"]";
}

template<class T>
Coda<T>::Coda(): testa(nullptr), coda(nullptr), s(0) {}

template<class T>
Coda<T>::~Coda()
{
    clear();
}

template<class T>
Iterator<T> Coda<T>::begin() const
{
    return Iterator<T>(testa);
}

template<class T>
Iterator<T> Coda<T>::end() const
{
    return Iterator<T>();
}

template<class T>
size_t Coda<T>::getSize() const
{
    return s;
}

template<class T>
bool Coda<T>::isEmpty() const
{
    return (!s);
}

template<class T>
Coda<T>* Coda<T>::clear()
{
    Nodo<T>*a;
    while(testa)
    {
        a=testa;
        testa=testa->getSucc();
        delete a;
        s-=1;
    }
    coda=testa;
    return this;
}

template<class T>
Coda<T>* Coda<T>::enqueue(T x)
{
    Nodo<T>*a=new Nodo<T>(x);
    if(isEmpty())
    {
        testa=coda=a;
    }
    else
    {
        a->setSucc(testa);
        testa=a;
    }
    s-=-1;
    return this;
}

template<class T>
T Coda<T>::getFirst()
{
    if(isEmpty())
    {
        throw std::runtime_error("Coda vuota");
    }
    return testa->getInfo();
}

template<class T>
T Coda<T>::getLast()
{
    if(isEmpty())
    {
        throw std::runtime_error("Coda vuota");
    }
    return coda->getInfo();
}

template<class T>
Coda<T>* Coda<T>::dequeue()
{
    if(!isEmpty())
    {
        if(testa==coda)
        {
            delete coda;
            testa=coda=nullptr;
        }
        else
        {
            Nodo<T>*a=testa;
            while(a->getSucc()!=coda)
            {
                a=a->getSucc();
            }
            a->setSucc(nullptr);
            delete coda;
            coda=a;
        }
        s-=1;
    }
    return this;
}

template<class T>
Coda<T>* Coda<T>::remove(T x)
{
    Nodo<T>*a=find(x);
    if(a)
    {
        if(a==testa)
        {
            testa=testa->getSucc();
        }
        else if(a==coda)
        {
            return dequeue();
        }
        else
        {
            Nodo<T>*b;
            for(b=testa; b->getSucc()!=a; b=b->getSucc()){}
            b->setSucc(a->getSucc());
        }
        delete a;
        s-=1;
    }
    return this;
}

template<class T>
Coda<T>* Coda<T>::map(std::function<T(T)> lambda)
{
    if(!isEmpty())
    {
        for(Nodo<T>*a=testa; a; a=a->getSucc())
        {
            a->setInfo(lambda(a->getInfo()));
        }
    }
    return this;
}

template<class T>
Coda<T>* Coda<T>::filter(std::function<bool(T)> predicate)
{
    Nodo<T>*a=testa;
    while(a)
    {
        if(predicate(a->getInfo())) 
        {
            T dataToRemove=a->getInfo();
            a=a->getSucc();
            remove(dataToRemove);
        }
        else
        {
            a=a->getSucc();
        }
    }
    return this;
}

template<class T>
template<class U>
U Coda<T>::reduce(std::function<U(T,U)> lambda)
{
    U accumulator=U();
    Nodo<T>*a;
    for(a=testa; a; a=a->getSucc())
    {
        accumulator=lambda(a->getInfo(),accumulator);
    }
    return accumulator;
}

template<class T>
bool Coda<T>::contains(T x) const
{
    return (find(x));
}

template<class T>
void Coda<T>::stampa() const
{
    aStampa();
    std::cout<<std::endl;
}

template<class U>
std::ostream& operator <<(std::ostream &str, const Coda<U>&a)
{
    a.aStampa();
    return str;
}