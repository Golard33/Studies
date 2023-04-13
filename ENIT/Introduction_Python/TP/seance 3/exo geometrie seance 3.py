Nombre = int ((input  (" mettre un nombre entier ")))
Nombre1= Nombre*Nombre
for n1 in range (0,Nombre1,1):
    if n1 <=Nombre1:
        print ('*', end=' ')
        n1=n1+1
    if n1 == Nombre:
        Nombre = Nombre+Nombre
        print ()
        