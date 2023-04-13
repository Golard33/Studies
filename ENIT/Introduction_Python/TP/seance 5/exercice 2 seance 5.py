#creation par l'utilisateur d'une liste
a="e"
nombre=0
nouveaumot=""
listeEntiere=[]
print ("entrez des valeur pour remplir la liste et stop l'orsqu'elle est termié:")
while nouveaumot != "stop":
    nouvmot=input()
    if nouveaumot != "stop":
        liste.append(nouvmot)
liste.sort()
for i in liste:
    if i!= a:
        for b in liste:
            if i == b:
                nombre = nombre+1
        print (nombre*"*",i)
    nbr=0
    a= i
print (listeEntiere)