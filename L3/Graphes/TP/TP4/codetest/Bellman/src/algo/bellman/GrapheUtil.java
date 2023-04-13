package algo.bellman;

/**
 * 
 * Méthode utilitaire lié aux graphes.
 * @author michaelcourcy
 *
 */
public class GrapheUtil {
	
	/**
	 * Construit la tache T0 celle qui sera le predecesseur de toutes celles
	 * qui n'ont pas de prédécesseurs.
	 * @param taches
	 * @return
	 */
	public static Tache construitTInitiale(Tache[] taches){
		Tache t = new Tache(0,0);
		for(Tache tache : taches){
			if (tache.getPredecesseurs().size()==0){
				t.addSuccesseur(tache);
			}
		}
		return t;
	}
	
	/**
	 * Construit la tache TN+1 celle qui sera le successeurs de toutes celles
	 * qui n'ont pas de successeurs.
	 * @param taches
	 * @return
	 */
	public static Tache construitTFinale(int nbrTotalDeTache, Tache[] taches){
		Tache t = new Tache(nbrTotalDeTache + 1, 0);
		for(Tache tache : taches){
			if (tache.getSuccesseurs().size()==0){
				tache.addSuccesseur(t);
			}
		}
		return t;
	}
	
	/**
	 * Trouve une tache non marque dont tous les predecesseurs sont marqués.
	 * 
	 * @param taches
	 * @return
	 */
	public static int trouveNonMarqueAvecTousPredecesseursMarque(Tache[] taches){
		for(int i = 0; i < taches.length; i++){
			Tache tache = taches[i];
			if (tache.isMarque()){
				continue;
			}
			boolean predecesseursTousMarques = true;
			for(Tache precedent : tache.getPredecesseurs()){
				if (!precedent.isMarque()){
					predecesseursTousMarques = false;
				}
			}
			if (predecesseursTousMarques){
				return i;
			}
		}
		//signifie qu'on a pas pu trouver de non marqué
		return -1;
	}

	/**
	 * Calcul le temps au plus tot d'une tache 
	 * 
	 * Le calcul de ce temps est fourni par l'algorithme de Bellman,
	 * tj = max { tk + ex(Tk) } ou k est l'ensemble des predecesseurs de j
	 * 
	 * @param tache
	 * @return
	 */
	public static int calculTempsAuPlusTot(Tache tache) {
		int max = 0;
		for (Tache precedent : tache.getPredecesseurs()){
			if ((precedent.getTempsAuPlusTot() + precedent.getEx())>max){
				max = precedent.getTempsAuPlusTot() + precedent.getEx(); 
			}
		}
		return max;
	}

}
