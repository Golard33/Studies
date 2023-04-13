let nombre;

do {
  nombre = prompt('Entrez un nombre:');
  estInf20 = nombre <= 20;
  estSup10 = nombre >= 10;
  estImpair = nombre % 2 == 1;
  estEntier = parseInt(nombre) == nombre;

} while (!(estImpair && estSup10 && estInf20 && estEntier));

alert(nombre + ' correspond bien aux critères !');