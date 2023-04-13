package algo.bellman;

/**
 * Un main  pour tester notre algorithme.
 * 
 * @author michaelcourcy
 *
 */
public class Test {
	
	public static void main(String[] args) {
		Tache T1 = new Tache(1,5); //tache no 1 dure 5s
		Tache T2 = new Tache(2,2); //tache no 2 dure 2s
		Tache T3 = new Tache(3,2); //tache no 3 dure 2s
		Tache T4 = new Tache(4,6); //tache no 4 dure 6s
		Tache T5 = new Tache(5,3); //tache no 5 dure 3s
		Tache T6 = new Tache(6,4); //tache no 6 dure 4s
		Tache T7 = new Tache(7,1); //tache no 7 dure 1s
		Tache T8 = new Tache(8,2); //tache no 8 dure 2s
		Tache T9 = new Tache(9,4); //tache no 9 dure 4s
		
		T1.addSuccesseur(T3);
		T1.addSuccesseur(T4);
		T1.addSuccesseur(T5);
		
		T2.addSuccesseur(T4);
		T2.addSuccesseur(T5);
		
		T3.addSuccesseur(T6);
		T3.addSuccesseur(T7);
		
		T4.addSuccesseur(T6);
		T4.addSuccesseur(T8);
		
		T5.addSuccesseur(T7);
		T6.addSuccesseur(T9);
		T7.addSuccesseur(T9);
		
		Tache[] taches = new Tache[]{T1,T2,T3,T4,T5,T6,T7,T8,T9};
		Algorithme bellmanAlgorithme = new Algorithme(taches);
		//on calcul les temps au plus tot pour chaque tache
		System.out.println("=== CALCUL DES CHEMINS AU PLUS TOT ===");
		bellmanAlgorithme.calculeTempsAuPlusTot();
		for (int i = 0; i<taches.length; i++){
			System.out.print("t"+taches[i].getNumero()+"="+taches[i].getTempsAuPlusTot()+ " ");
		}
		//on obtient le chemin critique une fois que se calcul est fait
		System.out.println();
		System.out.println("=== CALCUL DU CHEMIN CRITIQUE ===");
		for (Tache tache : bellmanAlgorithme.calculeCheminCritique()) {
			System.out.print("t"+tache.getNumero() + " ");
		}
		
	}

}
