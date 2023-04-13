package fr.uppa.tp4;

/**
 * TP4 
 *
 */
import org.jgrapht.*;
import org.jgrapht.graph.*;
import org.jgrapht.alg.interfaces.*;
import org.jgrapht.ext.JGraphXAdapter;
import org.jgrapht.alg.shortestpath.*;

import java.util.Vector;

import javax.imageio.ImageIO;

import com.mxgraph.layout.mxCircleLayout;
import com.mxgraph.layout.mxIGraphLayout;
import com.mxgraph.util.mxCellRenderer;

import java.io.File;
import java.io.IOException;
import java.awt.image.BufferedImage;
import java.awt.Color;

public class App 
{
    public static void main( String[] args ) throws IOException
    {
        // create a JGraphT graph
        SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> g = new SimpleDirectedWeightedGraph<String, DefaultWeightedEdge>(DefaultWeightedEdge.class);

        // add node
        g.addVertex("0");
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= i*2; j++) {
                g.addVertex(i +"."+ j);
            }
        }
        g.addVertex("3.7");
        g.addVertex("3.8");
        
        // add edge
        Vector<Double> P = new Vector<>();
        Vector<Double> E = new Vector<>();
        Vector<Double> R = new Vector<>();

        P.add(365.D);
        P.add(367.D);
        P.add(368.D);
        P.add(371.D);

        E.add(5.D);
        E.add(10.D);
        E.add(25.D);
        E.add(45.D);

        R.add(360.D);
        R.add(357.D);
        R.add(340.D);
        R.add(320.D);

        g.setEdgeWeight(g.addEdge("0", "1.1"), P.get(0) + E.get(0) - R.get(0));
            g.setEdgeWeight(g.addEdge("1.1", "2.1"), P.get(1) + E.get(1) - R.get(1));
                g.setEdgeWeight(g.addEdge("2.1", "3.1"), P.get(2) + E.get(2) - R.get(2));
                    g.setEdgeWeight(g.addEdge("3.1", "4.1"), P.get(3) + E.get(3) - R.get(3));
                g.setEdgeWeight(g.addEdge("2.1", "3.2"), P.get(2) + E.get(2));
                    g.setEdgeWeight(g.addEdge("3.2", "4.2"),E.get(3) - R.get(3));
            g.setEdgeWeight(g.addEdge("1.1", "2.2"), P.get(1) + E.get(1));
                g.setEdgeWeight(g.addEdge("2.2", "3.3"), E.get(2) - R.get(2));
                    g.setEdgeWeight(g.addEdge("3.3", "4.3"), P.get(3) + E.get(3) - R.get(3));
                g.setEdgeWeight(g.addEdge("2.2", "3.4"), E.get(2));
                    g.setEdgeWeight(g.addEdge("3.4", "4.4"), E.get(3) - R.get(3));
        g.setEdgeWeight(g.addEdge("0", "1.2"), P.get(0) + E.get(0));
            g.setEdgeWeight(g.addEdge("1.2", "2.3"), E.get(1) - R.get(1));
                g.setEdgeWeight(g.addEdge("2.3", "3.5"), P.get(2) + E.get(2) - R.get(2));
                    g.setEdgeWeight(g.addEdge("3.5", "4.5"), P.get(3) + E.get(3) - R.get(3));
                g.setEdgeWeight(g.addEdge("2.3", "3.6"), P.get(2) + E.get(2));
                    g.setEdgeWeight(g.addEdge("3.6", "4.6"), E.get(3) - R.get(3));
            g.setEdgeWeight(g.addEdge("1.2", "2.4"), E.get(1));
                g.setEdgeWeight(g.addEdge("2.4", "3.7"), E.get(2) - R.get(2));
                    g.setEdgeWeight(g.addEdge("3.7", "4.7"), P.get(3) + E.get(3) - R.get(3));
                g.setEdgeWeight(g.addEdge("2.4", "3.8"), E.get(2)); 
                    g.setEdgeWeight(g.addEdge("3.8", "4.8"), E.get(3) - R.get(3));

        App.viz(g, "arbre decision A");
        System.out.println("============== Décision A ==============");
        System.out.println(g);

        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> shortest = App.bellman(g);
        for(int i= 1; i<=8; i++ ){
            GraphPath<String, DefaultWeightedEdge> path = shortest.getPath("4."+i);
            System.out.println("path 0 => 4."+ i + ": " +  path.getVertexList());
            System.out.println("weight : " + path.getWeight());
        }

        System.out.println("============== Décision B ==============");
        SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> gB = new SimpleDirectedWeightedGraph<String, DefaultWeightedEdge>(
                DefaultWeightedEdge.class);

        for(int i=0;i<=4; i++){
            gB.addVertex(""+i);
        }
        gB.setEdgeWeight(gB.addEdge("0", "1"), 10.D);
        gB.setEdgeWeight(gB.addEdge("0", "2"), 23.D);
        gB.setEdgeWeight(gB.addEdge("0", "3"), 65.D);
        gB.setEdgeWeight(gB.addEdge("0", "4"), 130.D);

        gB.setEdgeWeight(gB.addEdge("1", "2"), 20.D);
        gB.setEdgeWeight(gB.addEdge("1", "3"), 62.D);
        gB.setEdgeWeight(gB.addEdge("1", "4"), 127.D);

        gB.setEdgeWeight(gB.addEdge("2", "3"), 53.D);
        gB.setEdgeWeight(gB.addEdge("2", "4"), 118.D);

        gB.setEdgeWeight(gB.addEdge("3", "4"), 96.D);

        System.out.println(gB);

        App.viz(gB, "Graphe decision B");

        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> shortestB = App.bellman(gB);

        GraphPath<String, DefaultWeightedEdge> shortestPath = shortestB.getPath("4");
        System.out.println("path 0 => 4.: " + shortestPath.getVertexList());
        System.out.println("weight : " + shortestPath.getWeight());
    }

    public static ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> bellman(SimpleDirectedWeightedGraph<String, DefaultWeightedEdge> g){
        BellmanFordShortestPath<String, DefaultWeightedEdge> bellmanFordShortestPath = new BellmanFordShortestPath<>(g);
        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultWeightedEdge> shortestPath = bellmanFordShortestPath.getPaths("0");
        return(shortestPath);
    }

    public static void viz(Graph<String, DefaultWeightedEdge> g, String name) throws IOException {
        JGraphXAdapter<String, DefaultWeightedEdge> graphAdapter = new JGraphXAdapter<String, DefaultWeightedEdge>(g);
        mxIGraphLayout layout = new mxCircleLayout(graphAdapter);
        layout.execute(graphAdapter.getDefaultParent());

        BufferedImage image = mxCellRenderer.createBufferedImage(graphAdapter, null, 2, Color.WHITE, true, null);

        File imgFile = new File("graph/" + name + ".png");
        imgFile.createNewFile();

        ImageIO.write(image, "PNG", imgFile);
    }
}

