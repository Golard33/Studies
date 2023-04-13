lst = ["chat", "antilope","chien", "grenouille", "poisson", "libellule", "lion", "girafe","éléphant", "léopard", "coccinelle", "loup"]
cpt=0
lstBis=[]
MotLong = 0
nombre=0
while nombre <=11:
    for car in lst[nombre]: # on parcourt le nombre de caractere dans la liste n  
        if car>="a" and car<="z":
            cpt = cpt+1
            if car == "l":
                lstBis.append(car)
    print (cpt)
    nombre = nombre +1
    if MotLong <= cpt:
        MotLong = cpt
    cpt = 0 # reinitialisé compteur pour compter le nb de car dans mot suivant
    for car in lst:
        if MotLong != len(car):
                    print (car, end=" ")
print(" la longueur du mot le + long est de ", MotLong, "caractères")
print ("les mots qui commencent par l sont:", lstBis)