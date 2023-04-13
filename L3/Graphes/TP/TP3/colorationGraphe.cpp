#include <iostream>
#include <list>
using namespace std;

class graph 
{
    int V;
    list<int> *adj;
public :
    graph(int V) {this->V = V; adj = new list<int>[V];}
    ~graph() {delete [] adj;}

    void addEdge(int v, int W);

    void greedyColoring();

};

void graph::addEdge (int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


void graph::greedyColoring()
{
    int result[V];

    result[0] = 0;

    for(int u = 1; u< V; u++)
        result[u] = -1;
    
    bool available[V];
    for (int cr = 0; cr<V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if(result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if(available[cr] == false)
                break;
        result[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); i++)
            if (result [*i] != -1)
                available[result[*i]] = false;
    }

    for (int u = 0; u< V; u++)
    {
        cout <<"vertex" << u << "--) color"
            << result[u] << endl;
    }
}

int main ()
{
    Graph g1(19);

    //A = 0 ; B = 1 ; C= 2;
    // D= 3; E=4; F=5; G=6; H=7; I=8;
    // J=9; K=10; L=11; M=12; N= 13;
    // O=14; P=15; Q=16; R=17; S=18; T=19;

    g1.addEdge(0,3); //A
    g1.addEdge(0,4);
    g1.addEdge(0,7);
    g1.addEdge(0,10);

    g1.addEdge(1,2);//B
    g1.addEdge(1,6);
    g1.addEdge(1,12);
    g1.addEdge(1,18);

    g1.addEdge(2,1); //C
    g1.addEdge(2,17);
    g1.addEdge(2,19);

    g1.addEdge(3,0);//D
    g1.addEdge(3,12);
    g1.addEdge(3,18);

    g1.addEdge(4,0);//E
    g1.addEdge(4,5);
    g1.addEdge(4,6);
    g1.addEdge(4,14);

    g1.addEdge(5,4);//F
    g1.addEdge(5,6);
    g1.addEdge(5,16);
    g1.addEdge(5,19);

    g1.addEdge(6,1);//G
    g1.addEdge(6,4);
    g1.addEdge(6,5);
    g1.addEdge(6,8);

    g1.addEdge(7,0); // H
    g1.addEdge(7,11);
    g1.addEdge(7,14);

    g1.addEdge(8,6);//I
    g1.addEdge(8,10);
    g1.addEdge(8,18);

    g1.addEdge(9,13);//J
    g1.addEdge(9,14);

    g1.addEdge(10,0);//K
    g1.addEdge(10,8);
    g1.addEdge(10,15);
    g1.addEdge(10,17);

    g1.addEdge(11,7);//L
    g1.addEdge(11,14);

    g1.addEdge(12,1);//M
    g1.addEdge(12,3);

    g1.addEdge(13,9);//N
    g1.addEdge(13,19);

    g1.addEdge(14,4);//O
    g1.addEdge(14,9);
    g1.addEdge(14,11);

    g1.addEdge(15,10);//P
    g1.addEdge(15,19);

    g1.addEdge(16,5);//Q
    g1.addEdge(16,7);

    g1.addEdge(17,2);//R
    g1.addEdge(17,10);

    g1.addEdge(18,1);//S
    g1.addEdge(18,3);
    g1.addEdge(18,8);

    g1.addEdge(19,2);//T
    g1.addEdge(19,5);
    g1.addEdge(19,13);
    g1.addEdge(19,15);

    cout << "coloring of graph \n";
    g1.greedyColoring();

    return 0;
}