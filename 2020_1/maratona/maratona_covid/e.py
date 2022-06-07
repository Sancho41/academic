qtd, sem = map(int, input().split())

qtd_sem, con = list(), list()

al = [0 for x in range(sem)]
s = 0
c = 0

for _ in range(qtd):
  a, b = map(int, input().split())
  a = a - 1
  if al[a] == 0:
    al[a] = b
    s += b
  else:
    if b > al[a]:
      al[a] = b
      s += b

print(s,al)