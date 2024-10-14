#include<iostream>
#include<cstdlib>
#include<cstring>
#include "utils/Gatto.hpp"
#include "utils/Heap.hpp"
using namespace std;

int main(int argc, char**argv)
{
    int vett[]={4,1,6,3,7};
    Heap<int>*mh=new MaxHeap<int>(5);
    cout<<*mh->buildHeap(vett,5)<<endl;
    int d=mh->dequeue();
    cout<<"d: "<<d<<endl<<"heapSize: "<<mh->getHeapSize()<<endl;
    cout<<*mh<<endl;
    delete mh;
    cout<<endl;
    Heap<Gatto>*minheap=new MinHeap<Gatto>(3);
    cout<<*minheap->enqueue(Gatto("Nano",3,4.5))->enqueue(Gatto("Gigi",6,7.4))->enqueue(Gatto("Marmellata",2,3.2))<<endl;
    delete minheap;
    exit(EXIT_SUCCESS);
}