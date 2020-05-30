def verifica_razao(n):
  r = n[1] / n[0]
  for x in range(1, len(n)):
    if n[x] / n[x - 1] != r:
      return False
  return True

def divide(n):
  a = list()
  for x in range(1, len(n)):
    a.append(n[x] / n[x-1])
  return a


qtd = int(input())
n = list(map(int, input().split())) 


achou = False
for i in range(4):
  if not verifica_razao(n):
    n = divide(n)
  else:
    achou = True
    break

if achou:
  print(f"Os elementos formam uma PG de ordem {i + 1}.")
else:
  print("Os elementos nao formam uma PG.")