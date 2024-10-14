#include<iostream>
#include<cstdlib>
#include<cstring>
#include "utils/Gatto.hpp"
#include "utils/DTable.hpp"
using namespace std;

int main()
{
    DTable<int>*dt=new DTable<int>();
    cout<<*dt->insert(5)->insert(7)->insert(3)->insert(2)->insert(8)<<endl;
    cout<<"N: "<<dt->getLimit()<<endl<<"s: "<<dt->getSize()<<endl<<endl;
    cout<<*dt->dequeue()<<endl;
    cout<<"N: "<<dt->getLimit()<<endl<<"s: "<<dt->getSize()<<endl<<endl;
    delete dt;
    DTable<Gatto>*g=new DTable<Gatto>();
    cout<<*g->insert(Gatto("Duchessa",6,4.5))->insert(Gatto("Romeo",7,5))->insert(Gatto("Bisé",2,2.3))->insert(Gatto("Minù",2,2))->insert(Gatto("Matis",2,3.2))<<endl;
    cout<<"N: "<<dt->getLimit()<<endl<<"s: "<<dt->getSize()<<endl;
    delete g;
    exit(EXIT_SUCCESS);
}