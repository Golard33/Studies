
#x = 321               exo 1 
#y = 321.0
#z = 1
#print (type (x//20))      
#print (x//20)

#exo 2 valeurs et types expressions
#x=321
#x1 = "321"
#print (type(x))
#print (type(x1))
#print (x1*3)
#print (3*x1)
#print (x1+3)
#print (3+x1)

# exo 3 calcul de prix ttc
PrixTTC = 0
Prix = int ((input  (" insérer prix ")))
ValeurTaux= int ((input (" insérer TVA (sans %)  : ")))
Prix = Prix + (Prix*(ValeurTaux/100))
print (Prix , ("euros"))