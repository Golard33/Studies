print("programme 1:")
s="Belle marquise"
print(s[0:4])#Bell
print(s[4:0])#
print(s[-2])#s
print(s[4:-1])#e marquis
print(s[4:-3])#e marqu
print(s[4:-12])#
print(s[-12])#l
print((2*s)[13:15])#eB
print(2*s[13:15])#ee


#s[6]="M" ne marche pas car M est un item et s un str
b=s.replace("m","M")
print(b)# b= Belle Marquise
print( )#separation entre les exo
print("programme 2:")
ch=input("chaine")
e=len(ch)
print(ch[1:e])#enlever le premiers et derniers charactère
f=e-1

a=(ch[-1]+ch[1:f]+ch[0])
print(a)#échange 1er et dernier charactère


