alter table films drop constraint FK_FILMS_REALISATEURS;
alter table realisateurs modify (CODREAL char(5));
alter table films add categorie varchar(20); question e 

question f
update films set categorie = 'comédie' where CODFILM ='F020';
update films set categorie = 'thriller' where CODFILM ='F019';
update films set categorie = 'drame' where CODFILM ='F015';

question d 
update films set budget = budget*1.1;

question c 
update realisateurs set prenomreal = 'DANNY' where codreal='DAN56';

question b 
alter table realisateurs add prenomreal varchar(20);

question a 
 alter table films modify titrefilm varchar(70);