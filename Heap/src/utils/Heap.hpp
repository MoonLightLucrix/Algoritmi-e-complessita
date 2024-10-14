#ifndef HEAP
#define HEAP

template<class T>
class Heap
{
    private:
        T**nodo;
        size_t hSize;
        size_t hLimit;
        const size_t radice=1;
        size_t getSx(size_t a) const;
        size_t getDx(size_t a) const;
        size_t getUp(size_t a) const;
        void scambia(size_t a, size_t b);
        void heapify(size_t a);
        void aStampa() const;
    protected:
        virtual bool compare(T*a, T*b) const = 0;
    public:
        Heap<T>(size_t hLimit);
        Heap<T>(T*vett, size_t n);
        virtual ~Heap<T>();
        size_t getHeapSize() const;
        T getTop() const;
        Heap<T>*enqueue(T x);
        Heap<T>*buildHeap(T*vett, size_t n);
        T dequeue();
        Heap<T>*extract();
        Heap<T>*clear();
        void stampa() const;

        template<class U>
        friend std::ostream& operator <<(std::ostream &str, const Heap<U>&h);
};

template<class T>
class MaxHeap:public Heap<T>
{
    private:
        bool compare(T*a, T*b) const override;
    public:
        using Heap<T>::getHeapSize;
        using Heap<T>::getTop;
        using Heap<T>::enqueue;
        using Heap<T>::buildHeap;
        using Heap<T>::dequeue;
        using Heap<T>::extract;
        using Heap<T>::clear;
        using Heap<T>::stampa;
        MaxHeap<T>(size_t hLimit);
        MaxHeap<T>(T*vett, size_t n);
        ~MaxHeap<T>();
};

template<class T>
class MinHeap:public Heap<T>
{
    private:
        bool compare(T*a, T*b) const override;
    public:
        using Heap<T>::getHeapSize;
        using Heap<T>::getTop;
        using Heap<T>::enqueue;
        using Heap<T>::buildHeap;
        using Heap<T>::dequeue;
        using Heap<T>::extract;
        using Heap<T>::clear;
        using Heap<T>::stampa;
        MinHeap<T>(size_t hLimit);
        MinHeap<T>(T*vett, size_t n);
        ~MinHeap<T>();
};

#include "Heap.cpp"

#endif