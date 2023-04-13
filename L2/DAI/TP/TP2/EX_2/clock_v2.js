"use strict";

let intervalID = null; // identifiant pour window.setInterval

/**
* Initialisation de l'application une fois le document chargé
*/
window.addEventListener("load", function() {

  afficheHeure();
  majHeure(); // lance la mise à jour régulière de l'heure
  remplirSelectsHeuresMinutes(); // ajouter la liste déroulante des heures et minutes
  abonnements(); // abonnenement aux événements
});

/**
 * Abonnements aux événements
 */
function abonnements() {

  // la checkbox "checkPause" réagit à l'événement "click"
  let checkboxElt=document.getElementById("checkPause");
  checkboxElt.addEventListener("change", stopHeure);

  let alarmeElts = document.getElementsByClassName("alarme");
  abonnerAlarmeElt(alarmeElts[0]);

  let ajouterElt = document.getElementsByClassName("ajouter")[0];
  ajouterElt.addEventListener("click", ajouterAlarme);
}

function stopHeure() {
  let checkboxElt=document.getElementById("checkPause");
  if (checkboxElt.checked){
    console.log("Pause de l'horloge");
    clearInterval(intervalID);
  }
  else {
    console.log("Reprise de l'horloge");
    majHeure();
  }
}

function addZero(number) {
  if (number<10){
    number="0"+number;
  }
  return (number);
}

function afficheHeure() {
  let date = new Date();
  //console.log(date.toString());

  let h = addZero(date.getHours());
  let m = addZero(date.getMinutes());
  let s = addZero(date.getSeconds());
  let hhmmss = h+":"+m+":"+s;
  let heureElt = document.getElementById("heure");
  heureElt.textContent = hhmmss;
}

function majHeure() {
  intervalID = window.setInterval(afficheHeure,1000);
}

/**
 * Remplir le select des Heures et des minutes
 */
function remplirSelectsHeuresMinutes() {
  // récupérer les deux selects de alarme
  let alarmeElts = document.getElementsByClassName("alarme");
  let selectElts = alarmeElts[0].getElementsByTagName("select");

  // ajouter les heures 0 à 23 au premier select
  ajouterOptionsAuSelect(23, selectElts[0]);

  // ajouter les minutes 0 à 59 au deuxième select
  ajouterOptionsAuSelect(59, selectElts[1]);
}

/**
 * ajoute des options numériques à un champ select
 * @param  {number} borneMax    ajoute les options 0 à borneMax
 * @param  {Object} selectElt   element select concerné
 */
function ajouterOptionsAuSelect(borneMax, selectElt) {

  // création des noeuds option
  let optionElt = null;

  for (var iCompteur = 0; iCompteur <= borneMax; iCompteur++) {
  optionElt = document.createElement('option');
  optionElt.value = iCompteur;
  optionElt.textContent = addZero(iCompteur);
  selectElt.appendChild(optionElt);
  }
}

/**
 * abonnerAlarmeElt - Réagir aux événements sur la checkbox et
 *                    le bouton "Enlever alarme" d'une alarme
 * @param {Object} alarmElt un élément div.alarme et son contenu
 *
 */
function abonnerAlarmeElt(alarmElt) {

  let checkboxElt = alarmElt.getElementsByTagName("input")[0];
  checkboxElt.addEventListener("click", enclencherAlarme);

  let boutonElt = alarmElt.getElementsByTagName("button")[0];
  boutonElt.addEventListener("click", enleverAlarme);
}

function enclencherAlarme(evenement) {

  let checkboxElt = document.getElementById("checkAlActive");
  let checked = checkboxElt.checked;

  console.log("Alarme enclenchée ? " + checked);

  let parentNode = evenement.target.parentNode;
  let selectElts = parentNode.getElementsByTagName("select");
  let selectHeures = selectElts[0];
  let selectMinutes = selectElts[1];

  if (checked) {
    let heures = selectHeures.options[selectHeures.selectedIndex].text;
    let minutes = selectMinutes.options[selectMinutes.selectedIndex].text;
    console.log("Heures : " + heures);
    console.log("Minutes : " + minutes);

    let dateAlarme = new Date();

    if ((heures<dateAlarme.getHours())||((heures==dateAlarme.getHours()) && (minutes<=dateAlarme.getMinutes()))) {
      dateAlarme.setDate(dateAlarme.getDate()+1);
    }
    dateAlarme.setHours(heures);
    dateAlarme.setMinutes(minutes);
    dateAlarme.setSeconds(0);
    console.log("Alarme réglée à : " + dateAlarme.toString());

    let dateCourante = new Date();
    let tempsRestant = dateAlarme - dateCourante;
    let timeoutId = setTimeout(function() {
      alert("BOUM ! BADABOUM !"); //TODO
    }, tempsRestant);

    // range le timeoutId dans la value de checkbox
    checkboxElt.value = timeoutId;

    // grise les champs
    selectHeures.disabled = true;
    selectMinutes.disabled = true;

  } else {
    // Annule l'enclenchement de l'alarme !
    clearTimeout(checkboxElt.value);

    // dégrise les champs
    selectHeures.disabled = false;
    selectMinutes.disabled = false;
  }
}

/**
 * enleverAlarme - Enlève le div.alarme contenant le bouton cliqué
 *                 mais seulement s'il reste plusieurs alarmes
 *
 * @param {Object} evenement l'événement qui a appelé cette fonction
 *
 */
function enleverAlarme(evenement) {

  let noeudDiv = evenement.target.parentNode;

  console.log("On veut supprimer ce ", noeudDiv);
  console.log("Il y a " + noeudDiv.parentNode.children.length + " alarme(s)");
  if (noeudDiv.parentNode.children.length== 1) {
    console.log("Impossible d'enlever toutes les alarmes, il doit en rester toujours au moins une");
  }

  else {
    // désamorce l'éventuelle alarme
    document.getElementById("checkAlActive").checked=false;
    enclencherAlarme(evenement);


    // enleve ce div.alarme
    noeudDiv.remove();
  }
}

function ajouterAlarme() {
  console.log("Ajoute une nouvelle alarme");

  // Clone le premier fils de #alarmes
  let alarmesElt = document.getElementById("alarmes");
  let nouvelleAlarmeElt = alarmesElt.children[0].cloneNode();
  nouvelleAlarmeElt.innerHTML = document.getElementById("alarme");


  // dégrise les éléments éventuellement grisés
  // TODO

  alarmesElt.appendChild(nouvelleAlarmeElt);
  console.log("TEST");
  abonnerAlarmeElt(nouvelleAlarmeElt);
}
