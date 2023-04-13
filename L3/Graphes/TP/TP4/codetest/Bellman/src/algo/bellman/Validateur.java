package algo.bellman;


/**
 * 
 * Etant donné l'aspect fortement typé de notre structure de données
 * nous n'avons pas à vérifier que les données sont incohérente comme par exemple 
 * vérifier l'état d'une matrice.
 * 
 * On se contente donc de vérifier qu'il n'existe pas de cycle.
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
			throw new RuntimeException("Cycle détecté");
		}
		for(Tache tacheSuivante : tacheInitiale.getSuccesseurs()){
			parcoursRecursivement(tacheSuivante,nbTacheParcouru++,nbTacheParcourable);
		}
		
	}
	
	

}
