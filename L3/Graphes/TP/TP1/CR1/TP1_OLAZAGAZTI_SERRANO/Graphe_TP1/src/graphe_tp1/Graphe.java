package graphe_tp1;

import org.graphstream.graph.implementations.*;
import org.graphstream.graph.*;

import java.util.*; 
import java.util.LinkedList; 
import org.graphstream.ui.view.Viewer;

// Classe graphe permettant de représenter un graphe par son nombre de sommets et sa liste d'adjacence. La classe fournit des methodes pour afficher le 
class Graphe 
{ 
	private int S; // Nombre de sommets 
	private LinkedList<Integer> adj[]; //Liste d'adjacence

	//Constructeur du graphe 
	Graphe(int s) 
	{ 
		S = s; 
		adj = new LinkedList[s]; 
		for (int i=0; i<s; ++i) 
			adj[i] = new LinkedList(); 
	} 

	//Fonction qui ajoute un arc au graphe 
	void ajoutArc(int s, int w) { adj[s].add(w); } 

	// Fonction qui affiche le parcours en profondeur a partir d'un sommet
	void affichPPS(int s,boolean estVisite[]) 
	{ 
		// On affiche le noeud et on le marque comme deja visite 
		estVisite[s] = true; 
                switch(s){
                        case 0 : //A
                             System.out.print("A, ");
                             break;

                        case 1 : //B
                             System.out.print("B, ");
                             break;

                        case 2 : //C
                             System.out.print("C, ");
                             break;

                        case 3 : //D
                             System.out.print("D, ");
                             break;

                        case 4 : //E
                             System.out.print("E, ");
                             break;

                        case 5 : //F
                             System.out.print("F, ");
                             break;

                        case 6 : //G
                             System.out.print("G, ");
                             break;

                        case 7 : //H
                             System.out.print("H, ");
                             break;
                }
		int n; 

		// Appel recursif s'il faut continuer 
		Iterator<Integer> i =adj[s].iterator(); 
		while (i.hasNext()) 
		{ 
			n = i.next(); 
			if (!estVisite[n]) 
				affichPPS(n,estVisite); 
		} 
	} 

	// Fonction qui retourne le graphe dual du graphe donne. 
	Graphe getDual() 
	{ 
		Graphe g = new Graphe(S);
                //Parcours de tous les sommets du graphe
		for (int s = 0; s < S; s++) 
		{ 
			// Parcours de la liste d'adjacence correspondant au sommet
			Iterator<Integer> i =adj[s].listIterator(); 
			while(i.hasNext()) 
				g.adj[i.next()].add(s); 
		} 
		return g; 
	} 

        //Fonction récursive qui permet de ranger dans un stack les sommets du graphe s'ils ont pas déjà été rangés
	void rangerSommets(int sommet, boolean estVisite[], Stack stack) 
	{ 
		
		estVisite[sommet] = true; 
                
		Iterator<Integer> i = adj[sommet].iterator(); 
		while (i.hasNext()) 
		{ 
			int n = i.next(); 
			if(!estVisite[n]) 
				rangerSommets(n, estVisite, stack); 
		} 

		// On recupere tous les sommets
		stack.push(new Integer(sommet)); 
	} 

	// Fonction qui trouve et qui affiche les composantes fortement connexes du graphe.
	void afficherCFC() 
	{ 
		Stack stack = new Stack(); 

		// Initialise les visites de sommets à faux, pour le premier parcours en profondeur 
		boolean estVisite[] = new boolean[S]; 
		for(int i = 0; i < S; i++) 
			estVisite[i] = false; 

		// Rangement des sommets en fonction de leur date de fin
		for (int i = 0; i < S; i++) 
			if (estVisite[i] == false) 
				rangerSommets(i, estVisite, stack); 

		// Creation du graphe dual
		Graphe grDual = getDual(); 
                grDual.toGraphStream("DUAL");
		// Reinitialise les visites de sommets à faux, pour le deuxieme parcours en profondeur 
		for (int i = 0; i < S; i++) 
			estVisite[i] = false; 

		// Parcours de tous les sommets rangés
		while (stack.empty() == false) 
		{ 
			// Recuperation d'un sommet
			int s = (int)stack.pop(); 

			// Affiche la composante fortement connexe correspondant au sommet récuperé
			if (estVisite[s] == false) 
			{ 
                                System.out.print("{ "); 
				grDual.affichPPS(s, estVisite); 
				System.out.println("\b\b } ;"); 
			} 
		} 
	}
        
        //Fonction qui affiche dans une fenêtre le graphe. Les nœuds sont vert clair si c’est un graphe dual.
        void toGraphStream(String nom ){
            Graph graph = new SingleGraph(nom);
            for(int iParcours=0; iParcours<this.S; iParcours++){
                switch(iParcours){
                    case 0 : //A
                         Node A =graph.addNode("A");
                         break;
                         
                    case 1 : //B
                         Node B =graph.addNode("B");
                         break;
                         
                    case 2 : //C
                         Node C =graph.addNode("C");
                         break;
                         
                    case 3 : //D
                         Node D =graph.addNode("D");
                         break;
                         
                    case 4 : //E
                         Node E =graph.addNode("E");
                         break;
                         
                    case 5 : //F
                         Node F =graph.addNode("F");
                         break;
                         
                    case 6 : //G
                         Node G =graph.addNode("G");
                         break;
                         
                    case 7 : //H
                         Node H =graph.addNode("H");
                         break;
                         
                }
            }
            for(int iParcours=0; iParcours<this.S; iParcours++){
                String extremiteInitiale="";
                switch(iParcours){
                        case 0 : //A
                             extremiteInitiale="A";
                             break;

                        case 1 : //B
                             extremiteInitiale="B";
                             break;

                        case 2 : //C
                             extremiteInitiale="C";
                             break;

                        case 3 : //D
                             extremiteInitiale="D";
                             break;

                        case 4 : //E
                             extremiteInitiale="E";
                             break;

                        case 5 : //F
                             extremiteInitiale="F";
                             break;

                        case 6 : //G
                             extremiteInitiale="G";
                             break;

                        case 7 : //H
                             extremiteInitiale="H";
                             break;

                    }
                
                int jParcours=0;
                String extremiteFinale="";
                Iterator<Integer> j =adj[iParcours].listIterator(); 
                while(j.hasNext()){
                    switch(j.next()){
                        case 0 : //A
                             extremiteFinale="A";
                             break;

                        case 1 : //B
                             extremiteFinale="B";
                             break;

                        case 2 : //C
                             extremiteFinale="C";
                             break;

                        case 3 : //D
                             extremiteFinale="D";
                             break;

                        case 4 : //E
                             extremiteFinale="E";
                             break;

                        case 5 : //F
                             extremiteFinale="F";
                             break;

                        case 6 : //G
                             extremiteFinale="G";
                             break;

                        case 7 : //H
                             extremiteFinale="H";
                             break;

                    }
                    String nomEdge=extremiteInitiale+extremiteFinale;
                    graph.addEdge(nomEdge, extremiteInitiale, extremiteFinale,true); 
                }  
            }
            for(Node u : graph.getEachNode()) {
                        u.addAttribute("label",u.getId());
                }
            
            if (nom=="DUAL"){
                graph.addAttribute("ui.stylesheet",""
                    + "edge { fill-color: grey; size: 2px; arrow-size: 20px, 8px;} "
                    + "node { size: 25px; fill-color: #bdffba; stroke-mode: plain; stroke-color:black; stroke-width:1px;}");
            } else{
                graph.addAttribute("ui.stylesheet",""
                        + "edge { fill-color: grey; size: 2px; arrow-size: 20px, 8px;} "
                        + "node { size: 25px; fill-color: orange; stroke-mode: plain; stroke-color:black; stroke-width:1px;}");
            }
            Viewer viewer = graph.display();
            if (nom=="DUAL")
                viewer.setCloseFramePolicy(Viewer.CloseFramePolicy.HIDE_ONLY);
        }

        
	// MAIN
	public static void main(String args[]) 
	{ 
                System.setProperty("org.graphstream.ui.renderer", "org.graphstream.ui.j2dviewer.J2DGraphRenderer");
		// Creation du graphe
		Graphe g = new Graphe(8); 
		g.ajoutArc(0, 1); 
		g.ajoutArc(0, 4); 
		g.ajoutArc(1, 2); 
                g.ajoutArc(1, 4);
                g.ajoutArc(2, 5); 
                g.ajoutArc(2, 6); 
                g.ajoutArc(3, 6); 
                g.ajoutArc(3, 7); 
                g.ajoutArc(4, 5); 
                g.ajoutArc(5, 1); 
                g.ajoutArc(6, 5);
                g.ajoutArc(7, 6); 




		System.out.println("Voici les composantes fortement connexes dans G :"); 
		g.afficherCFC(); 
                
                g.toGraphStream("GRAPH");
                
	} 
}
