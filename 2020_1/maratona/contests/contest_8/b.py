from math import ceil
a, b, c, d = map(int, input().split())

n = 1
menor = c
while n*n <= c:
  if c % n == 0:
    if n % a == 0 and n % b != 0 and d % n != 0:
      if n < menor:
        menor = n
    q = c / n
    if q % a == 0 and q % b != 0 and d % q != 0:
      if q < menor:
        menor = q
  n += 1

if menor == c:
  print(-1)
else:
  print(int(menor))