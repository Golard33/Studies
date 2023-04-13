k=int(input("distance à parcourir en km:"))
j=int(input("durée de location en jour:"))


print(k),print(type(k))
print(j),print(type(j))
e=40*j+0.15*k
d=50*j+0.1*k
if e<d:
    print("le meilleur choix est la voiture essence qui aura pour coût:",e,"€")
elif e==d:
    print("le prix est de",e,"€ pour les deux types de voiture")
elif e>d:
    print("le meilleur choix est la voiture diesel qui aura pour coût:",d,"€")
    