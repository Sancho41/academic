from math import sqrt, ceil

qtd = int(input())

for _ in range(qtd):
  word = input()
  tam = len(word)
  sq = ceil(sqrt(tam))

  word += "*" * ((sq**2) - tam)

  for i in range(sq, 0, -1):
    for j in range(sq):
      indice = (sq ** 2) - (i) - (j * sq)
      if word[indice] != "*":
        print(word[indice], end="")
  print("\n", end="")