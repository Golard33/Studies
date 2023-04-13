package algo.bellman;

import java.util.ArrayList;
import java.util.List;

/**
 * Implemente l'algorithme de Bellman.
 * 
 * On procede d'abord au calcul des temps au plus tot de chaque tache. 
 * t0 = 0; maquer T0
 * Tant qu'il existe des sommets non marqu�s faire
 * 	Soit Tj un sommet non marqu�s dont tous les predecesseurs Tk sont marqu� alors 
 * 		tj = max { tk + ex(Tk) }
 *  	Marquer Tj
 *  FinSoit
 * FinTantQue 
 * 
 * Enfin le chemin critique passe par les taches qui ne peuvent pas partir en 
 * retard sans retarder l'ensemble de l'execution, c'est a dire celle dont le temps 
 * au plus tot est egale au temps au plus tard.
 * 
 * 
 * @author michaelcourcy
 *
 */
public class Algorithme {
	
	/**
	 * La liste des taches utilis� par cette algorithme
	 */
	Tache[] taches;
	
	/**
	 * Renvoie les temps au plus tot en utilisant l'alorithme de Bellman.
	 *  
	 * @param taches
	 * @return
	 */
	public void calculeTempsAuPlusTot(){
		//cree la tache initiale fictive en lui trouvant pour 
		//successeur toutes les taches qui n'ont pas de pr�d�cesseurs
		Tache tacheIntiale = GrapheUtil.construitTInitiale(taches);
		//Cree la tache finale fictive en lui trouvant pour predecesseur
		//toutes les taches qui n'ont pas de successeur
		Tache tacheFinale = GrapheUtil.construitTFinale(taches.length, taches);
		//condition initiale � l'algo on marque T0 et on lui
		//affecte la date au plus tot nulle
		tacheIntiale.setMarque(true);
		tacheIntiale.setTempsAuPlusTot(0);
		//nonMarque est l'index de la premiere tache non marquee
		//trouvee si il vaut -1 c'est qu'on ne peut plus en trouver
		//la boucle s'arrete
		int nonMarque = GrapheUtil.trouveNonMarqueAvecTousPredecesseursMarque(taches);
		while (nonMarque != -1  ){
			//on marque la tache traitee
			taches[nonMarque].setMarque(true);
			//on calcul son temps au plus tot
			int tempsAuPlusTot = GrapheUtil.calculTempsAuPlusTot(taches[nonMarque]);
			//et on le met dans la tache
			taches[nonMarque].setTempsAuPlusTot(tempsAuPlusTot);
			//et on continue avec la prochaine tache non marquee suivante
			nonMarque = GrapheUtil.trouveNonMarqueAvecTousPredecesseursMarque(taches);
		}
		//on finalise avec la derni�re tache
		int tempsAuPlusTotFinal = GrapheUtil.calculTempsAuPlusTot(tacheFinale);
		tacheFinale.setTempsAuPlusTot(tempsAuPlusTotFinal);
	}
	
	/**
	 * Renvoie les taches sur le chemin critique 
	 * cette m�thode ne peut etre appel� qu'apres l'appel
	 * de la m�thode {@link #calculeTempsAuPlusTot()}
	 * @return
	 */
	public List<Tache> calculeCheminCritique() {
		//On intialise le chemin critique
		List<Tache> cheminCritique = new ArrayList<Tache>();
		//on ajoute la tache initiale
		Tache tacheInitale = taches[0].getPredecesseurs().iterator().next();
		cheminCritique.add(tacheInitale);
		Tache tacheSurLeChemin = tacheInitale;
		while ((tacheSurLeChemin = tacheSurLeChemin.getSuccesseurTempsAuPlusTotMax())!=null){
			cheminCritique.add(tacheSurLeChemin);
		}		
		return cheminCritique;
	}
	
	/**
	 * L'algorithme a besoin pour s'executer de connaitre la liste des taches.
	 * @param taches
	 */
	public Algorithme(Tache[] taches){
		this.taches = taches;
	}
	
	
	

}
