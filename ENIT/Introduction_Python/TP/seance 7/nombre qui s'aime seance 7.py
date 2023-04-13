def narcissique (nombre):
    n=0
    a = str(nombre)
    for i in a:
        n= n+int(i)**len (a)
    if n == nombre:
        m = True
    else:
        m = False
    return m
nombre = int (input("entrer un nombre narcissique",))
m= narcissique (nombre)
print (m)
if m == True:
    print ("le nombre s'aime beaucoup")
else:
    print ("le nombre se déteste")
    
a = int (input("entrer un nombre entier",))
b = int (input("entre un nombre plus grand que a stp",))

def ABCDE (a,b):
    for nombre in range (a,b+1):
        m= narcissique (nombre)
        if m == True:
            print (nombre)
ABCDE (a,b)
print (m, ",",end="")