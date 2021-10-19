from math import ceil
qtdbairros, chega, accept = map(int, input().split())

linhas = list()

for i in range(qtdbairros):
  prim, inter, taxa = map(int, input().split())

  a = prim if prim >= chega else ceil((chega - prim) / inter) * inter + prim

  if taxa <= accept:
    linhas.append((a - chega, taxa, i + 1))

if len(linhas):
  print(sorted(linhas)[0][2])
else:
  print(-1)

