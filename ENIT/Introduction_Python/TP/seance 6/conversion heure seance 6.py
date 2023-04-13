def conversion (h, m, s):
    Aupif = 3600*h+60*m+s
    return Aupif

h = int ((input  (" mettre juste heure ")))
m = int ((input  (" mettre juste minutes ")))
s = int ((input  (" mettre juste seconde ")))
print (conversion(h, m, s), "secondes")