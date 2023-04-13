# afficher les chiffres 
ch = "A12B2C5XYZ22P1"

nombre = 0
for n in ch:
    if n == '1':
        nombre = nombre+1
        print ('1', end=' ')
    elif  n == '2': # pour le elif il faut aligner avec le if sinon erreur indentation 
            nombre = nombre+1
            print ('2', end=' ')
    elif  n == '5':
                nombre = nombre+1
                print ('5', end=' ')
                
            
            
