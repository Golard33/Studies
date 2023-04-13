#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/reverse_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/copy.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <iostream>
#include <fstream>
int main()
{
  using namespace boost;
  typedef adjacency_list < vecS, vecS, undirectedS,no_property, property < edge_weight_t, int > > Graph;
  typedef graph_traits < Graph >::edge_descriptor Edge;
  typedef graph_traits < Graph >::vertex_descriptor Vertex;
  typedef std::pair<int, int> E;
    const int num_nodes = 34; // nombre de noeuds
  E edge_array[] = { E(1, 3), E(1, 6), E(1, 11), E(2, 3), E(2, 9),
    E(3, 4), E(3, 7), E(3, 31), E(4,5), E(4,6), E(4,7), E(5,3), E(6,5), E(7,8), E(7,9), E(8,13), E(9,8), E(9,10), E(10,11), E(10,12)
    , E(10,13), E(11,12), E(11,13), E(12,13), E(13,7), E(13,14), E(14,7), E(14,15), E(15,16), E(15,17), E(16,22), E(16,30), E(16,31), E(16,32)
    , E(16,33), E(16,34), E(17,18), E(18,19), E(18,23), E(19,20), E(19,24), E(20,21), E(21,25), E(22,20), E(22,33), E(23,24)
    , E(23,26), E(24,25), E(24,26), E(25,27), E(25,28), E(26,29), E(27,28), E(28,29), E(30,31), E(30,32), E(31,34), E(32,33)
  };//liaison des noeuds

  int weights[] = { 13, 12, 1, 10,21,11,13,40,4,2,22,4,5,2,8,1,10,9,1,14,9,14,9,14,23,7,12,10,8,18,11,9,9,5,6,13,11,13,10,7,7,6,8,9,2,10,7,4,8,15,6,3,4,10,2,7,2,10,8,1};
  std::size_t num_edges = sizeof(edge_array) / sizeof(E);
  #if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
    Graph g(num_nodes);
    property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, g);
    for (std::size_t j = 0; j < num_edges; ++j) {
      Edge e; bool inserted;
      boost::tie(e, inserted) = add_edge(edge_array[j].first, edge_array[j].second, g);
      weightmap[e] = weights[j];
    }
  #else
    Graph g(edge_array, edge_array + num_edges, weights, num_nodes);
  #endif
  property_map < Graph, edge_weight_t >::type weight = get(edge_weight, g);
  std::vector < Edge > spanning_tree;

  kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree)); //utilisation librairie inclut dans boostgraph

int i=0;
  std::cout << "Print the edges in the MST:" << std::endl;
  for (std::vector < Edge >::iterator ei = spanning_tree.begin();
       ei != spanning_tree.end(); ++ei) {
    std::cout << source(*ei, g) << " <--> " << target(*ei, g)
      << " with weight of " << weight[*ei]
      << std::endl;
       i +=  1;
  }
// création du graphe et du graphe suite à l'algorithme de kruskal dans une seule image
  std::ofstream fout("kruskal-eg.dot");
  fout << "digraph g {\n"
    << " rankdir=TB\n"
    << " edge[style=\"bold\"]\n" << " node[shape=\"circle\"]\n";
  graph_traits<Graph>::edge_iterator eiter, eiter_end;

  for (boost::tie(eiter, eiter_end) = edges(g); eiter != eiter_end; ++eiter) {
    fout << source(*eiter, g) << " -> " << target(*eiter, g);
    if (std::find(spanning_tree.begin(), spanning_tree.end(), *eiter)
        != spanning_tree.end())
      fout << "[color=\"black\", label=\"" << get(edge_weight, g, *eiter)
           << "\"]\n";
    else
      fout << "[color=\"gray\",label=\"" << get(edge_weight, g, *eiter)
           << "\"]\n";
  }
  fout << "}\n";
    write_graphviz(fout, g);
    system("dot -Tpng kruskal-eg.dot > TP2-GrapheMin.png");
  return EXIT_SUCCESS;
}
