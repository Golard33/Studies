package algo.bellman;


/**
 * 
 * Etant donn� l'aspect fortement typ� de notre structure de donn�es
 * nous n'avons pas � v�rifier que les donn�es sont incoh�rente comme par exemple 
 * v�rifier l'�tat d'une matrice.
 * 
 * On se contente donc de v�rifier qu'il n'existe pas de cycle.
 * 
 * @author michaelcourcy
 *
 */
public class Validateur {
	
	public void validate(Tache[] taches) {
		Tache tacheInitiale = GrapheUtil.construitTInitiale(taches);
		parcoursRecursivement(tacheInitiale,1,taches.length + 1);		
	}

	private void parcoursRecursivement(Tache tacheInitiale,int nbTacheParcouru, int nbTacheParcourable) {
		if (nbTacheParcouru > nbTacheParcourable){
			throw new RuntimeException("Cycle d�tect�");
		}
		for(Tache tacheSuivante : tacheInitiale.getSuccesseurs()){
			parcoursRecursivement(tacheSuivante,nbTacheParcouru++,nbTacheParcourable);
		}
		
	}
	
	

}
