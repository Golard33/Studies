package com.alonso.ivan.tcp_java;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 *
 * @author Ivan
 */
public class Server {

    public static String DEFAULT_MSG = "Hello client, loud and clear!";

    public static void main(String[] args) throws UnknownHostException, SocketException, IOException, ClassNotFoundException {
        // serveur positionne sa socket d'écoute sur le port local args0
        ServerSocket serverSocket = new ServerSocket(Integer.parseInt(args[0]));
        try (// se met en attente de connexion de la part d'un client distant
                Socket socket = serverSocket.accept()) {
            // connexion acceptée : récupère les flux objets pour communiquer
// avec le client qui vient de se connecter
ObjectOutputStream output
        = new ObjectOutputStream(socket.getOutputStream());
ObjectInputStream input
        = new ObjectInputStream(socket.getInputStream());
// attente les données venant du client
String chaine = (String) input.readObject();
// affiche les coordonnées du client qui vient de se connecter
System.out.println("Message recu: " + chaine + "\n de la part de " + socket.getInetAddress() + ":" + socket.getPort());

// envoi d'une réponse au client
output.writeObject(DEFAULT_MSG);
        }
    }
}
