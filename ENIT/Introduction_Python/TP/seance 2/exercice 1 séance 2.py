# belle marquise
s = "Belle marquise"
print (s[0:4], s[-2], s[4:-1], s[4:-3], s[4:-3], s[4:-12], s[-12])
print ((2*s)[13:15]) # le programme fait un déplacement de 13 caractères puis il refait un déplacement de 15 caractères

print(2*s[13:15]) # sans parenthèses le programme effectue 2 fois la meme action donc il lit 2 fois le même e

# print (s[6]='M') ne fonctionne pas car la syntaxe est incorrect
print (s[6].upper())
       