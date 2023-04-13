/*AVATAR*/
insert into realisateurs values('CAM54','Cameron','canadienne','16/08/1954',null);
insert into films values('F011', 'Avatar', '16/12/2009', 162, 500000000, 'CAM54');
insert into acteurs values('SAM76', 'Worthington', 'Sam', 'australienne', 'h', '02/08/1976',null);
insert into acteurs values('ZOE78', 'Saldana', 'Zoe', 'américaine', 'f', '19/06/1978',null);
insert into acteurs values('SIG49', 'Weaver', 'Sigourney', 'américaine', 'f', '08/10/1949',null);
insert into acteurs values('STE52', 'Lang', 'Stephen', 'américaine', 'h', '11/07/1952',null);
insert into jouent values('F011', 'SAM76','Jack Sully');
insert into jouent values('F011', 'ZOE78', 'Neytiri');
insert into jouent values('F011', 'SIG49', 'Grace Augustine');
insert into jouent values('F011', 'STE52', 'le colonel Miles Quaritch');

/*ALIENS,LE RETOUR*/
insert into films values('F012', 'aliens,le retour', '08/10/1986', 137, 400000000, 'CAM54');
insert into acteurs values('MIC56', 'Biehn', 'Michael', 'américaine', 'h', '31/07/1956', null);
insert into acteurs values('LAN40', 'Henriksen', 'Lance', 'américaine','h', '05/05/1940', null);
insert into jouent values('F012', 'SIG49', 'Lieutenant Ellen Ripley');
insert into jouent values('F012', 'MIC56', 'Caporal Dwayne Hicks');
insert into jouent values('F012', 'LAN40', 'Evêque');

/*ALIEN LE HUITIEME PASSAGER*/
insert into realisateurs values('RID37','Scott','anglaise','30/11/1937',null);
insert into films values('F013', 'Alien, le huitième passager', '12/09/1979', 116, 300000000, 'RID37');
insert into acteurs values('TOM33', 'Skerritt', 'Tom', 'américaine', 'h', '25/08/1933',null);
insert into jouent values('F013', 'SIG49','Lieutenant Ellen Ripley');
insert into jouent values('F013', 'TOM33', 'Capitaine A.J Dallas');

/*TITANIC*/
insert into films values('F014', 'Titanic', '07/07/1998', 194, 20000000, 'CAM54');
insert into acteurs values('LEO74', 'Di Caprio', 'Leonardo', 'américaine', 'h', '11/11/1974',null);
insert into acteurs values('KAT75', 'Winslet', 'Kate', 'anglaise', 'f', '05/10/1975',null);
insert into jouent values('F014', 'LEO74','Jack Dawson');
insert into jouent values('F011', 'KAT75', 'Rose DeWitt Butaker');

/*LES NOCES REBELLES*/
insert into realisateurs values('SAM65','Mendes','anglaise','01/08/1965',null);
insert into films values('F015', 'Les Noces Rebelles', '21/01/2009', 125, 100000000, 'SAM65');
insert into jouent values('F015', 'LEO74','Franck Wheeler');
insert into jouent values('F015', 'KAT75', 'April Wheeler');

/*TITANIC*/
insert into realisateurs values('JEA00','Negulesco','américaine','26/02/1900', '18/07/1993');
insert into films values('F016', 'Titanic', null, 98, 600000000, 'JEA00');
insert into acteurs values('CLI89', 'Webb', 'Clifton', 'américaine', 'h', '11/11/1889','13/10/1966');
insert into acteurs values('BAR07', 'Stanwyck', 'Barbara', 'américaine', 'f', '16/07/1907', '20/01/1990');
insert into acteurs values('AUD34', 'Dalton', 'Audrey', 'américaine', 'f', '21/01/1934',null);
insert into acteurs values('ROB30', 'Wagner', 'Robert', 'américaine', 'h', '10/02/1930',null);
insert into jouent values('F016', 'CLI89','Richard Ward Sturges');
insert into jouent values('F016', 'BAR07', 'Julia Sturges');
insert into jouent values('F016', 'AUD34', 'Anette Sturges');
insert into jouent values('F016', 'ROB30', 'Gifford Roger');

/* LES PETITS MOUCHOIRS*/



insert into films values('F017', 'Les Petits Mouchoirs', '20/10/2010', 154, 700000000, 'GUI73');
insert into acteurs values('MAR75', 'Cotillard', 'Marion', 'française', 'f', '30/09/1975',null);
insert into acteurs values('JEA72', 'Dujardin', 'Jean', 'française', 'h', '19/06/1972',null);
insert into acteurs values('GIL72', 'Lellouche', 'Gilles', 'française', 'h', '05/07/1972',null);
insert into acteurs values('BEN74', 'Magimel', 'Benoit', 'française', 'h', '11/05/1974',null);
insert into jouent values('F017', 'FRA55','Max Cantara');
insert into jouent values('F017', 'MAR75', 'Marie');
insert into jouent values('F017', 'JEA72', 'Ludo');
insert into jouent values('F017', 'GIL72', 'Eric');
insert into jouent values('F017', 'BEN74', 'Vincent Ribaud');

/*ENSEMBLE C'EST TOUT*/
insert into realisateurs values('CLA34','Berry','française','01/07/1934','12/01/2009');
insert into films values('F018', 'Ensemble c"est tout', '21/03/2007', 97, 800000000, 'CLA34');
insert into acteurs values('AUD76', 'Tautou', 'Audrey', 'française', 'f', '09/08/1976',null);
insert into acteurs values('GUI73', 'Canet', 'Guillaume', 'française', 'h', '10/04/1973',null);
insert into jouent values('F018', 'GUI73','Franck');
insert into jouent values('F018', 'AUD76', 'Camille');

/*LA PLAGE*/
insert into realisateurs values('DAN56','Boyle','anglaise','20/10/1956',null);
insert into films values('F019', 'La Plage', '16/02/2020', 119, 900000000, 'DAN56');
insert into acteurs values('VIR75', 'Ledoyen', 'Virginie', 'française', 'f', '15/11/1975',null);
insert into jouent values('F019', 'LEO74','Richard');
insert into jouent values('F019', 'GUI73', 'Etienne');
insert into jouent values('F019', 'VIR75', 'Françoise');

/*NARCO*/
insert into realisateurs values('GIL72','Lellouche','française','05/07/1972',null);
insert into films values('F020', 'Narco', '01/12/2004', 105, 550000000, 'GIL72');
insert into acteurs values('BEN64', 'Poelvoorde', 'Benoit', 'belge', 'h', '22/09/1964',null);
insert into jouent values('F020', 'GUI73','Gustave Klopp');
insert into jouent values('F020', 'BEN64', 'Lenny Bar');
insert into jouent values('F020', 'GIL72', 'Le jumeau patineur');



