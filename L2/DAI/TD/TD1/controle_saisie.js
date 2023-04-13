

let nombre;
let estEntier, estImpair, estSup10, estInf20;

do {
  nombre = prompt('Entrez un entier impair compris entre 10 et 20');
  estEntier = parseInt(nombre) == nombre;
  estImpair = nombre % 2 == 1;
  estSup10 = nombre >= 10;
  estInf20 = nombre <= 20;

} while (!(estEntier && estImpair && estSup10 && estInf20));

alert(nombre + ' correspond bien aux critères !');