let nombre, erreur;
let estInf20, estSup10, estImpair, estEntier;
let message = '';

do {
  nombre = prompt(message + 'Entrez un entier impair dans [10,20]');
  estInf20 = nombre <= 20;
  estSup10 = nombre >= 10;
  estImpair = nombre % 2 == 1;
  estEntier = parseInt(nombre) == nombre;

  erreur = 0;

  erreur += estInf20 ? 0 : 1;
  erreur += estSup10 ? 0 : 1;
  erreur += estImpair ? 0 : 1;
  erreur += estEntier ? 0 : 1;

  let pas_ni = erreur == 1 ? ' pas ' : ' ni ';

  if (erreur ==0){
  	message = '';
  }
  else {
  	message = erreur + ' erreur' + (erreur==0 ? '' : 's') + ' : ';
  	message += nombre + ' n\'est';
  	message += estEntier ? '' : pas_ni + "entier";
  	message += estInf20 ? '' : pas_ni + "inférieur à 20";
  	message += estSup10 ? '' : pas_ni + "supérieur à 10";
  	message += estImpair ? '' : pas_ni + "impair";
  	message += '! \n';
  }
} while (!(estImpair && estSup10 && estInf20 && estEntier));

alert(nombre + ' correspond bien aux critères !');