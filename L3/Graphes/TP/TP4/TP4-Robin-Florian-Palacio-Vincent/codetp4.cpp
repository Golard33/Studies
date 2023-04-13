#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/reverse_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>

using namespace std;
using namespace boost;

struct EdgeProperties
{
    int weight;
    EdgeProperties() : weight(0) {}
    EdgeProperties( int y) : weight(y) {}
};

struct VertexProperties
{
    string name;
    VertexProperties() : name("") {}
    VertexProperties(string y) : name(y) {}
};

struct my_graph_writer {
    void operator()(std::ostream& out) const {
        out << "graph [splines=true, forcelabels=true, pad=0.5, nodesep=5, overlap=false]\nnode [shape=circle]" << std::endl;
    }
};

typedef boost::adjacency_list <
    boost::vecS, // OutEdgeList est un des types de conteneurs choisi en interne
    boost::vecS, // VertexList est de même un type de conteneur choisi en interne
    boost::directedS, // graphe orienté avec des arcs unidirectionnels
    //boost::no_property,
    VertexProperties,
    EdgeProperties
> Graph;

int main()
{
    cout << "Hello World!" << endl;

    Graph g;

    add_vertex(VertexProperties("Début"), g);

    add_vertex(VertexProperties("1.1"), g);
    add_vertex(VertexProperties("1.2"), g);
    add_vertex(VertexProperties("1.3"), g);

    EdgeProperties e1 = EdgeProperties(0);
    add_edge(0, 1, e1, g);
    EdgeProperties e2 = EdgeProperties(0);
    add_edge(0, 2, e2, g);
     EdgeProperties e2 = EdgeProperties(0);
    add_edge(0, 3, e3, g);

    add_vertex(VertexProperties("2.1"), g);
    add_vertex(VertexProperties("2.2"), g);
    add_vertex(VertexProperties("2.3"), g);
    add_vertex(VertexProperties("2.4"), g);

    EdgeProperties e4 = EdgeProperties(4);
    add_edge(1, 3, e4, g);
    EdgeProperties e5 = EdgeProperties(4);
    add_edge(1, 4, e5, g);
    EdgeProperties e5 = EdgeProperties(8);
    add_edge(2, 5, e5, g);
    EdgeProperties e6 = EdgeProperties(1);
    add_edge(3, 6, e6, g);

    add_vertex(VertexProperties("3.1"), g);
    add_vertex(VertexProperties("3.2"), g);

    EdgeProperties e7 = EdgeProperties(13);
    add_edge(3, 7, e7, g);
    EdgeProperties e8 = EdgeProperties(3);
    add_edge(4, 8, e8, g);


    add_vertex(VertexProperties("4.1"), g);
    add_vertex(VertexProperties("4.2"), g);

    EdgeProperties e9 = EdgeProperties(16);
    add_edge(7, 9, e9, g);
    EdgeProperties e10 = EdgeProperties(5);
    add_edge(8, 10, e10, g);

    add_vertex(VertexProperties("5.1"), g);

    EdgeProperties e11 = EdgeProperties(18);
    add_edge(9, 11, e11, g);

    add_vertex(VertexProperties("6.1"), g);

    EdgeProperties e12 = EdgeProperties(23);
    add_edge(11, 12, e12, g);
  

    //Création du fichier nécéssaire à la création de l'image
    string filename = "tp4.dot";
    ofstream fout(filename.c_str());
    write_graphviz(fout, g, make_label_writer(boost::get(&VertexProperties::name, g)), make_label_writer(boost::get(&EdgeProperties::weight, g)), my_graph_writer());
    system("neato -Tpng tp4.dot > tp4_Strategie_A.png");
    fout..close();

    cout << "Fichier crée !" << endl;

    return 0;
}
