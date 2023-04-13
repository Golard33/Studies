def somme (m, n):
    Calcul = 0
    while m <= n:
        Calcul = Calcul+m
        m = m+1
    return Calcul

m = int ((input  (" rentrer un nombre entier ")))
n = int ((input  (" rentrer un nombre entier plus grand que le précédent")))
print (somme (m,n))
    
    