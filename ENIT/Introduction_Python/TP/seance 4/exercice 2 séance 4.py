L = [0,1,2,3,5,13,21,34,55]
#L.append (89)
#print (L) # ajoute 89 a la liste

#L.insert (4,8)
#print("apres insert", L) # afficher 8 entre 3 et 5

Lp = []
Li = []
for e in L:
    if e%2==0:
        Lp.append(e)
    else:
        Li.append(e)
print (Lp[:], Li[:]) # imprime liste paire et impaire

addition = 0
for e in L:         # parcours la liste et ajoute le nb au nb précédent
    addition = addition+e
print (addition)

Nombre = int ((input  (" mettre un nombre entier entre 0-100 ")))
for e in L:
    if e==Nombre:
        print ("ce nombre est present dans la liste")
        break
    print ("ce nombre n'est pas dans la liste, c'est dommage") # ça fonctionne 
    break


    