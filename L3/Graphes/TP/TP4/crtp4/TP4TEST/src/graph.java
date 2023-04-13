import org.jgrapht.graph.*;
import org.jgrapht.alg.interfaces.*;
import org.jgrapht.alg.shortestpath.*;

import java.io.IOException;
import java.util.Arrays;

//Author: ELGHAZI Youness//

public class graph {
    public static void main(String[] args) throws IOException {

        //-- Creation du graphe g representant la decision A -----------------------------------------------------------------------
        SimpleDirectedWeightedGraph <String, DefaultWeightedEdge> g = new SimpleDirectedWeightedGraph<>(DefaultWeightedEdge.class);
        // Creation des sommets
        g.addVertex("0");
        g.addVertex("1.1");
        g.addVertex("1.2");
        g.addVertex("2.1");
        g.addVertex("2.2");
        g.addVertex("2.3");
        g.addVertex("2.4");
        g.addVertex("3.1");
        g.addVertex("3.2");
        g.addVertex("3.3");
        g.addVertex("3.4");
        g.addVertex("3.5");
        g.addVertex("3.6");
        g.addVertex("3.7");
        g.addVertex("3.8");
        g.addVertex("4.1");
        g.addVertex("4.2");
        g.addVertex("4.3");
        g.addVertex("4.4");
        g.addVertex("4.5");
        g.addVertex("4.6");
        g.addVertex("4.7");
        g.addVertex("4.8");


        //Ajout des arcs avec leur coÃ»t
        DefaultWeightedEdge edge1 = (DefaultWeightedEdge) g.addEdge("0", "1.1");
        g.setEdgeWeight(edge1, 10);

        DefaultWeightedEdge edge2 = (DefaultWeightedEdge) g.addEdge("0", "1.2");
        g.setEdgeWeight(edge2, 370);

        DefaultWeightedEdge edge3 = (DefaultWeightedEdge) g.addEdge("1.1", "2.1");
        g.setEdgeWeight(edge3, 20);

        DefaultWeightedEdge edge4 = (DefaultWeightedEdge) g.addEdge("1.1", "2.2");
        g.setEdgeWeight(edge4, 377);

        DefaultWeightedEdge edge5 = (DefaultWeightedEdge) g.addEdge("1.2", "2.3");
        g.setEdgeWeight(edge5, -347);

        DefaultWeightedEdge edge6 = (DefaultWeightedEdge) g.addEdge("1.2", "2.4");
        g.setEdgeWeight(edge6, 10);

        DefaultWeightedEdge edge7 = (DefaultWeightedEdge) g.addEdge("2.1", "3.1");
        g.setEdgeWeight(edge7, 53);

        DefaultWeightedEdge edge8 = (DefaultWeightedEdge) g.addEdge("2.1", "3.2");
        g.setEdgeWeight(edge8, 393);

        DefaultWeightedEdge edge9 = (DefaultWeightedEdge) g.addEdge("2.2", "3.3");
        g.setEdgeWeight(edge9, -315);

        DefaultWeightedEdge edge10 = (DefaultWeightedEdge) g.addEdge("2.2", "3.4");
        g.setEdgeWeight(edge10, 25);

        DefaultWeightedEdge edge11 = (DefaultWeightedEdge) g.addEdge("2.3","3.5");
        g.setEdgeWeight(edge11, 53);

        DefaultWeightedEdge edge12 = (DefaultWeightedEdge) g.addEdge("2.3", "3.6");
        g.setEdgeWeight(edge12, 393);

        DefaultWeightedEdge edge13 = (DefaultWeightedEdge) g.addEdge("2.4", "3.7");
        g.setEdgeWeight(edge13, 315);

        DefaultWeightedEdge edge14 = (DefaultWeightedEdge) g.addEdge("2.4", "3.8");
        g.setEdgeWeight(edge14, 25);

        DefaultWeightedEdge edge15 = (DefaultWeightedEdge) g.addEdge("3.1", "4.1");
        g.setEdgeWeight(edge15,96);

        DefaultWeightedEdge edge16 = (DefaultWeightedEdge) g.addEdge("3.2", "4.2");
        g.setEdgeWeight(edge16, -275);

        DefaultWeightedEdge edge17 = (DefaultWeightedEdge) g.addEdge("3.3","4.3");
        g.setEdgeWeight(edge17, 96);

        DefaultWeightedEdge edge18 = (DefaultWeightedEdge) g.addEdge("3.4", "4.4");
        g.setEdgeWeight(edge18, -275);

        DefaultWeightedEdge edge19 = (DefaultWeightedEdge) g.addEdge("3.5", "4.5");
        g.setEdgeWeight(edge19, 96);

        DefaultWeightedEdge edge20 = (DefaultWeightedEdge) g.addEdge("3.6", "4.6");
        g.setEdgeWeight(edge20, -275);

        DefaultWeightedEdge edge21 = (DefaultWeightedEdge) g.addEdge("3.7", "4.7");
        g.setEdgeWeight(edge21, 96);

        DefaultWeightedEdge edge22 = (DefaultWeightedEdge) g.addEdge("3.8", "4.8");
        g.setEdgeWeight(edge22, -275);



        // Creation du graphe g2 representant la decision B

        SimpleDirectedWeightedGraph <String, DefaultWeightedEdge> g2 = new SimpleDirectedWeightedGraph<>(DefaultWeightedEdge.class);
        // Creation des sommets
        g2.addVertex("0");
        g2.addVertex("1");
        g2.addVertex("2");
        g2.addVertex("3");
        g2.addVertex("4");

        //Ajout des arcs avec leur coÃ»t
        DefaultWeightedEdge edge1b = (DefaultWeightedEdge) g2.addEdge("0", "4");
        g2.setEdgeWeight(edge1b, 130);

        DefaultWeightedEdge edge2b = (DefaultWeightedEdge) g2.addEdge("0", "1");
        g2.setEdgeWeight(edge2b, 10);

        DefaultWeightedEdge edge3b = (DefaultWeightedEdge) g2.addEdge("0", "2");
        g2.setEdgeWeight(edge3b, 23);

        DefaultWeightedEdge edge4b = (DefaultWeightedEdge) g2.addEdge("0", "3");
        g2.setEdgeWeight(edge4b, 65);

        DefaultWeightedEdge edge5b = (DefaultWeightedEdge) g2.addEdge("1", "2");
        g2.setEdgeWeight(edge5b, 20);

        DefaultWeightedEdge edge6b = (DefaultWeightedEdge) g2.addEdge("1", "3");
        g2.setEdgeWeight(edge6b, 62);

        DefaultWeightedEdge edge7b = (DefaultWeightedEdge) g2.addEdge("1", "4");
        g2.setEdgeWeight(edge7b, 127);

        DefaultWeightedEdge edge8b = (DefaultWeightedEdge) g2.addEdge("2", "3");
        g2.setEdgeWeight(edge8b, 53);

        DefaultWeightedEdge edge9b = (DefaultWeightedEdge) g2.addEdge("2", "4");
        g2.setEdgeWeight(edge9b, 118);

        DefaultWeightedEdge edge10b = (DefaultWeightedEdge) g2.addEdge("3", "4");
        g2.setEdgeWeight(edge10b, 96);


        //-------------------------------------------------------------------------------------------------------


        BellmanFordShortestPath bellmanPathA = new BellmanFordShortestPath(g);
        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> cheminA = bellmanPathA.getPaths("0");

        BellmanFordShortestPath bellmanPathB = new BellmanFordShortestPath(g2);
        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> cheminB = bellmanPathB.getPaths("0");

        double[] poidsChemins= new double[8];

        for(int i= 1; i<=8; i++ ){
            poidsChemins[i-1]=cheminA.getPath("4."+i).getWeight();   ///// Tableau des couts de chaque chemins
        }
        Arrays.sort(poidsChemins);
        double minVal = poidsChemins[0];


        double[] poidsCheminsB= new double[8];
        for(int i= 1; i<=8; i++ ){
            poidsCheminsB[i-1]=cheminB.getPath("4").getWeight();   ///// Tableau des couts de chaque chemins
        }
        Arrays.sort(poidsCheminsB);
        double minValB = poidsCheminsB[0];


        for(int i= 1; i<=8; i++ ){
            if(minVal==cheminA.getPath("4."+i).getWeight()){
                System.out.println("Decision A " +  cheminA.getPath("4."+i).getVertexList() + ". Couts : " +cheminA.getPath("4."+i).getWeight());    ////renvoies une listes des sommets d'un chemin
            }
        }
        if(minValB==cheminB.getPath("4").getWeight()){
            System.out.println("Decision B " +  cheminB.getPath("4").getVertexList()+ ". Couts : " +cheminB.getPath("4").getWeight());    ////renvoies une listes des sommets d'un chemin
        }

    }
}
