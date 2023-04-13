ch=input("chaine:")
p="."
a=len(ch)
e=a-1
b=a*p
print(b)#autant de points que de lettre dans ch
d=ch[0]+((a-2)*p)+ch[e]#1er lettre des points puis dernière lettre
print(d)