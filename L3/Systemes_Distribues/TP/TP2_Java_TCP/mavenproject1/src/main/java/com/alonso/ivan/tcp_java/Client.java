package com.alonso.ivan.tcp_java;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 *
 * @author Ivan
 */
public class Client {
    
    public static String DEFAULT_MSG = "Hello server, do you get me?";
    
    public static void main(String[] args) throws UnknownHostException, SocketException, IOException, ClassNotFoundException {
        // adresse IP du serveur
        InetAddress adr = InetAddress.getByName(args[0]);
        // construction de flux objets à partir des flux de la socket
        try (// ouverture de connexion avec le serveur sur le port args1
                Socket socket = new Socket(adr, Integer.parseInt(args[1]))) {
            // construction de flux objets à partir des flux de la socket
            ObjectOutputStream output
                    = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream input
                    = new ObjectInputStream(socket.getInputStream());
// écriture d'une chaîne dans le flux de sortie : c'est-à-dire envoi de
// données au serveur
output.writeObject(DEFAULT_MSG);
// attente de réception de données venant du serveur (avec le readObject)
// on sait qu'on attend une chaîne, on peut donc faire un cast directement
String chaine = (String) input.readObject();
System.out.println("Message recu du serveur: " + chaine);
        }
    }
}
