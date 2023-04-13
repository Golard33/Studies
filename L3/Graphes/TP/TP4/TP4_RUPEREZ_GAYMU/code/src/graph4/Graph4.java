/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graph4;

import com.mxgraph.layout.hierarchical.mxHierarchicalLayout;
import org.jgrapht.*;
import org.jgrapht.graph.*;
import org.jgrapht.alg.interfaces.*;
import org.jgrapht.ext.JGraphXAdapter;
import org.jgrapht.alg.shortestpath.*;


import javax.imageio.ImageIO;

import com.mxgraph.layout.mxIGraphLayout;
import com.mxgraph.util.mxCellRenderer;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import java.awt.Color;
import java.util.Arrays;

/**
 *
 * @author utilisateur
 */
public class Graph4 {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        
        //-- Création du graphe g représentant la décision A -----------------------------------------------------------------------
        SimpleDirectedWeightedGraph <String, DefaultWeightedEdge> g = new SimpleDirectedWeightedGraph<>(DefaultWeightedEdge.class);        
        // Création des sommets
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
        System.out.println("Graphe de la décision A : ");
        
        //Ajout des arcs avec leur coût
        DefaultWeightedEdge edge1 = (DefaultWeightedEdge) g.addEdge("0", "1.1");
        g.setEdgeWeight(edge1, 10);
        System.out.println(g.getEdgeSource(edge1) + " --> "+ g.getEdgeTarget(edge1)+ " coût : "+ g.getEdgeWeight(edge1));
        DefaultWeightedEdge edge2 = (DefaultWeightedEdge) g.addEdge("0", "1.2");
        g.setEdgeWeight(edge2, 370);
        System.out.println(g.getEdgeSource(edge2) + " --> "+ g.getEdgeTarget(edge2)+ " coût : "+ g.getEdgeWeight(edge2));
        DefaultWeightedEdge edge3 = (DefaultWeightedEdge) g.addEdge("1.1", "2.1");
        g.setEdgeWeight(edge3, 20);
        System.out.println(g.getEdgeSource(edge3) + " --> "+ g.getEdgeTarget(edge3)+ " coût : "+ g.getEdgeWeight(edge3));
        DefaultWeightedEdge edge4 = (DefaultWeightedEdge) g.addEdge("1.1", "2.2");
        g.setEdgeWeight(edge4, 377);
        System.out.println(g.getEdgeSource(edge4) + " --> "+ g.getEdgeTarget(edge4)+ " coût : "+ g.getEdgeWeight(edge4));
        DefaultWeightedEdge edge5 = (DefaultWeightedEdge) g.addEdge("1.2", "2.3");
        g.setEdgeWeight(edge5, -347);
        System.out.println(g.getEdgeSource(edge5) + " --> "+ g.getEdgeTarget(edge5)+ " coût : "+ g.getEdgeWeight(edge5));
        DefaultWeightedEdge edge6 = (DefaultWeightedEdge) g.addEdge("1.2", "2.4");
        g.setEdgeWeight(edge6, 10);
        System.out.println(g.getEdgeSource(edge6) + " --> "+ g.getEdgeTarget(edge6)+ " coût : "+ g.getEdgeWeight(edge6));
        DefaultWeightedEdge edge7 = (DefaultWeightedEdge) g.addEdge("2.1", "3.1");
        g.setEdgeWeight(edge7, 53);
        System.out.println(g.getEdgeSource(edge7) + " --> "+ g.getEdgeTarget(edge7)+ " coût : "+ g.getEdgeWeight(edge7));
        DefaultWeightedEdge edge8 = (DefaultWeightedEdge) g.addEdge("2.1", "3.2");
        g.setEdgeWeight(edge8, 393);
        System.out.println(g.getEdgeSource(edge8) + " --> "+ g.getEdgeTarget(edge8)+ " coût : "+ g.getEdgeWeight(edge8));
        DefaultWeightedEdge edge9 = (DefaultWeightedEdge) g.addEdge("2.2", "3.3");
        g.setEdgeWeight(edge9, -315);
        System.out.println(g.getEdgeSource(edge9) + " --> "+ g.getEdgeTarget(edge9)+ " coût : "+ g.getEdgeWeight(edge9));
        DefaultWeightedEdge edge10 = (DefaultWeightedEdge) g.addEdge("2.2", "3.4");
        g.setEdgeWeight(edge10, 25);
        System.out.println(g.getEdgeSource(edge10) + " --> "+ g.getEdgeTarget(edge10)+ " coût : "+ g.getEdgeWeight(edge10));
        DefaultWeightedEdge edge11 = (DefaultWeightedEdge) g.addEdge("2.3","3.5");
        g.setEdgeWeight(edge11, 53);
        System.out.println(g.getEdgeSource(edge11) + " --> "+ g.getEdgeTarget(edge11)+ " coût : "+ g.getEdgeWeight(edge11));
        DefaultWeightedEdge edge12 = (DefaultWeightedEdge) g.addEdge("2.3", "3.6");
        g.setEdgeWeight(edge12, 393);
        System.out.println(g.getEdgeSource(edge12) + " --> "+ g.getEdgeTarget(edge12)+ " coût : "+ g.getEdgeWeight(edge12));
        DefaultWeightedEdge edge13 = (DefaultWeightedEdge) g.addEdge("2.4", "3.7");
        g.setEdgeWeight(edge13, 315);
        System.out.println(g.getEdgeSource(edge13) + " --> "+ g.getEdgeTarget(edge13)+ " coût : "+ g.getEdgeWeight(edge13));
        DefaultWeightedEdge edge14 = (DefaultWeightedEdge) g.addEdge("2.4", "3.8");
        g.setEdgeWeight(edge14, 25);
        System.out.println(g.getEdgeSource(edge14) + " --> "+ g.getEdgeTarget(edge14)+ " coût : "+ g.getEdgeWeight(edge14));
        DefaultWeightedEdge edge15 = (DefaultWeightedEdge) g.addEdge("3.1", "4.1");
        g.setEdgeWeight(edge15,96);
        System.out.println(g.getEdgeSource(edge15) + " --> "+ g.getEdgeTarget(edge15)+ " coût : "+ g.getEdgeWeight(edge15));
        DefaultWeightedEdge edge16 = (DefaultWeightedEdge) g.addEdge("3.2", "4.2");
        g.setEdgeWeight(edge16, -275);
        System.out.println(g.getEdgeSource(edge16) + " --> "+ g.getEdgeTarget(edge16)+ " coût : "+ g.getEdgeWeight(edge16));
        DefaultWeightedEdge edge17 = (DefaultWeightedEdge) g.addEdge("3.3","4.3");
        g.setEdgeWeight(edge17, 96);
        System.out.println(g.getEdgeSource(edge17) + " --> "+ g.getEdgeTarget(edge17)+ " coût : "+ g.getEdgeWeight(edge17));
        DefaultWeightedEdge edge18 = (DefaultWeightedEdge) g.addEdge("3.4", "4.4");
        g.setEdgeWeight(edge18, -275);
        System.out.println(g.getEdgeSource(edge18) + " --> "+ g.getEdgeTarget(edge18)+ " coût : "+ g.getEdgeWeight(edge18));
        DefaultWeightedEdge edge19 = (DefaultWeightedEdge) g.addEdge("3.5", "4.5");
        g.setEdgeWeight(edge19, 96);
        System.out.println(g.getEdgeSource(edge19) + " --> "+ g.getEdgeTarget(edge19)+ " coût : "+ g.getEdgeWeight(edge19));
        DefaultWeightedEdge edge20 = (DefaultWeightedEdge) g.addEdge("3.6", "4.6");
        g.setEdgeWeight(edge20, -275);
        System.out.println(g.getEdgeSource(edge20) + " --> "+ g.getEdgeTarget(edge20)+ " coût : "+ g.getEdgeWeight(edge20));
        DefaultWeightedEdge edge21 = (DefaultWeightedEdge) g.addEdge("3.7", "4.7");
        g.setEdgeWeight(edge21, 96);
        System.out.println(g.getEdgeSource(edge21) + " --> "+ g.getEdgeTarget(edge21)+ " coût : "+ g.getEdgeWeight(edge21));
        DefaultWeightedEdge edge22 = (DefaultWeightedEdge) g.addEdge("3.8", "4.8");
        g.setEdgeWeight(edge22, -275);
        System.out.println(g.getEdgeSource(edge22) + " --> "+ g.getEdgeTarget(edge22)+ " coût : "+ g.getEdgeWeight(edge22));
        
        
        
        ImageOfG(g,"Decision_A");
        
       //----------------------------------------------------------------------------------------------------
       
       // Création du graphe g2 représentant la décision B
       System.out.println("Graphe de la décision B : ");
        SimpleDirectedWeightedGraph <String, DefaultWeightedEdge> g2 = new SimpleDirectedWeightedGraph<>(DefaultWeightedEdge.class);        
        // Création des sommets
        g2.addVertex("0");  
        g2.addVertex("1");
        g2.addVertex("2");
        g2.addVertex("3");
        g2.addVertex("4");
        
        //Ajout des arcs avec leur coût
        DefaultWeightedEdge edge1b = (DefaultWeightedEdge) g2.addEdge("0", "4");
        g2.setEdgeWeight(edge1b, 130);
        System.out.println(g2.getEdgeSource(edge1b) + " --> "+ g2.getEdgeTarget(edge1b)+ " coût : "+ g2.getEdgeWeight(edge1b));
        DefaultWeightedEdge edge2b = (DefaultWeightedEdge) g2.addEdge("0", "1");
        g2.setEdgeWeight(edge2b, 10);
        System.out.println(g2.getEdgeSource(edge2b) + " --> "+ g2.getEdgeTarget(edge2b)+ " coût : "+ g2.getEdgeWeight(edge2b));
        DefaultWeightedEdge edge3b = (DefaultWeightedEdge) g2.addEdge("0", "2");
        g2.setEdgeWeight(edge3b, 23);
        System.out.println(g2.getEdgeSource(edge3b) + " --> "+ g2.getEdgeTarget(edge3b)+ " coût : "+ g2.getEdgeWeight(edge3b));
        DefaultWeightedEdge edge4b = (DefaultWeightedEdge) g2.addEdge("0", "3");
        g2.setEdgeWeight(edge4b, 65);
        System.out.println(g2.getEdgeSource(edge4b) + " --> "+ g2.getEdgeTarget(edge4b)+ " coût : "+ g2.getEdgeWeight(edge4b));
        DefaultWeightedEdge edge5b = (DefaultWeightedEdge) g2.addEdge("1", "2");
        g2.setEdgeWeight(edge5b, 20);
        System.out.println(g2.getEdgeSource(edge5b) + " --> "+ g2.getEdgeTarget(edge5b)+ " coût : "+ g2.getEdgeWeight(edge5b));
        DefaultWeightedEdge edge6b = (DefaultWeightedEdge) g2.addEdge("1", "3");
        g2.setEdgeWeight(edge6b, 62);
        System.out.println(g2.getEdgeSource(edge6b) + " --> "+ g2.getEdgeTarget(edge6b)+ " coût : "+ g2.getEdgeWeight(edge6b));
        DefaultWeightedEdge edge7b = (DefaultWeightedEdge) g2.addEdge("1", "4");
        g2.setEdgeWeight(edge7b, 127);
        System.out.println(g2.getEdgeSource(edge7b) + " --> "+ g2.getEdgeTarget(edge7b)+ " coût : "+ g2.getEdgeWeight(edge7b));
        DefaultWeightedEdge edge8b = (DefaultWeightedEdge) g2.addEdge("2", "3");
        g2.setEdgeWeight(edge8b, 53);
        System.out.println(g2.getEdgeSource(edge8b) + " --> "+ g2.getEdgeTarget(edge8b)+ " coût : "+ g2.getEdgeWeight(edge8b));
        DefaultWeightedEdge edge9b = (DefaultWeightedEdge) g2.addEdge("2", "4");
        g2.setEdgeWeight(edge9b, 118);
        System.out.println(g2.getEdgeSource(edge9b) + " --> "+ g2.getEdgeTarget(edge9b)+ " coût : "+ g2.getEdgeWeight(edge9b));
        DefaultWeightedEdge edge10b = (DefaultWeightedEdge) g2.addEdge("3", "4");
        g2.setEdgeWeight(edge10b, 96);
        System.out.println(g2.getEdgeSource(edge10b) + " --> "+ g2.getEdgeTarget(edge10b)+ " coût : "+ g2.getEdgeWeight(edge10b));
       
        ImageOfG(g2,"Decision_B");
       
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
                System.out.println("Décision A : chemin le plus court : " +  cheminA.getPath("4."+i).getVertexList() + ". Coût de ce chemin : " +cheminA.getPath("4."+i).getWeight());    ////renvoies une listes des sommets d'un chemin
            }
        }   
        if(minValB==cheminB.getPath("4").getWeight()){
            System.out.println("Décision B : chemin le plus court : " +  cheminB.getPath("4").getVertexList()+ ". Coût de ce chemin : " +cheminB.getPath("4").getWeight());    ////renvoies une listes des sommets d'un chemin
        }

    }
    
    
    
    public static void ImageOfG(Graph<String, DefaultWeightedEdge> g,String n) throws IOException {
        //-----Image du graphe décision A : -----
        JGraphXAdapter<String, DefaultWeightedEdge> graphAdapter = new JGraphXAdapter<>(g);
        mxIGraphLayout layout = new mxHierarchicalLayout(graphAdapter);
        layout.execute(graphAdapter.getDefaultParent());

        BufferedImage image = mxCellRenderer.createBufferedImage(graphAdapter, null, 2, Color.WHITE, false, null);
        File imgFile = new File("./"+n+".png");
        ImageIO.write(image, "png", imgFile);
        
        //-----Image du Graphe décision B : -----
        JGraphXAdapter<String, DefaultWeightedEdge> graphAdapterB = new JGraphXAdapter<>(g);
        mxIGraphLayout layoutB = new mxHierarchicalLayout(graphAdapterB);
        layoutB.execute(graphAdapterB.getDefaultParent());

        BufferedImage imageB = mxCellRenderer.createBufferedImage(graphAdapterB, null, 2, Color.WHITE, false, null);
        File imgFileB = new File("./"+n+".png");
        ImageIO.write(imageB, "png", imgFileB);

    }
}
