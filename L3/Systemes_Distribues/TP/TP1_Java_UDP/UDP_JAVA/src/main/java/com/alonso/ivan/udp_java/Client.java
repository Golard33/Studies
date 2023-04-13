package com.alonso.ivan.udp_java;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 *
 * @author Ivan
 */
public class Client {

    public static String DEFAULT_MSG = "Hello server, do you get me?";

    public static void main(String[] args) throws UnknownHostException, SocketException, IOException {
        InetAddress adr;
        DatagramPacket packet;
        DatagramSocket socket;
// adr contient l'@IP de la partie serveur
        adr = InetAddress.getByName(args[0]);
// données à envoyer : chaîne de caractères
        byte[] data = DEFAULT_MSG.getBytes();
// création du paquet avec les données et en précisant l'adresse du serveur
// (@IP et port sur lequel il écoute : 7777)
        packet = new DatagramPacket(data, data.length, adr, Integer.parseInt(args[1]));
// création d'une socket, sans la lier à un port particulier
        socket = new DatagramSocket();
// envoi du paquet via la socket
        socket.send(packet);
// attente paquet envoyé sur la socket du client
        socket.receive(packet);
// récupération et affichage de la donnée contenue dans le paquet
        String chaine = new String(packet.getData(), 0,
                packet.getLength());
        System.out.println(" recu du serveur : " + chaine);
        socket.close();
    }
    
}
