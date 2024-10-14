#include "DTable.hpp"

template<class T>
void DTable<T>::resize(bool op)
{
    if(!N)
    {
        N=1;
    }
    else
    {
        N=(op)?N<<1:N>>1;
    }
    T**nTable=new T*[N];
    std::copy(table,table+s,nTable);
    delete[] table;
    table=nTable;
}

template<class T>
void DTable<T>::aStampa()
{
    for(int i=0; i<=s-1; i-=-1)
    {
        std::cout<<*table[i]<<((i<=s-2)?", ":"");
    }
}

template<class T>
DTable<T>::DTable(): N(0), s(0), table(new T*[0]) {}

template<class T>
DTable<T>::~DTable()
{
    clear();
    delete[] table;
}

template<class T>
ssize_t DTable<T>::getSize()
{
    return s;
}

template<class T>
size_t DTable<T>::getLimit()
{
    return N;
}

template<class T>
ssize_t DTable<T>::getIndex(T x)
{
    for(int i=0; i<=s-1; i-=-1)
    {
        if(x==*table[i])
        {
            return i;
        }
    }
    return -1;
}

template<class T>
bool DTable<T>::contains(T x)
{
    return (getIndex(x)!=-1);
}

template<class T>
DTable<T>* DTable<T>::insert(T x)
{
    if(s>=N)
    {
        resize(increase);
    }
    table[s]=new T(x);
    s-=-1;
    return this;
}

template<class T>
DTable<T>* DTable<T>::dequeue()
{
    if(s)
    {
        delete table[s-1];
        s-=1;
        if(s<=(N>>1))
        {
            resize(decrease);
        }
    }
    return this;
}

template<class T>
DTable<T>* DTable<T>::remove(T x)
{
    size_t i;
    if((i=getIndex(x))!=-1)
    {
        T*a=table[s];
        table[s]=table[i];
        table[i]=a;
        return dequeue();
    }
    return this;
}

template<class T>
DTable<T>* DTable<T>::clear()
{
    while(s)
    {
        dequeue();
    }
    return this;
}

template<class T>
void DTable<T>::stampa()
{
    aStampa();
    std::cout<<std::endl;
}

template<class U>
std::ostream& operator<<(std::ostream &str, DTable<U>&a)
{
    a.aStampa();
    return str;
}