lista=[]
for a in range (5):
    nome,pre=input().split() 
    if pre=="1":
        lista.append(nome) 
print(*lista)