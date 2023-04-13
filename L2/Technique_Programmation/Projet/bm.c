#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "base.h"
#include "facility.h"

/* Sous programme qui permet de donner la date (base) */
void DateBase(xmlNodePtr cur, xmlDocPtr doc, base_t *base)
{
  char *nptr=NULL;
  xmlNodePtr cur0;
  cur0=cur->xmlChildrenNode;

  while (cur0 != NULL) 
  {
    /*Enregistre le jour*/
    if ((!xmlStrcmp(cur0->name, (const xmlChar *) "day"))) 
    {
    base->day=strtol((char*)(xmlNodeListGetString(doc, cur0->xmlChildrenNode, 1)), &nptr, 10);
    xmlFree((xmlNodeListGetString(doc, cur0->xmlChildrenNode, 1)));
    }
    /*Enregistre le mois */
    if ((!xmlStrcmp(cur0->name, (const xmlChar *) "month"))) 
    {
      base->month=strtol((char*)(xmlNodeListGetString(doc, cur0->xmlChildrenNode, 1)), &nptr, 10);
      xmlFree((xmlNodeListGetString(doc, cur0->xmlChildrenNode, 1)));
    }
    /*Enregistre l'année */
    if ((!xmlStrcmp(cur0->name, (const xmlChar *) "year"))) 
    {
      base->year=strtol((char*)(xmlNodeListGetString(doc, cur0->xmlChildrenNode, 1)), &nptr, 10);
    }
    cur0 = cur0->next;
  }
}

/* Sous programme qui vérifie toutes les conditions pour les facilities*/
void facilities(xmlNodePtr cur, xmlDocPtr doc, base_t *base,  facility_t *facility)
{
  char *nptr= NULL;
  xmlNodePtr cur1,cur2;
  cur1=cur->xmlChildrenNode;

  /* Le programme continue tant que le 1er paramètre n'est pas null et qu'il y a des facilities */
  while(cur1!=NULL)
  {
    facility_t *facility;
    /* Enregistre les noms des facilities */
    if ((!xmlStrcmp(cur1->name, (const xmlChar *) "facility")))
    {
      facility= facility_create();
      facility->name = (char *) xmlGetProp(cur1, (const xmlChar *) "name");
      cur2=cur1->xmlChildrenNode;

      while (cur2!=NULL)
      {
        /* Enregistre le prix des facility*/
        if ((!xmlStrcmp(cur2->name, (const xmlChar *) "cost")))
        {
            facility->cost=strtod((char*) (xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1)), &nptr);
            if (errno!=0 || *nptr != '\0') fprintf(stderr, "strtod failure\n");
          }
          /*Enregistre la zone de facility*/
          if ((!xmlStrcmp(cur2->name, (const xmlChar *) "area"))) 
          {
            facility->area=strtod((char*) (xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1)), &nptr);
            if (errno!=0 || *nptr != '\0') fprintf(stderr, "strtod failure\n");
          }

        cur2=cur2->next;
      }
      base_add_facility(base,facility);
    }
    cur1=cur1->next;
  }
}

/* sous programme qui Vérifie toutes les conditions pour les bases*/
base_t * parseDoc(xmlNodePtr cur, xmlDocPtr doc, base_t *base, facility_t *facility)
{
  
  base = base_create();
  if(base == NULL){
    return NULL;
  }
  facility = facility_create();
  /* Enregistre le nom de  la base*/
  
  base->name = (char*) xmlGetProp (cur,(const xmlChar*) "name");
  cur = cur ->xmlChildrenNode;
  while (cur != NULL)
  {
    if ((!xmlStrcmp(cur->name, (const xmlChar *)"date"))){
			DateBase (cur, doc, base);
    }
    if ((!xmlStrcmp(cur->name, (const xmlChar *)"country"))){
      base->country=(char*)xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
    }
    if ((!xmlStrcmp(cur->name, (const xmlChar *)"facilities"))){
			facilities (cur, doc, base, facility);
    }

    cur=cur->next;
  }

  return base;
}

int main(int argc, char const *argv[]) 
{
  int i;
  float cost;
  char *nptr=NULL;
  base_t *base= NULL;
  facility_t *facility= NULL;
  xmlDocPtr doc;
  xmlNodePtr cur;
  char *string2 = " ", string1[20], *name;

  /*Vérifie qu'il y a bien un seul argument*/
  if(argc != 2)
  {
    fprintf(stderr,"%s: Invalid number of arguments\n",argv[0]);
    return 1;
  }
  doc = xmlParseFile(argv[1]);
  /*Vérifie s'il y a bien un document correct lisible*/
  if(doc == NULL)
  {
  fprintf(stderr, "%s: Unable to parse the document \n",argv[0]);
  return 1;
  }
  cur = xmlDocGetRootElement(doc);
  /*Vérifie s'il y a un document vide*/
  if (cur == NULL) 
  {
    fprintf(stderr,"%s: empty document\n",argv[0]);
    xmlFreeDoc(doc);
  }

  base = parseDoc(cur,doc,base, facility);
  if(base == NULL){
    return 1;
  }

  do 
  {
    fprintf(stdout, "BM> ");
    fgets(string1, 20, stdin);


    string1[strlen(string1)-1] = '\0';

    i=0; /* sépare le string reçu*/
		for(i=0;i<strlen(string1); i++){
			if(string1[i]==' '){
				string1[i]='\0';
        string2= &string1[i+1];

			}
		}

    if (!strcmp(string1,"h")) 
    {
        printf("b: Prints the base\n");
        printf("c: Prints the base country\n");
        printf("d: Prints the base date \n");
        printf("f: Prints the base facilities \n");
        printf("fc COST: Prints the base facilities with the cost equal to COST \n");
        printf("fcge COST: Prints the base facilities with the cost greater than or equal to COST\n");
        printf("fcgt COST: Prints the base facilities with the cost greater than COST \n");
        printf("fcle COST: Prints the base facilities with the cost less than or equal to COST \n");
        printf("fclt COST: Prints the base facilities with the cost less than COST \n");
        printf("fn NAME: Prints the base facilities with the name containing NAME \n");
        printf("h: Prints this help \n");
        printf("n: Prints the base name\n");
        printf("t: Prints the base total cost \n");
        printf("v: Prints the BM version \n");
        printf("q: Quits BM\n");
      }

      else if (!strcmp(string1,"b"))
      {
        base_handle_b(*base);
      }

      else if (!strcmp(string1,"c"))
      {
        base_handle_c(*base);
      }

      else if (!strcmp(string1,"d"))
      {
        base_handle_d(*base);
      }

      else if (!strcmp(string1,"f"))
      {
        base_handle_f(*base);
      }

      else if (!strcmp(string1,"fc"))
      {
        errno=0;
        cost=strtod((char *) string2, &nptr);
        if (errno!=0 || *nptr != '\0') fprintf(stderr, "Invalid parameter for the fc command \n");
        else if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fc command \n");
        else base_handle_fc(*base, cost);
        if((string1[strlen(string2)-1]!='\n')&&(string2[8]!='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
      }

      else if (!strcmp(string1,"fcge"))
      {
        errno=0;
        cost=strtod((char *) string2, &nptr);
        if (errno!=0 || *nptr != '\0') fprintf(stderr, "Invalid parameter for the fcge command \n");
        else if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fcge command \n");
        else base_handle_fcge(*base, cost);
        if((string1[strlen(string2)-1]!='\n')&&(string2[8]!='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
      }

      else if (!strcmp(string1,"fcgt"))
      {
        errno=0;
        cost=strtod((char *) string2, &nptr);
        if (errno!=0 || *nptr != '\0') fprintf(stderr, "Invalid parameter for the fcgt command \n");
        else if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fcgt command \n");
        else base_handle_fcgt(*base, cost);
        if((string1[strlen(string2)-1]!='\n')&&(string2[8]!='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
      }

      else if (!strcmp(string1,"fcle"))
      {
        errno=0;
        cost=strtod((char *) string2, &nptr);
        if (errno!=0 || *nptr != '\0') fprintf(stderr, "Invalid parameter for the fcle command \n");
        else if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fcle command \n");
        else base_handle_fcle(*base, cost);
        if((string1[strlen(string2)-1]!='\n')&&(string2[8]!='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
      }

      else if (!strcmp(string1,"fclt"))
      {
        errno=0;
        cost=strtod((char *) string2, &nptr);
        if (errno!=0 || *nptr != '\0') fprintf(stderr, "Invalid parameter for the fclt command \n");
        else if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fclt command \n");
        else base_handle_fclt(*base, cost);
        if((string1[strlen(string2)-1]!='\n')&&(string2[8]!='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
      }

      else if (!strcmp(string1,"fn"))
      {
        int count;
        name = string2;
        if (strlen(string2)<1) fprintf(stderr, "Missing parameter for the fn command \n");
        else base_handle_fn(*base, name);
        count = strlen(string2);
        if((string1[strlen(string2)-1]!='\n')&&(string2[count] !='\0'))
        {
          fprintf(stderr,"Too many characters for the command\n");
        }
        
      }

      else if (!strcmp(string1,"n"))
      {
        base_handle_n(*base);
      }

      else if (!strcmp(string1,"t"))
      {
        base_handle_t(*base);
      }

      else if (!strcmp(string1,"v")) 
      {
        printf("BM (Base Manager) 20211209\n");
        printf("Copyright (C) 2021 Florian Robin and Lucas Marquez.\n");
        printf("Written by Florian Robin <florian.robin@etud.univ-pau.fr> and Lucas Marquez <lucas.marquez@etud.univ-pau.fr>.\n");
      }

      else if (!strcmp(string1,"q")) 
      {
        printf("Goodbye !\n");
      }

      else
      {
        printf("Invalid command\n");
      }
    }
  while(strcmp(string1, "q"));

  facility_free(facility);
  base_free(base);
  xmlFreeDoc(doc);
  xmlCleanupParser();

  return 0;
}