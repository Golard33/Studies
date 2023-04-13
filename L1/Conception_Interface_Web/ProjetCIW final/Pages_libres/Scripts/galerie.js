
function changeImageM1(url, nom) {
  console.log("DEBUG : changeImageM1 : url = "+url+", nom = "+nom);
  imgTag.src=url;
bTag.innerHTML=nom;

}

function changeImageM2(id_url, id_nom, url, nom) {
  console.log("DEBUG : changeImageM2 : id_url = " + id_url + ", id_nom = " + id_nom
              +", url = " + url + ", nom = " + nom);
    var img = document.getElementById(id_url);
    var id= document.getElementById(id_nom);
    img.src=url ;
    id.innerHTML=nom ;

}

function changeImageM3(url, nom) {
  console.log("DEBUG : changeImageM3 : url ="+url+" , nom = "+nom);
  var el = document.querySelector("#id_image");
  var le = document.querySelector("#id_quoi");
  el.src=url ;
  le.innerHTML=nom ;
}

function CouleurFond() {
    console.log("Test")

    let r = Math.floor(Math.random() * Math.floor(255)) ;
    let g = Math.floor(Math.random() * Math.floor(255)) ;
    let b = Math.floor(Math.random() * Math.floor(255)) ;

    document.body.style.backgroundColor = "rgb("+r+","+g+","+b+")" ;
    document.oncontextmenu = new Function("return false");
}
