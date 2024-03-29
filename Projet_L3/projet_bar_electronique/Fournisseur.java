import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.Naming;
import java.rmi.RemoteException;

import java.util.Vector;

public class Fournisseur extends UnicastRemoteObject implements IBiere {

    protected Vector<Biere> blondes;

    protected Vector<Biere> ambrees;


    /**
     * Retourne la liste des bieres blondes
     */
    public Vector<Biere> listeBlondes() throws RemoteException {
	return blondes;
    }

    /**
     * Retourne la liste des bieres ambrees
     */
    public Vector<Biere> listeAmbrees() throws RemoteException {
	return ambrees;
    }

    /**
     * Retourne un fut de biere de la biere dont on passe le nom en parametre.
     * Si cette bier n'existe pas, retounre <code>null</code>
     */
    public Biere acheterBiere(String nom) throws RemoteException {
	Vector<Biere> toutes = new Vector<Biere>();
	Biere b;
	toutes.addAll(ambrees);
	toutes.addAll(blondes);

	for (int i=0; i<toutes.size(); i++) {
	    b = (Biere)toutes.elementAt(i);
	    if (b.getNom().equals(nom)) return b;
	}
	return null;
    }



    protected void remplirCatalogue() {
	blondes = new Vector<Biere>();
	ambrees = new Vector<Biere>();

	blondes.add(new Biere("Paix Dieu", Biere.BLONDE, 10));
	blondes.add(new Biere("Goudale", Biere.BLONDE, 7));
	blondes.add(new Biere("Delirium Tremens", Biere.BLONDE, 8));

	ambrees.add(new Biere("Kwak", Biere.AMBREE, 8));
	ambrees.add(new Biere("Mousse Ta Shuc", Biere.AMBREE, 6));
	ambrees.add(new Biere("Queue de Charrue", Biere.AMBREE, 5));
    }
	 

    public Fournisseur() throws RemoteException {

	super();
	remplirCatalogue();
    }


    public static void main(String argv[]) {

	Fournisseur fournisseur = null;
        try {
            System.setProperty("java.rmi.server.hostname","10.1.13.145");
            fournisseur = new Fournisseur();
	    Naming.rebind("DedeLaChope", fournisseur);

        } catch (Exception ex) {
	    System.err.println("Impossible de lancer le fournisseur");
            System.err.println(ex);
	}
    }
}
