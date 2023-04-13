"use strict";

let intervalID = null; // identifiant pour window.setInterval et clearInterval

// Initialisation de l'application une fois le document chargé
window.addEventListener("load", function() {

  afficheHeure();

  majHeure();  // lance la mise à jour régulière de l'heure

  abonnements(); // abonnenement aux événements

});

function abonnements() {

  // la checkbox réagit à l'événement "click"
  let checkboxElt=document.getElementById("checkPause");
  checkboxElt.addEventListener("change", stopHeure);
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
  console.log(date.toString());

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
