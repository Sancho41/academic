for j in range(int(input())):
  a = int(input())
  s = 0
  cont = 0
  for i in range(1, a + 1, 2):
    s += (i * i - ((i-2)* (i-2))) * cont 
    cont += 1
  print(s)

