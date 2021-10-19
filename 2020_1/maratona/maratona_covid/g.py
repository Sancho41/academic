from math import factorial
from fractions import Fraction

tam = int(input())
cam = input()
letters = {}

for x in cam:
  if x not in letters:
    letters[x] = 0
  letters[x] += 1

dif = len(letters)

eq = 1
for x in letters:
  eq *= factorial(letters[x])

a = factorial(dif)
b = factorial(tam) // eq

a = str(Fraction(a, b))

if a == "1":
  print(1, 1)
else:
  print(*a.split("/"))