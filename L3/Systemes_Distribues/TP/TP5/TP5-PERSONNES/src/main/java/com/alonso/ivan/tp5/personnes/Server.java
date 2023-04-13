package com.alonso.ivan.tp5.personnes;

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
        /**
         *
         */
        private static DataManager dm;

        public static void main(String[] args) throws UnknownHostException, SocketException, IOException,
                        ClassNotFoundException, InvalidIdException {

                final int PORT = 45000;
                dm = new DataManager();
                ServerSocket serverSocket = null;
                System.out.println("Port choisi: " + PORT);

                try {

                        // server is listening on port 1234
                        serverSocket = new ServerSocket(PORT);
                        serverSocket.setReuseAddress(true);

                        // running infinite loop for getting
                        // client request
                        while (true) {

                                // socket object to receive incoming client
                                // requests
                                Socket client = serverSocket.accept();

                                // Displaying that new client is connected
                                // to server
                                System.out.println("New client connected " + client.getInetAddress().getHostAddress());

                                // create a new thread object
                                ClientHandler clientThread = new ClientHandler(client);

                                // This thread will handle the client
                                // separately
                                new Thread(clientThread).start();
                        }
                } catch (IOException e) {
                        e.printStackTrace();
                } finally {
                        if (serverSocket != null) {
                                try {
                                        serverSocket.close();
                                } catch (IOException e) {
                                        e.printStackTrace();
                                }
                        }
                }

        }

        private static class ClientHandler implements Runnable {
                private final Socket cSocket;

                // Constructor
                public ClientHandler(Socket socket) {
                        this.cSocket = socket;
                }

                public void run() {

                        // get the outputstream of client
                        ObjectOutputStream output = null;
                        ObjectInputStream input = null;
                        try {
                                output = new ObjectOutputStream(cSocket.getOutputStream());
                                input = new ObjectInputStream(cSocket.getInputStream());
                                // attente les données venant du client
                                String option = (String) input.readObject();
                                System.out.println("Option demandee: " + option);
                                Personne temp;
                                Integer id;
                                switch (option) {
                                        case "add":

                                                temp = (Personne) input.readObject();
                                                id = dm.addPersonne(temp);
                                                System.out.println("Personne " + temp.toString() + " ajoutee.");
                                                output.writeObject(id);
                                                break;

                                        case "sendid":
                                                id = (Integer) input.readObject();
                                                try {
                                                        temp = dm.getPersonne(id);
                                                } catch (InvalidIdException e) {
                                                        temp = new Personne(0,"ID ERR");
                                                }
                                                output.writeObject(temp);
                                                System.out.println("Donnes de " + temp.toString() + "d'ID " + id + " renvoyees.");
                                                break;

                                        case "getid":
                                                temp = (Personne) input.readObject();
                                                id = dm.getId(temp);
                                                output.writeObject(id);
                                                System.out.println("ID " + id + " de " + temp.toString() + " renvoye.");
                                                break;

                                        default:
                                                System.out.println("Option " + option + " non reconnue");
                                                break;
                                }
                        } catch (IOException | ClassNotFoundException e) {
                                e.printStackTrace();
                        } finally {
                                try {
                                        if (output != null) {
                                                output.close();
                                        }
                                        if (input != null) {
                                                input.close();
                                                cSocket.close();
                                        }
                                } catch (IOException e) {
                                        e.printStackTrace();
                                }
                        }
                }
        }
}
