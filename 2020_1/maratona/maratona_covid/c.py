a, b = input(), input()
cont = 0
for i, x in enumerate(a):
  cont += x != b[i]
print(cont)