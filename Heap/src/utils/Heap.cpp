#include "Heap.hpp"

template<class T>
size_t Heap<T>::getSx(size_t a) const
{
    return a<<1;
}

template<class T>
size_t Heap<T>::getDx(size_t a) const
{
    return (a<<1)+1;
}

template<class T>
size_t Heap<T>::getUp(size_t a) const
{
    return a>>1;
}

template<class T>
void Heap<T>::scambia(size_t a, size_t b)
{
    T*x=nodo[a];
    nodo[a]=nodo[b];
    nodo[b]=x;
}

template<class T>
void Heap<T>::heapify(size_t a)
{
    if(a<=hSize)
    {
        size_t i=getSx(a);
        size_t j=getDx(a);
        size_t select=a;
        if((i<=hSize) && (compare(nodo[i],nodo[select])))
        {
            select=i;
        }
        if((j<=hSize) && (compare(nodo[j],nodo[select])))
        {
            select=j;
        }
        if(select!=a)
        {
            scambia(a,select);
            heapify(select);
        }
    }
}

template<class T>
void Heap<T>::aStampa() const
{
    for(int i=1; i<=hSize; i-=-1)
    {
        std::cout<<*nodo[i]<<((i<=hSize-1)?", ":"");        
    }
}

template<class T>
Heap<T>::Heap(size_t hLimit): hLimit(hLimit+1), nodo(new T*[hLimit+1]), hSize(0) {}

template<class T>
Heap<T>::Heap(T*vett, size_t n): hLimit(n+1), hSize(0), nodo(new T*[n+1]) {}

template<class T>
Heap<T>::~Heap()
{
    clear();
    delete[] nodo;
}

template<class T>
size_t Heap<T>::getHeapSize() const
{
    return hSize;
}

template<class T>
T Heap<T>::getTop() const
{
    return *nodo[radice];
}

template<class T>
Heap<T>* Heap<T>::enqueue(T x)
{
    if(hSize<=hLimit-2)
    {
        hSize-=-1;
        size_t i=hSize;
        nodo[i]=new T(x);
        while((i>=2) && (compare(nodo[i],nodo[getUp(i)])))
        {
            scambia(i,getUp(i));
            i=getUp(i);
        }
    }
    else
    {
        std::cout<<"Heap pieno!"<<std::endl;
    }
    return this;
}

template<class T>
Heap<T>* Heap<T>::buildHeap(T*vett, size_t n)
{
    if(hSize+n<=hLimit-1)
    {
        for(int i=0; i<=n-1; i-=-1)
        {
            hSize-=-1;
            nodo[hSize]=new T(vett[i]);
        }
        for(int i=getUp(hSize); i>=1; i-=1)
        {
            heapify(i);
        }
    }
    return this;
}

template<class T>
T Heap<T>::dequeue()
{
    T x=T();
    if(hSize)
    {
        scambia(radice,hSize);
        x=*nodo[hSize];
        delete nodo[hSize];
        hSize-=1;
        heapify(radice);
    }
    return x;
}

template<class T>
Heap<T>* Heap<T>::extract()
{
    dequeue();
    return this;
}

template<class T>
Heap<T>* Heap<T>::clear()
{
    if(hSize)
    {
        for(int i=1; i<=hSize; i-=-1)
        {
            delete nodo[i];
        }
        hSize=0;
    }
    return this;
}

template<class T>
void Heap<T>::stampa() const
{
    aStampa();
    std::cout<<std::endl;
}

template<class U>
std::ostream &operator <<(std::ostream &str, const Heap<U>&h)
{
    h.aStampa();
    return str;
}

template<class T>
bool MaxHeap<T>::compare(T*a, T*b) const
{
    return (*a>=*b);
}
template<class T>
MaxHeap<T>::MaxHeap(size_t hLimit): Heap<T>(hLimit) {}

template<class T>
MaxHeap<T>::MaxHeap(T*vett, size_t n): Heap<T>(vett,n)
{
    buildHeap(vett,n);
}

template<class T>
MaxHeap<T>::~MaxHeap(){}

template<class T>
bool MinHeap<T>::compare(T*a, T*b) const
{
    return (*a<=*b);
}

template <class T>
MinHeap<T>::MinHeap(size_t hLimit) : Heap<T>(hLimit) {}

template<class T>
MinHeap<T>::MinHeap(T*vett, size_t n): Heap<T>(vett,n)
{
    buildHeap(vett,n);
}

template<class T>
MinHeap<T>::~MinHeap(){}