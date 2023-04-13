/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.alonso.ivan.tp5.personnes;

/**
 * Classe qui décrit une personne. Implémente
 * <code>java.io.Serializable</code> car doit transiter à travers
 * des sockets et des flux.
 */
public class Personne implements java.io.Serializable
{
    /**
     *
     */
    private static final long serialVersionUID = 5L;

    /**
     * Age de la personne
     */ 
    protected int age;

    /**
     * Nom de la personne
     */ 
    protected String nom;

    /**
     * Crèe une nouvelle personne
     * @param a son age
     * @param n son nom
     */
    public Personne(int a, String n)
    {
	age = a;
	nom = n;
    }

    public String toString()
    {
	return ("NOM: "+nom+", AGE: "+age);
    }

    /** 
     * Ne pas oublier de rédéfinir la méthode <code>equals</code> pour
     * que la comparaison de personne fonctionne aussi sur des copies
     * d'objets (comme c'est le cas par principe quand ils transitent
     * à travers le réseau et des flux) 
     */
    public boolean equals(Object obj)
    {
	if (obj == null) return false;
	if (!(obj instanceof Personne)) return false;
	
	Personne p = (Personne)obj;
	return ((age == p.age) && (nom.equals(p.nom)));
    }
}



