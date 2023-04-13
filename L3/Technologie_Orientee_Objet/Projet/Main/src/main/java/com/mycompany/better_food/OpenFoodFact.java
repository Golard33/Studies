/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.better_food;

import javax.json.stream.JsonParsingException;


/**
 *
 * @author flori
 */
public class OpenFoodFact {
    
    public static String Nutriscore(String bar_code) throws java.net.MalformedURLException, java.io.IOException {

    String nutriscoreGrade = "";
    java.net.URL url = new java.net.URL("https://world.openfoodfacts.org/api/v0/product/" + bar_code + ".json"); // Subscription to the service is mandatory to get a license key!
    java.net.URLConnection connection = (java.net.URLConnection) url.openConnection();
    if (connection != null) {
        javax.json.stream.JsonParserFactory factory = javax.json.Json.createParserFactory(null);
        // Effective connection with the service:
        javax.json.stream.JsonParser parser = factory.createParser(connection.getInputStream());
         while (parser.hasNext()) {
            javax.json.stream.JsonParser.Event event = parser.next();
            if (event == javax.json.stream.JsonParser.Event.KEY_NAME && parser.getString().equals("nutriscore_grade")) {
                while (parser.hasNext()) {
                    event = parser.next();
                    if (event == javax.json.stream.JsonParser.Event.VALUE_STRING) {
                        nutriscoreGrade = parser.getValue().toString();
                        break;
                    }
                }
            }
            
        }

        } try {
             url.openConnection();
        } catch(java.net.MalformedURLException mfue){
            System.err.println(java.net.MalformedURLException.class.getSimpleName() + ": " + mfue.getMessage());
        }
        try {
            javax.json.stream.JsonParserFactory factory = javax.json.Json.createParserFactory(null);
        } catch (JsonParsingException pe) {
           System.err.println(pe.getMessage());
                    
        }
        return nutriscoreGrade;

    }
}
    