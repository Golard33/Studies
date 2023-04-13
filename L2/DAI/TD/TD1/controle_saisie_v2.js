

let nombre;
let estEntier, estImpair, estSup10, estInf20;
let message = '';

do {
  nombre = prompt('Entrez un entier impair dans [10;20]');
  estEntier = parseInt(nombre) == nombre;
  estImpair = nombre % 2 == 1;
  estSup10 = nombre >= 10;
  estInf20 = nombre <= 20;

  let nbErr = 0;
  estEntier += true ? nbErr+1 :
  estImpair += true ? nbErr+1 :
  estSup10 += true ? nbErr+1 :
  estInf20 += true ? nbErr+1;

} while (!(estEntier && estImpair && estSup10 && estInf20));

alert(nombre + ' est bien un entier impair dans [10,20] !');