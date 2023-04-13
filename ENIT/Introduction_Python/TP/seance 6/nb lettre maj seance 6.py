def Lettre (liste):
    cpt = 0
    liste=(input(" rentrer des lettres "))
    for car in liste:
        if car == car.upper():
            cpt = cpt+1
    return cpt

liste=[]
print(Lettre(liste))