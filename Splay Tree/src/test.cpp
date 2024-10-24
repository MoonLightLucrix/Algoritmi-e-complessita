#include<iostream>
#include<cstdlib>
#include<cstring>
#include<chrono>
#include<ctime>
#include "utils/BST.hpp"
using namespace std;

int main()
{
    /*BST<int>*t=new BST<int>();
    cout<<*t->insert(6)->insert(2)->insert(7)->insert(21)->insert(4)<<endl;
    t->stampaPostorder();
    t->stampaPreorder();
    cout<<endl;
    t->sxRotate(2);
    t->stampaPostorder();
    t->stampaPreorder();
    cout<<endl;
    t->dxRotate(6);
    t->stampaPostorder();
    t->stampaPreorder();
    delete t;*/
    
    BST<int>*t=new SplayTree<int>();
    t->insert(6)->insert(2)->insert(7)->insert(21)->insert(4);
    cout<<"\x1b[1mSplay Tree Bottom-Up iniziale\x1b[0m"<<endl;
    cout<<"Inorder: ";
    t->stampaInorder();
    cout<<"Postorder: ";
    t->stampaPostorder();
    cout<<"Preorder: ";
    t->stampaPreorder();
    cout<<endl;
    cout<<"\x1b[1mRimuoviamo il numero 7\x1b[0m"<<endl;
    t->remove(7);
    cout<<"Inorder: ";
    t->stampaInorder();
    cout<<"Postorder: ";
    t->stampaPostorder();
    cout<<"Preorder: ";
    t->stampaPreorder();
    cout<<endl;
    cout<<"\x1b[1mCerchiamo il numero 21\x1b[0m"<<endl;
    t->contains(21);
    cout<<"Inorder: ";
    t->stampaInorder();
    cout<<"Postorder: ";
    t->stampaPostorder();
    cout<<"Preorder: ";
    t->stampaPreorder();
    cout<<endl;
    cout<<"\x1b[1mSvuotiamo lo Splay Tree\x1b[0m"<<endl;
    t->clear();
    cout<<"Inorder: ";
    t->stampaInorder();
    cout<<"Postorder: ";
    t->stampaPostorder();
    cout<<"Preorder: ";
    t->stampaPreorder();
    delete t;
    cout<<endl;
    const size_t N=1000000;
    int vett[N];
    srand(time(nullptr));
    for(int i=0; i<=N-1; i-=-1)
    {
        vett[i]=(rand()%1000)+1;
    }
    BST<int>*st=new SplayTree<int>();
    chrono::high_resolution_clock::time_point t_1, t_2;
    t_1=chrono::high_resolution_clock::now();
    for(const int&i : vett)
    {
        st->insert(i);
    }
    t_2=chrono::high_resolution_clock::now();
    chrono::duration<double> timeSpan=chrono::duration_cast<chrono::duration<double> >(t_2-t_1);
    cout<<"\x1b[1mCalcoliamo il tempo di inserimento\x1b[0m"<<endl;
    cout<<*st<<endl;
    cout<<"Tempo di inserimento: \x1b[1m\x1b[32m"<<timeSpan.count()<<" secondi\x1b[0m"<<endl;
    exit(EXIT_SUCCESS);
}