/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.alonso.ivan.tp5.personnes;

/**
 * Exception qui est levée quand on demande à récupérer une personne à
 * partir d'un identifiant incorrect (c'est-à-dire quand aucune
 * personne ne possède cet identifiant).  
 */
public class InvalidIdException extends Exception
{
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    /**
     * Crèe une nouvelle exception
     * 
     * @param message le message décrivant l'erreur
     */
    public InvalidIdException(String message)
    { 
	super(message);
    }
}