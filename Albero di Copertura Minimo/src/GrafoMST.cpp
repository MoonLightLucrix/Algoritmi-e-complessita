#include<iostream>
#include<cstdlib>
#include<cstring>
#include "utils/Grafo.hpp"
using namespace std;

int main(int argc, char**argv)
{
    Grafo*g=new Grafo(10);
    cout<<*g->addEdge('a','b',2)->addEdge('b','c',4)->addEdge('c','d',7)->addEdge('d','f',8)->addEdge('f','g',10)->addEdge('g','h',2)->addEdge('a','e',4)->addEdge('a','i',16)->addEdge('i','j',6)->addEdge('b','i',10)->addEdge('b','e',3)->addEdge('c','e',2)->addEdge('d','e',2)->addEdge('e','f',3)->addEdge('e','h',6)->addEdge('e','i',2)->addEdge('f','i',3)->addEdge('f','h',9)->addEdge('h','i',9)->addEdge('h','j',9)<<endl;
    g->bfs('a');
    g->dfs('a');
    g->stampaMST();
    delete g;
    exit(EXIT_SUCCESS);
}