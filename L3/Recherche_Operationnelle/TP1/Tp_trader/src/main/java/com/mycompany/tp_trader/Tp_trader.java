/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.tp_trader;

import com.mxgraph.layout.mxFastOrganicLayout;

import java.io.*;

import org.jgrapht.graph.SimpleDirectedWeightedGraph;
import org.jgrapht.alg.flow.EdmondsKarpMFImpl;
import org.jgrapht.alg.flow.MaximumFlowAlgorithmBase;
import org.jgrapht.alg.interfaces.ShortestPathAlgorithm.SingleSourcePaths;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;
import org.jgrapht.graph.*;
import com.mxgraph.util.mxCellRenderer;

import java.awt.Color;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import org.jgrapht.ext.JGraphXAdapter;

/**
 *
 * @author florian robin
 */

public class Tp_trader {
    
	//Cette classe nous permet d'afficher les coûts des arcs 
    

	//Fonction pour la création du graphe B
    public static SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> buildGraphQ3(){
        
        SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> graph = new SimpleDirectedWeightedGraph<>(DefaultWeightedEdge.class);
 
        graph.addVertex("S");
        graph.addVertex("E1");
        graph.addVertex("E2");
        graph.addVertex("F1");
        graph.addVertex("F2");
        graph.addVertex("A1");
        graph.addVertex("A2");
        graph.addVertex("A3");
        graph.addVertex("P");
       
        DefaultWeightedEdge Se1 = graph.addEdge("S","E1"); 
        graph.setEdgeWeight(Se1, 100);
        DefaultWeightedEdge Se2 = graph.addEdge("S","E2"); 
        graph.setEdgeWeight(Se2, 100);
        DefaultWeightedEdge e1a1 = graph.addEdge("E1","A1"); 
        graph.setEdgeWeight(e1a1, 30);
        DefaultWeightedEdge e1f1 = graph.addEdge("E1","F1"); 
        graph.setEdgeWeight(e1f1, 60);
        DefaultWeightedEdge e2f1 = graph.addEdge("E2","F1"); 
        graph.setEdgeWeight(e2f1, 50);
        DefaultWeightedEdge e2f2 = graph.addEdge("E2","F2"); 
        graph.setEdgeWeight(e2f2, 40);
        DefaultWeightedEdge f1a1 = graph.addEdge("F1","A1"); 
        graph.setEdgeWeight(f1a1, 30);
        DefaultWeightedEdge f1a2 = graph.addEdge("F1","A2"); 
        graph.setEdgeWeight(f1a2, 50);
        DefaultWeightedEdge f1a3 = graph.addEdge("F1","A3"); 
        graph.setEdgeWeight(f1a3, 40);
        DefaultWeightedEdge f1f2 = graph.addEdge("F1","F2"); 
        graph.setEdgeWeight(f1f2, 20);
        DefaultWeightedEdge f2a3 = graph.addEdge("F2","A3"); 
        graph.setEdgeWeight(f2a3, 50);
        DefaultWeightedEdge a1P = graph.addEdge("A1","P"); 
        graph.setEdgeWeight(a1P, 1000);
        DefaultWeightedEdge a2P = graph.addEdge("A2","P"); 
        graph.setEdgeWeight(a2P, 1000);
        DefaultWeightedEdge a3P = graph.addEdge("A3","P"); 
        graph.setEdgeWeight(a3P, 1000);

        return graph;
    }
    
	//Fonction pour créer les graphes
    public static void printGraphImage(SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> g, String fileName) throws IOException {
        File imgFile = new File(fileName + ".png");
        imgFile.createNewFile();
        JGraphXAdapter<String, DefaultWeightedEdge> graphAdapter = new JGraphXAdapter<>(g);
        mxFastOrganicLayout layout = new mxFastOrganicLayout(graphAdapter);
        layout.setForceConstant(150);
        layout.execute(graphAdapter.getDefaultParent());
        
        BufferedImage image = mxCellRenderer.createBufferedImage(graphAdapter, null, 2, Color.WHITE, true, null);
        ImageIO.write(image, "PNG", imgFile);
    }
    
    public static void main( String[] args ) throws IOException{
        
        System.out.println("------------TP Trader------------");
		//Création du modele du graphe
        SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> graphBase = buildGraphQ3();
        EdmondsKarpMFImpl<String, DefaultWeightedEdge> grapheEdmonds = new EdmondsKarpMFImpl<String, DefaultWeightedEdge>(graphBase,MaximumFlowAlgorithmBase.DEFAULT_EPSILON);

        printGraphImage(graphBase, "grapheB");
		//Création de la représentation graphique du graphe B sous forme d'image
        
        System.out.println("Chemin le plus court allant de S vers P:");
        DijkstraShortestPath<String, DefaultWeightedEdge> dijkstraAlg =
            new DijkstraShortestPath<>(graphBase);
        SingleSourcePaths<String, DefaultWeightedEdge> iPaths = dijkstraAlg.getPaths("S");
        System.out.println(iPaths.getPath("P") + "\n");
        System.out.println(iPaths.getWeight("S"));


        System.out.println("Flot maximum actuel = " + grapheEdmonds.calculateMaximumFlow("S", "P")); // fonction pour calculer le flot maximum
        System.out.println("Flux associes a chaque arete:" + grapheEdmonds.getFlowMap());
        System.out.println("Aretes de la st-coupe de capacite " + grapheEdmonds.calculateMinCut("S", "P") + ": " + grapheEdmonds.getCutEdges());
        System.out.println("Partition cote source de la st-coupe: "+ grapheEdmonds.getSourcePartition());
        System.out.println("Partition cote puits de la st-coupe: "+ grapheEdmonds.getSinkPartition());
    }
}
