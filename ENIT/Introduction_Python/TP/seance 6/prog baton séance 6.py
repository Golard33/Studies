def histo(liste):
    for baton in liste:
        print ( int(baton)*"*")
def envoiLaListe ():
    
    liste=[]
    a=17
    while a!=1:
        liste.append(input("mettre un nombre entier stp"))
        print("encore ?, mettre zéro")
        a=int(input("fin, mettre 1",))
envoiLaListe()
histo(liste)