/*1*/
select count (codfilm)
from films;

/*2*/
select count (distinct F.codfilm)
from films F, jouent J, realisateurs R, acteurs A
where F.codfilm = J.codfilm
    and J.nact = A.codact
    and F.codreal = R.codreal
    and R.nomreal='Cameron'
    and A.sexe = 'f'
    and extract(year from A.dnaissact)> 1970;

/*3*/
select count (distinct nact)
from films F, jouent J, realisateurs R
where F.codfilm = J.codfilm
    and R.codreal = F.codreal
    and R.nomreal='Cameron';

/*4*/
select max (budget)
from films;

/*5*/
select (titrefilm)
from films
where budget = (select max (budget)
                from films);

/*6*/
select sum (budget)
from films F, realisateurs R
where F.codreal = R.codreal
    and R.nomreal = 'Cameron';

/*utilisation fct et groupe by*/

/*1*/
select count (codfilm), R.codreal, nomreal
from realisateurs R, films F
where R.codreal = F.codreal
group by R.codreal, nomreal;

/*2*/
select count(distinct codact), nomreal,nationreal
from realisateurs R, films F, jouent J
where F.codfilm = J.codfilm
    and R.codreal = F.codreal
    group by R.codreal ,nomreal, nationreal;

/*3*/
select sum( budget), nomreal,nationreal
from realisateurs R, films F
where R.codreal = F.codreal
    and F.categorie = 'science fiction'
    group by R.codreal, nomreal, nationreal;

/*4*/
select count (distinct F.codfilm), nomreal, nationreal, categorie
from realisateurs R, films F
where R.codreal = F.codfilm
    group by R.codreal, nomreal, nationreal, F.categorie

/*HAVING*/

/*1*/
select nomact, prenomact
from acteurs A, jouent J
where J.nact = A.codact
    and A.nationact = 'americaine'
    group by A.codact, nomact, prenomact
    having count( codfilm) > 2;

/*2*/
select R.codreal, nomreal, nationreal
from realisateurs R, films F
where R.codreal = F.codreal
    and F.categorie = 'science fiction'
    group by R.codreal, nomreal, nationreal
    having sum (budget)>1000000;

/*3*/
select nomact, prenomact
from acteurs A, jouent J 
where A.codact = J.nact
    group by nomact, prenomact
    having count(J.codfilm)> (select count(J1.codfilm)
                            from jouent J1,acteurs A1 
                            where A1.codact= J1.nact
                                and nomact='Winslet'
                                and prenomact='Kate');

/*4 requete qui tombe tout le temps "le code et le nom des acteurs qui ont tourné dans le plus de films"*/
select nomact, codact
from acteurs A, jouent J 
where A.codact = J.nact
    group by nomact, codact
    having count(codfilm)> (select max(count(codfilm))
    from jouent J1
    group by J.nact);
