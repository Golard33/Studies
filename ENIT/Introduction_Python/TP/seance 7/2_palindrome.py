def palind (mot):
    i=0
    a=False
    while i <= len(mot)-1:
        if mot[i]==mot[len(mot)-1-i]:
            i=i+1
    if i == int(len(mot)):
        a=True
    if a == True:
        print ("le mot est un palindrome")
    else:
        print ("le mot n'est pas un palindrome")
    
mot = input("entre un mot",)
palind(mot)
pharse= input("retre une phrase",)
def retirespace (phrase):
    mot=""
    for i in phrase:
        if upper.i==i:
            mot=mot+i
        elif z<=i<=a:
            mot= mot + upper.i
    print(mot)