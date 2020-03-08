cont=0
for A in range (5):
    B= int(input())
    if B % 2!=0:
        cont=cont+1
if (5-cont)%2==0:
    print("NAO")
else:
    print("SIM")