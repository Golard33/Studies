package com.alonso.ivan.tp5.personnes;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

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

    public static void main(String[] args)
            throws UnknownHostException, SocketException, IOException, ClassNotFoundException {
        final int PORT = 45000;
        final String HOST = "localhost";
        // adresse IP du serveur
        InetAddress adr = InetAddress.getByName(HOST);
        // construction de flux objets à partir des flux de la socket
        // ouverture de connexion avec le serveur sur le port args1

        try (Socket socket = new Socket(adr, PORT);) {
            // construction de flux objets à partir des flux de la socket

            ObjectOutputStream output = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream input = new ObjectInputStream(socket.getInputStream());

            // écriture d'une chaîne dans le flux de sortie : c'est-à-dire envoi de
            // données au serveur
            Scanner sc = new Scanner(System.in);
            System.out.println("Veuillez choisir l'option: (add/sendid/getid)");
            String option = sc.next();
            

            Personne temp;
            Integer age;
            Integer id;
            String name;
            switch (option) {
                case "add":
                    System.out.print("Enter age of the person to add: ");
                    age = sc.nextInt();
                    System.out.print("\nEnter name of the person to add: ");
                    name = sc.next();
                    temp = new Personne(age, name);

                    output.writeObject(new String(option));
                    output.writeObject(temp);

                    id = (Integer) input.readObject();
                    System.out.println(temp.toString() + " ID: " + id);
                    break;

                case "sendid":
                    System.out.print("\nEnter the id of the person you want to know more about: ");
                    id = sc.nextInt();

                    output.writeObject(new String(option));
                    output.writeObject(id);

                    temp = (Personne) input.readObject();
                    System.out.println("Concordance dans la base de donnees pour l'ID :" + id + "\n" + temp.toString());
                    break;
                case "getid":
                    System.out.print("Enter age of the person you want to know the ID of: ");
                    age = sc.nextInt();
                    System.out.print("\nEnter name of the person you want to know the ID of: ");
                    name = sc.next();
                    temp = new Personne(age, name);

                    output.writeObject(new String(option));
                    output.writeObject(new Personne(age, name));

                    id = (Integer) input.readObject();
                    System.out.println("Concordance dans la base de donnees pour la personne" + temp.toString() + "  ID " + id);
                    break;

                default:
                    System.out.println("Option " + option + " non reconnue");
                    break;
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
