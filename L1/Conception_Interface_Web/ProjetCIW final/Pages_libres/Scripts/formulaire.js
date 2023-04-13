function same(){
  if (document.getElementById("f_idem").checked) {

    document.getElementById("f_Adresse1").value= document.getElementById("f_Adresse").value;
        document.getElementById("f_Adresse1").readOnly=true;

    document.getElementById("f_codepostale1").value= document.getElementById("f_codepostale").value;
        document.getElementById("f_codepostale1").readOnly=true;

    document.getElementById("f_ville1").value= document.getElementById("f_ville").value;
      document.getElementById("f_ville1").readOnly=true;
  }
  else {
  document.getElementById("f_Adresse1").readOnly=false;
  document.getElementById("f_codepostale1").readOnly=false;
  document.getElementById("f_ville1").readOnly=false;

    document.getElementById("f_Adresse1").value="";
    document.getElementById("f_codepostale1").value="";
    document.getElementById("f_ville1").value="";
  }
}
