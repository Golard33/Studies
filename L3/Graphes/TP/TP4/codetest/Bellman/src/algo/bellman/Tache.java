package algo.bellman;

import java.util.HashSet;
import java.util.Set;

public class Tache {
	
	/**
	 * Les successeurs de cette tache
	 */
	private Set<Tache> successeurs = new HashSet<Tache>();
	
	/**
	 * Les predecesseurs
	 */
	private Set<Tache> predecesseurs = new HashSet<Tache>();
	
	

	/**
	 * Le noeud a-t-il été marqué durant le parcours ?
	 */
	private boolean marque = false;
	
	/**
	 * le temps d'excecution du noeud.
	 */
	private int ex = 0;
	
	/**
	 * Le numero de la tache.
	 */
	private int numero = 0;
	
	/**
	 * Le temps au plus tot au fur et a mesure qu'il sera connu.S
	 */
	private int tempsAuPlusTot = 0;

	/**
	 * On initialise une tache en définissant son numero et sa durée. 
	 * @param ex
	 */
	public Tache(int numero, int ex) {
		super();
		this.numero = numero;
		this.ex = ex;
	}
	
	/**
	 * Ajoute un successeurs au noeud.
	 * @param noeud
	 * @return
	 */
	public void addSuccesseur(Tache tache){
		successeurs.add(tache);
		tache.getPredecesseurs().add(this);
	}

	public Set<Tache> getSuccesseurs() {
		return successeurs;
	}

	public void setSuccesseurs(Set<Tache> enfants) {
		this.successeurs = enfants;
	}

	public boolean isMarque() {
		return marque;
	}

	public void setMarque(boolean marque) {
		this.marque = marque;
	}

	public int getEx() {
		return ex;
	}

	public void setEx(int ex) {
		this.ex = ex;
	}
	
	public Set<Tache> getPredecesseurs() {
		return predecesseurs;
	}

	public void setPredecesseurs(Set<Tache> predecesseurs) {
		this.predecesseurs = predecesseurs;
	}

	public int getTempsAuPlusTot() {
		return tempsAuPlusTot;
	}

	public void setTempsAuPlusTot(int tempsAuPlusTot) {
		this.tempsAuPlusTot = tempsAuPlusTot;
	}
	
	/**
	 * Retourne le successeur dont le temps au plus tot est le plus élevé.
	 * 
	 * @return
	 */
	public Tache getSuccesseurTempsAuPlusTotMax() {
		Tache tacheLaPlusTardive = null;
		int tempsAuPlusTot = 0;
		for (Tache tache : successeurs) {
			if (tache.getTempsAuPlusTot() >= tempsAuPlusTot) {
				tacheLaPlusTardive = tache;
			}
		}
		return tacheLaPlusTardive;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	

}
