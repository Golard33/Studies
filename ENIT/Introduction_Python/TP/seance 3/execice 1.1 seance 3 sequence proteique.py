# sequence proteique avec la lettre toutes les lettres
proteine = "CVAPGPMCAWCDSTAC"
nombreProteine = 0
for n in proteine:
    if n == 'C':
        nombreProteine = nombreProteine+1
print (nombreProteine,("C"))

for n1 in proteine:
    if n1 == 'M':
        nombreProteine = 0
        nombreProteine = nombreProteine+1
print (nombreProteine,("M"))
   




