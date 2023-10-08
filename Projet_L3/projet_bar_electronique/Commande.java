import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;
import java.util.*;

public class Commande {


    // Se connecter au registre RMI
private static Registry registry;
// Chercher l'objet distant par son nom "DedeLaChope"
private static IBiere fournisseur;
// Récupérer la liste des bières disponibles
private static Vector<Biere> blondes;
private static Vector<Biere> ambrees;

// Créer une HashMap pour stocker les raccourcis de bières
private static HashMap<Integer, Biere> beerShortcuts = new HashMap<>();

static {
    try {
        // Localiser le registre RMI sur la machine distante avec l'adresse IP "10.1.13.137"
        registry = LocateRegistry.getRegistry("10.1.13.145");
        // Rechercher l'objet distant avec le nom "DedeLaChope"
        fournisseur = (IBiere) registry.lookup("DedeLaChope");
        // Obtenir la liste des bières blondes et ambrées disponibles
        blondes = fournisseur.listeBlondes();
        ambrees = fournisseur.listeAmbrees();
    } catch (RemoteException e) {
        // Gérer RemoteException si la connexion à la machine distante échoue
        System.err.println("Echec de connexion RMI:");
        e.printStackTrace();
    } catch (Exception e) {
        // Gérer toute autre exception qui pourrait se produire
        System.err.println("Une erreur est apparue:");
        e.printStackTrace();
    }
}

// Menu pour commander
public static void menutap() {
    System.out.println("Veuillez choisir une option de 1 à 2:");
    System.out.println("1. Commander un fut de bière :");
    // Afficher la liste des bières disponibles
    System.out.println("2. Consulter les différentes bières :");
}

// Afficher les bières blondes disponibles
public static void displayblonde() {
    System.out.println("Blondes disponibles:");
    int index = 1;
    for (Biere blonde : blondes) {
        System.out.println(index + ". " + blonde.getNom() + " (" + blonde.getDegre() + "%)");
        beerShortcuts.put(index, blonde);
        index++;
    }
}

// Afficher les bières ambrées disponibles
public static void displayambree() {
    System.out.println("\nAmbrees disponibles:");
    int index = 1;
    for (Biere ambree : ambrees) {
        System.out.println(index + ". " + ambree.getNom() + " (" + ambree.getDegre() + "%)");
        beerShortcuts.put(index, ambree);
        index++;
    }
}

    public static void main(String[] args) {
    // Créer un objet Scanner pour lire l'entrée depuis la console
    Scanner scanner = new Scanner(System.in);

    // Vérifier que l'argument du port UDP est bien spécifié lors du lancement du programme
    if (args.length != 1) {
        System.err.println("Usage: java Commande <UDP port>");
        System.exit(1);
    }

    // Récupérer le numéro de port UDP à partir des arguments de ligne de commande
    int udpPort= Integer.parseInt(args[0]);

    try {
        // Créer une socket pour recevoir les messages depuis ControleV.c
        DatagramSocket socket = new DatagramSocket(udpPort);
        byte[] buffer = new byte[1024];

        while (true) {
            // Recevoir un datagramme UDP
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);

            // Convertir le contenu du datagramme en chaîne de caractères
            String received = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Recu: " + received);

            // Si le message reçu indique qu'une tireuse est vide, demander à l'utilisateur quelle bière acheter
            if (received.startsWith("Empty tap: ")) {
                // Récupérer le numéro de la tireuse vide
                int emptyTap = Integer.parseInt(received.substring("Empty tap: ".length()));

                // Récupérer la bière à acheter en fonction de la tireuse vide
                Biere beerToBuy = beerShortcuts.get(emptyTap);

                // Boucle pour demander à l'utilisateur de choisir une bière tant qu'une valeur correcte n'est pas entrée
                int var=0;
                int trans;
                String choice;
                int choiceint;
                String choix;
                int choixint;
                int choixval;
                while(var==0){
                    do{
                        menutap(); // Afficher le menu pour choisir une bière
                        choice = scanner.nextLine();
                    }while(!choice.equals("1")&& !choice.equals("2"));
                    choiceint=Integer.parseInt(choice);

                    switch(choiceint){
                        case 1:
                            // Si la tireuse vide est la première, afficher le menu des bières blondes et demander à l'utilisateur de choisir
                            if (emptyTap==1) {
                                System.out.println("\nVeuillez choisir une option de 1 à 3:");
                                displayblonde(); // Afficher le menu des bières blondes
                                
                                // Boucle pour demander à l'utilisateur de choisir une option tant qu'une valeur correcte n'est pas entrée
                                do{
                                    System.out.println("Rentrer une valeur correcte 1,2 ou 3");
                                    choix = scanner.nextLine();
                                }while(!choix.equals("1") && !choix.equals("2") && !choix.equals("3"));
                                choixint = Integer.parseInt(choix);
                                beerToBuy = beerShortcuts.get(choixint);
                                var=1;
                            }else if(emptyTap==2){
                                // Si la tireuse vide est la deuxième, afficher le menu des bières ambrées et demander à l'utilisateur de choisir
                                System.out.println("\nVeuillez choisir une option de 1 à 3:");
                                displayambree(); // Afficher le menu des bières ambrées
                                    do{
                                        System.out.println("Rentrer une valeur correcte 1,2 ou 3");
                                        choix = scanner.nextLine();
                                    }while(!choix.equals("1")&& !choix.equals("2") && !choix.equals("3"));
                                    choixint = Integer.parseInt(choix);
                                    beerToBuy = beerShortcuts.get(choixint);
                                    var=1;
                                }
                                break;
                    
                            case 2:
                                displayblonde();
                                displayambree();
                                System.out.println("\n");

                                break;
                    
                            default:
                                System.out.println("\nSaisie invalide. Veuillez entrer un nombre entier entre 1 et 2.");
                                menutap();
                        }
                    }
                    
                    if (beerToBuy != null) {
                        Biere boughtBeer = fournisseur.acheterBiere(beerToBuy.getNom());
                        if (boughtBeer != null) {
                            System.out.println("\nCorrectement acheté : " + boughtBeer.getNom() + " (" + boughtBeer.getDegre() + "%)");
                
                            int beer_quantity = 5000; // Définir la quantité du fut acheté
                            String message = "Keg purchased: " + emptyTap + ", quantity: " + beer_quantity + ", beer: " + boughtBeer.getNom();
                            byte[] msgBuffer = message.getBytes();
                
                            InetAddress address = packet.getAddress();
                            int port = packet.getPort();
                            packet = new DatagramPacket(msgBuffer, msgBuffer.length, address, port);
                            socket.send(packet);
                
                        } else {
                            System.out.println("\nErreur d'achat " + beerToBuy.getNom() + ". Pas disponible.");
                        }
                    } else {
                        System.out.println("\nInvalid selection. Please try again.");
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("An error occurred while processing the UDP connection:");
            e.printStackTrace();
        }
    }
}