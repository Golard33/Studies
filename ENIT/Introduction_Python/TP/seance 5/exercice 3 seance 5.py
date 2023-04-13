L = ["Admirable","Limpide", "Genial", "Ouvrage", "Rigoureux",
"Inventif", "Technique", "Harassant", "Merveilleux",
"Elegant"]
for e in L:
    print (e[0], end="")
    
L = ["Harassant", "Merveilleux",
"Limpide", "Admirable", "Algorithme", "Elegant", "Ouvrage",
"Inventif", "Genial", "Technique", "Rigoureux"]
cpt=0
rangmot=-1
rgmot = -1
for e in L:
    rgmot = rgmot + 1 
    if len(e) == len (L)-1:
        for lettre in e:
            for mot in L:
                rangmot = rangmot +1
                if rangmot != rgmot:
    if len (e) == cpt - 1:
        print ("le mot est ", e)
        break
    break

        
                
        