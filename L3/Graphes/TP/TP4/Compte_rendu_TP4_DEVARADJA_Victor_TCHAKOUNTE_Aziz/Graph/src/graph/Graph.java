/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package graph;

// A Java program for Bellman-Ford's single source shortest path 
// algorithm. 

import java.util.*; 
import java.lang.*; 
import java.io.*; 
  
// A class to represent a connected, directed and weighted graph 
class Graph { 
    // A class to represent a weighted edge in graph 
    class Edge { 
        int src, dest, weight; 
        Edge() 
        { 
            src = dest = weight = 0; 
        } 
    }; 
  
    int V, E; 
    Edge edge[]; 
  
    // Creates a graph with V vertices and E edges 
    Graph(int v, int e) 
    { 
        V = v; 
        E = e; 
        edge = new Edge[e]; 
        for (int i = 0; i < e; ++i) 
            edge[i] = new Edge(); 
    } 
  
    // The main function that finds shortest distances from src 
    // to all other vertices using Bellman-Ford algorithm. The 
    // function also detects negative weight cycle 
    void BellmanFord(Graph graph, int src) 
    { 
        int V = graph.V, E = graph.E; 
        int dist[] = new int[V]; 
  
        // Step 1: Initialize distances from src to all other 
        // vertices as INFINITE 
        for (int i = 0; i < V; ++i) 
            dist[i] = Integer.MAX_VALUE; 
        dist[src] = 0; 
  
        // Step 2: Relax all edges |V| - 1 times. A simple 
        // shortest path from src to any other vertex can 
        // have at-most |V| - 1 edges 
        for (int i = 1; i < V; ++i) { 
            for (int j = 0; j < E; ++j) { 
                int u = graph.edge[j].src; 
                int v = graph.edge[j].dest; 
                int weight = graph.edge[j].weight; 
                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) 
                    dist[v] = dist[u] + weight; 
            } 
        } 
  
        // Step 3: check for negative-weight cycles. The above 
        // step guarantees shortest distances if graph doesn't 
        // contain negative weight cycle. If we get a shorter 
        // path, then there is a cycle. 
        for (int j = 0; j < E; ++j) { 
            int u = graph.edge[j].src; 
            int v = graph.edge[j].dest; 
            int weight = graph.edge[j].weight; 
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) { 
                System.out.println("Graph contains negative weight cycle"); 
                return; 
            } 
        } 
        printArr(dist, V); 
    } 
  
    // A utility function used to print the solution 
    void printArr(int dist[], int V) 
    { 
        System.out.println("Distance au sommet de la source"); 
        for (int i = 0; i < V; ++i) 
            System.out.println(i + "\t\t" + dist[i]); 
    } 
  
    // Driver method to test above function 
    public static void main(String[] args) 
    { 
        int V = 5; // Number of vertices in graph 
        int E = 10; // Number of edges in graph 
  
        Graph graph = new Graph(V, E); 
  
        // add edge 0->1  
        graph.edge[0].src = 0; 
        graph.edge[0].dest = 1; 
        graph.edge[0].weight = 10; 
  
        // add edge 0->2 
        graph.edge[1].src = 0; 
        graph.edge[1].dest = 2; 
        graph.edge[1].weight = 23; 
  
        // add edge 0->3  
        graph.edge[2].src = 0; 
        graph.edge[2].dest = 3; 
        graph.edge[2].weight = 65; 
  
        // add edge 0->4
        graph.edge[3].src = 0; 
        graph.edge[3].dest = 4; 
        graph.edge[3].weight = 130; 
  
        // add edge 1->2
        graph.edge[4].src = 1; 
        graph.edge[4].dest = 2; 
        graph.edge[4].weight = 20; 
  
        // add edge 1->3
        graph.edge[5].src = 1; 
        graph.edge[5].dest = 3; 
        graph.edge[5].weight = 62; 
  
        // add edge 1->4
        graph.edge[6].src = 1; 
        graph.edge[6].dest = 4; 
        graph.edge[6].weight = 127; 
  
        // add edge 2->3
        graph.edge[7].src = 2; 
        graph.edge[7].dest = 3; 
        graph.edge[7].weight = 53;
        
        // add edge 2->4
        graph.edge[8].src = 2; 
        graph.edge[8].dest = 4; 
        graph.edge[8].weight = 118; 
        
        // add edge 3->4
        graph.edge[9].src = 3; 
        graph.edge[9].dest = 4; 
        graph.edge[9].weight = 96; 
  
        graph.BellmanFord(graph, 0); 
    } 
}