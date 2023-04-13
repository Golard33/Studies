# multiple de 7 avec boucle while 
nombre = 0
while nombre < 100:
    print(nombre,)
    nombre = nombre+7

# multiple de 7 avec boucle for
print ()
nombre = 0
for nombre in range(0,101,7):
    print(nombre, end=' ')
    
# factorielle de n
print ()
NombreADemander = int ((input  (" mettre un nombre entier ")))
factorielleN= NombreADemander
for z in range (1,NombreADemander):
   factorielleN = z*factorielleN
print(factorielleN)
    
 