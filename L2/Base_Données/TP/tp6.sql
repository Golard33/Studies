/*requete numéro 1*/
select * 
from films
where budget > 1000000 ;

/*requete numero 2*/
select *
from acteurs
where   nationact = 'américaine'
         and sexe = 'f';

/*requete numero 3*/
select nomact, prenomact
from acteurs
where   nationact = 'française'
        or nationact = 'belge' ;

/*requete numero 4*/
select titrefilm
from films
where codreal = 'CAM54';

/*requete numéro 5*/
select nomact, prenomact
from acteurs, films, jouent
where   (nationact = 'française'
        or nationact = 'américaine')
        and titrefilm = 'La Plage'
        and films.codfilm = jouent.codfilm 
        and acteurs.codact = jouent.nact;

/*requete numéro 6*/
select A2.nomact, A2.prenomact, A2.dnaissact
from acteurs A1, acteurs A2
where   extract (year from A1.dnaissact) = extract (year from A2.dnaissact)
        and A1.nomact = 'Dujardin'
        and A1.prenomact = 'Jean';

/*requete numéro 7*/
select  R1.codreal, nomreal ,nationreal ,dnaissreal,ddecreal
from realisateurs R1, films F1
where F1.titrefilm = 'Ensemble c"est tout'
        and ddecreal < F1.datesortie;

/*requete numero 8 */
select distinct F1.titrefilm, R1.nomreal
from films F1, jouent J1, realisateurs R1
where F1.codfilm = J1.codfilm
        and F1.codreal = R1.codreal
        and J1.nompers = 'Lieutenant Ellen Ripley';

/*requete numero 9 */
select nomreal
from realisateurs
where codreal in (select codreal
                  from realisateurs
                        minus
                  select codreal
                  from acteurs A1, jouent J1, films F1
                  where J1.nact = A1.codact
                        and J1.codfilm = F1.codfilm
                        and A1.nationact = 'americaine');
/*ou*/

select R1.nomreal
from realisateurs R1
where codreal not in (select codreal
                      from films F1, jouent J1, acteurs A1
                      where F1.codfilm = J1.codfilm
                                and J1.nact = A1.codact
                                and nationact = 'americaine');

/* requete numero 10*/
select distinct R1.codreal,nomreal,prenomreal
from realisateurs R1, acteurs A1, jouent J1, films F1
where A1.nationact != 'americaine'
        and J1.nact = A1.codact
        and J1.codfilm = F1.codfilm
        and F1.codreal = R1.codreal;

/*requete numero 11*/
select F1.titrefilm, datesortie, budget
from films F1, realisateurs R1
where F1.codreal = R1 codreal
        and F1.datesortie - R1.dnaissreal <40*365;

/*requete numero 1 td6*/
select distinct nationact
from acteurs A1;

/*requete numero 2 td6*/
select R1.nomreal, R1.prenomreal
from realisateurs R1
where R1.nationreal = 'americaine'
        minus
select R2.nomreal, R2.prenomreal
from realisateurs R2, acteurs A1, jouent J1, films F1
where J1.nact = A1.codact
        and J1.codfilm = F1.codfilm
        and R1.codreal = R2.codreal
        and A1.nationact = 'française'
        and R1.nationreal = 'americaine';