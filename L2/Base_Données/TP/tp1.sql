create table realisateurs (
    codreal varchar (6),
    nomreal varchar (20),
    nationreal varchar (20),
    dnaissreal date,
    ddecreal date,
    constraint pk_realisateurs primary key (codreal),
    constraint ck_realisateurs_dnaissreal check(dnaissreal < ddecreal)
);

create table films (
    codfilm char (4),
    titrefilm varchar (50),
    datesortie date,
    duree number,
    budget number,
    codreal varchar (6),
    constraint pk_films primary key (codfilm),
    constraint fk_films_realisateurs foreign key (codreal) references realisateurs,
    constraint ck_films_duree check (duree >= 0),
    constraint ck_films_budget check (budget >= 0)
);

create table acteurs (
    codact char (5),
    nomact varchar (20),
    prenomact varchar (20),
    nationact varchar (20),
    sexe char (1),
    dnaissact date,
    ddecact date,
    constraint pk_acteurs primary key (codact),
    constraint ck_acteurs_dnaissact check(dnaissact < ddecact),
    constraint ck_acteurs_sexe check(sexe in ('h','f'))
);

create table jouent (
    codfilm char (4),
    nact char (5),
    nompers varchar (30),
    constraint pk_jouent primary key (codfilm, nact),
    constraint fk_jouent_films foreign key (codfilm) references films, 
    constraint fk_jouent_acteurs foreign key (nact) references acteurs
);
