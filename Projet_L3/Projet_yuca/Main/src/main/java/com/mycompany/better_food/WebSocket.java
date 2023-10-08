/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.better_food;
import java.io.IOException;
import javax.websocket.DeploymentException;
import org.glassfish.tyrus.server.Server;
/**
 *
 * @author vpalacio001
 */
public class WebSocket {
    
    //Necessaire uniquement à l'université 
     static 
    {
        System.setProperty("http.proxyHost", "cache.univ-pau.fr");
        System.setProperty("http.proxyPort", "3128");
    }
    
    /* Danger: 'My_ServerEndpoint' constructor must be accessed by the WebSockets server. Don't forget 'static'! */
   @javax.websocket.server.ServerEndpoint(value = "/WebSocket")
    public static class Server_Endpoint {

        @javax.websocket.OnOpen
        public void onOpen(javax.websocket.Session session, javax.websocket.EndpointConfig ec) throws java.io.IOException {
            System.out.println("OnOpen... " + ec.getUserProperties().get("Author"));
        }

        @javax.websocket.OnMessage
        public void onMessage(javax.websocket.Session session, String message) throws IOException {
            System.out.println("Message from client: " + message);
            System.out.println("opendFoodFacts"+ OpenFoodFact.Nutriscore(message));
            session.getBasicRemote().sendText(OpenFoodFact.Nutriscore(message));
        }

        @javax.websocket.OnClose
        public void onClose(javax.websocket.Session session, javax.websocket.CloseReason close_reason) {
            System.out.println("Closing of websocket : " + close_reason.getReasonPhrase());
        }

        @javax.websocket.OnError
        public void onError(javax.websocket.Session session, Throwable throwable) {
            System.out.println("Error from websocket : " + throwable.getMessage());
        }

        
    } 
   
public static void main(String[] args) throws IOException 
{
   
    java.util.Map<String, Object> user_properties = new java.util.HashMap();
    user_properties.put("Author", "Palacio_Robin");

   Server server = new Server("localhost", 2006, "/PalacioRobin", user_properties, Server_Endpoint.class);
    try {
        server.start();
        System.out.println("\n*** Please press any key to stop the server... ***\n");
// The Web page (JavaScript client) is launched from Java:                                  
        java.awt.Desktop.getDesktop().browse(java.nio.file.FileSystems.getDefault().getPath("SelfieS.ts/index.html").toUri());
        java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        reader.readLine();
        System.out.println("\n@@@\n" + "@@@\n");
    } catch (IOException | DeploymentException e) {
        e.printStackTrace();
    } finally {
        server.stop();
    }
  }
}

