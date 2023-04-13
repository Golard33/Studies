#include <iostream>
#include <algorithm>

#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/graph_traits.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/reverse_graph.hpp>
#include <boost/graph/graph_utility.hpp>
using namespace std;
using namespace boost;



struct VertexProperties
{
   unsigned id;
   //un identifiant manuel (qui n'est pas assigné automatiquement par la librairie) donc 1,2,3, etc ...
   //un constructeur par défaut si aucune donnée n'est rentrée lors de la création du noeud.
   VertexProperties() : id(0) {}
   //La fonction qui permet d'assigner les valeurs saisies par l'utilisateur au noeud correspondant.
   VertexProperties(unsigned i) : id(i) {}
};



//Création d'un DFS Visitor personnalisé pour noter et récupérer les sommets dans l'ordre date fin
class custom_dfs_visitor_finish : public boost::default_dfs_visitor
{
   public:
      custom_dfs_visitor_finish() : vv(new std::vector<int>()) {}

      template < typename Vertex, typename Graph >

      void finish_vertex(Vertex u, const Graph & g) const
         {
            VertexProperties const& vertexProperties = g[u];
            std::cout << "Fini: " << vertexProperties.id <<endl;
            vv->push_back(g[u].id);
         }

         std::vector<int> &GetVectorF() const { return *vv; }

   private:
         boost::shared_ptr<std::vector<int> > vv;
};






class custom_dfs_visitor_discover : public boost::default_dfs_visitor
{
   public:
      custom_dfs_visitor_discover() : vw(new std::vector<int>()) {}

      template < typename Vertex, typename Graph >

         void discover_vertex(Vertex u, const Graph & g) const
            {
               VertexProperties const& vertexProperties = g[u];
               std::cout << "DÃ©couvert: " << vertexProperties.id <<endl;
               vw->push_back(g[u].id);
            }

         std::vector<int> &GetVectorD() const { return *vw; }

   private:
         boost::shared_ptr<std::vector<int> > vw;
};



int main(int, char*[])
{
   //Création des fichiers et streams nécessaires Ã  la création des images
   string filename = "graph.dot";
   ofstream fout(filename.c_str());

   string filename2 = "result.dot";
   ofstream fout2(filename2.c_str());

   string filename3 = "dual.dot";
   ofstream fout3(filename3.c_str());

   typedef adjacency_list < vecS, vecS, bidirectionalS, VertexProperties > Graph;
   typedef graph_traits<Graph>::vertex_descriptor vertex_t;
   typedef graph_traits<Graph>::edge_descriptor edge_t;

   //Création du graphe, des noeuds et des arcs
   Graph g;
   vertex_t V1 = add_vertex(VertexProperties(1),g);
   vertex_t V2 = add_vertex(VertexProperties(2),g);
   vertex_t V3 = add_vertex(VertexProperties(3),g);
   vertex_t V4 = add_vertex(VertexProperties(4),g);
   vertex_t V5 = add_vertex(VertexProperties(5),g);
   vertex_t V6 = add_vertex(VertexProperties(6),g);
   vertex_t V7 = add_vertex(VertexProperties(7),g);
   vertex_t V8 = add_vertex(VertexProperties(8),g);
   vertex_t V9 = add_vertex(VertexProperties(9),g);
   vertex_t V10 = add_vertex(VertexProperties(10),g);
   vertex_t V11 = add_vertex(VertexProperties(11),g);
   vertex_t V12 = add_vertex(VertexProperties(12),g);
   vertex_t V13 = add_vertex(VertexProperties(13),g);
   vertex_t V14 = add_vertex(VertexProperties(14),g);
   vertex_t V15 = add_vertex(VertexProperties(15),g);
    vertex_t V16 = add_vertex(VertexProperties(16),g);
   vertex_t V17 = add_vertex(VertexProperties(17),g);
   const string names [] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16","17"};

   pair<Graph::edge_descriptor, bool> e1 = add_edge(V1, V2, g);
   pair<Graph::edge_descriptor, bool> e2 = add_edge(V1, V4, g);
   pair<Graph::edge_descriptor, bool> e3 = add_edge(V1, V10, g);
   pair<Graph::edge_descriptor, bool> e4 = add_edge(V1, V11, g);
   pair<Graph::edge_descriptor, bool> e5 = add_edge(V1, V15, g);
   pair<Graph::edge_descriptor, bool> e6 = add_edge(V2, V3, g);
   pair<Graph::edge_descriptor, bool> e7 = add_edge(V2, V6, g);
   pair<Graph::edge_descriptor, bool> e8 = add_edge(V2, V9, g);
   pair<Graph::edge_descriptor, bool> e9 = add_edge(V2, V14, g);
   pair<Graph::edge_descriptor, bool> e10 = add_edge(V3, V4, g);
   pair<Graph::edge_descriptor, bool> e11 = add_edge(V3, V7, g);
   pair<Graph::edge_descriptor, bool> e12 = add_edge(V4, V5, g);
   pair<Graph::edge_descriptor, bool> e13 = add_edge(V4, V9, g);
   pair<Graph::edge_descriptor, bool> e14 = add_edge(V4, V15, g);
   pair<Graph::edge_descriptor, bool> e15 = add_edge(V5, V6, g);
   pair<Graph::edge_descriptor, bool> e16 = add_edge(V5, V8, g);
   pair<Graph::edge_descriptor, bool> e17 = add_edge(V5, V12, g);
   pair<Graph::edge_descriptor, bool> e18 = add_edge(V6, V9, g);
   pair<Graph::edge_descriptor, bool> e19 = add_edge(V6, V14, g);
   pair<Graph::edge_descriptor, bool> e20 = add_edge(V7, V6, g);
   pair<Graph::edge_descriptor, bool> e21 = add_edge(V7, V15, g);
   pair<Graph::edge_descriptor, bool> e22 = add_edge(V8, V6, g);
   pair<Graph::edge_descriptor, bool> e23 = add_edge(V8, V7, g);
   pair<Graph::edge_descriptor, bool> e24 = add_edge(V8, V11, g);
   pair<Graph::edge_descriptor, bool> e25 = add_edge(V9, V7, g);
   pair<Graph::edge_descriptor, bool> e26 = add_edge(V9, V8, g);
   pair<Graph::edge_descriptor, bool> e27 = add_edge(V9, V10, g);
   pair<Graph::edge_descriptor, bool> e28 = add_edge(V10, V13, g);
   pair<Graph::edge_descriptor, bool> e29 = add_edge(V11, V10, g);
   pair<Graph::edge_descriptor, bool> e30 = add_edge(V11, V15, g);
   pair<Graph::edge_descriptor, bool> e31 = add_edge(V12, V11, g);
   pair<Graph::edge_descriptor, bool> e32 = add_edge(V13, V12, g);
   pair<Graph::edge_descriptor, bool> e33 = add_edge(V14, V11, g);
   pair<Graph::edge_descriptor, bool> e34 = add_edge(V14, V12, g);
   pair<Graph::edge_descriptor, bool> e35 = add_edge(V15, V10, g);
   pair<Graph::edge_descriptor, bool> e36 = add_edge(V15, V14, g);
    pair<Graph::edge_descriptor, bool> e37 = add_edge(V16, V10, g);
   pair<Graph::edge_descriptor, bool> e38 = add_edge(V17, V14, g);

   //Première recherche en profondeur, sur le graphe
   custom_dfs_visitor_finish vis;
   cout <<endl<< "Recherche en profondeur sur le Graphe, date fin:" << endl;
   depth_first_search(g , visitor(vis));

   //Création des images du graphe et du graphe dual
   write_graphviz(fout, g, make_label_writer(&names[0]));
   system("dot -Tpng graph.dot > graph.png");
   write_graphviz(fout3, make_reverse_graph(g), make_label_writer(&names[0]));
   system("dot -Tpng dual.dot > dual.png");

   //Récupération de l'ordre date fin de la première recherche, et inversion de l'ordre pour l'avoir 		décroissant
   vector<int> datefinDecroissant = vis.GetVectorF();
   reverse(datefinDecroissant.begin(), datefinDecroissant.end());

   //Création d'un vecteur aidant à isoler les composantes fortement connexes
   //en ne contenant que les sommets pas encore explorés
   vector<int> vect;
   for (int i = 0; i < 15; i++)
   {
      vect.push_back(i+1);
   }

   custom_dfs_visitor_discover tempVis;
   auto indexmap = get(vertex_index, g);
   auto colormap = make_vector_property_map<default_color_type>(indexmap);
   vector<int> tempVect;
   vector<int> tempVect2;
   vector<int> tempDiff;

   //Parcours en profondeur sur le graphe dual, en suivant l'ordre date fin décroissant
   cout <<endl<<endl<< "Recherche en profondeur sur le graphe dual, dans l'ordre décroissant de date fin:" <<endl;
   for (int i = 0; i < datefinDecroissant.size(); i++)
   {
            //On ne lance une recherche que sur les sommets que l'on n'a pas encore visité
            vector<int>::iterator it = std::find(vect.begin(), vect.end(), datefinDecroissant[i]);
            if (it != vect.end())
            {
                  cout <<endl<< "Recherche à  partir de: " << datefinDecroissant[i]<<endl;
                  depth_first_visit(make_reverse_graph(g), i, tempVis, colormap);
                  tempVect = tempVis.GetVectorD();
                  set_difference(tempVect.begin(), tempVect.end(), tempVect2.begin(), tempVect2.end(), 
                  inserter(tempDiff, tempDiff.begin()));

                  cout << "Composante fortement connexe trouvée: ";
                  for (int p = 0; p < tempDiff.size(); p++)
                     cout << tempDiff[p] << " ";
                  cout <<endl;

                  //Mise à  jour du vecteur d'aide
                  for (int j = 0; j < tempDiff.size(); j++)
                  {
                        vector<int>::iterator it2 = std::find(vect.begin(), vect.end(), tempDiff[j]);
                        if (it2 != vect.end()){
                        vect.erase(it2);
                        }
                  }

                  //Pour la représentation graphique, suppression des arcs n'appartenant pas aux composantes fortement connexes
                  if (tempDiff.size() == 1)
                  {
                        clear_out_edges(i,g);
                        clear_in_edges(i,g);
                  }
                  else for (int j = 0; j < tempDiff.size(); j++)
                  {
                        for (int k = 0; k < vect.size(); k++)
                        {
                              remove_edge(tempDiff[j]-1, vect[k]-1, g);
                              remove_edge(vect[k]-1, tempDiff[j]-1, g);
                        }
                  }

                  tempVect2 = tempVect;
                  tempDiff.clear();
            }
   }

   //Création de l'image finale, contenant les composantes fortement connexes
   write_graphviz(fout2, g, make_label_writer(&names[0]));
   system("dot -Tpng result.dot > result.png");
   cout <<endl;
   return 0;
}
