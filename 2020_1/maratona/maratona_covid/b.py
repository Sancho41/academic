from math import sqrt
c, v = map(int, input().split())
def get_indexes(x, y, tam):
  pos = {
    "t": y > 0,
    "b":  y < lado - 1,
    "l": x > 0,
    "r": x < lado - 1
  }
  pos["tl"] = pos["t"] and pos["l"]
  pos["tr"] = pos["t"] and pos["r"]
  pos["bl"] = pos["b"] and pos["l"]
  pos["br"] = pos["b"] and pos["r"]

  ids = list()

  if pos["t"]:
    ids.append([x, y - 1])

  if pos["b"]:
    ids.append([x, y + 1])
    
  if pos["l"]:
    ids.append([x - 1, y])
    
  if pos["r"]:
    ids.append([x + 1, y])
    
  if pos["tl"]:
    ids.append([x - 1, y - 1])
    
  if pos["tr"]:
    ids.append([x + 1 , y - 1])
    
  if pos["bl"]:
    ids.append([x -1 , y + 1])
    
  if pos["br"]:
    ids.append([x + 1, y + 1])

  return ids

lado = int(sqrt(c))

cinema = [[0 for _ in range(lado)] for _ in range(lado)]

for _ in range(v):
  x, y = map(lambda x: int(x) - 1, input().split())
  cinema[x][y] = 1
  indexes = get_indexes(x, y, lado)
  for x1, y1 in indexes:
    cinema[x1][y1] = 1

m = int(input())

for _ in range(m):
  x, y = map(lambda x: int(x) - 1, input().split())

  if cinema[x][y] == 1:
    print('Nao')
    continue
  
  cinema[x][y] = 1
  indexes = get_indexes(x, y, lado)
  for x1, y1 in indexes:
    cinema[x1][y1] = 1
  print('Sim')

