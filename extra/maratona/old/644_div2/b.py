for _ in range(int(input())):
  qtd = int(input())
  l = sorted(list(map(int, input().split())))
  m = abs(l[0] - l[1])
  for i in range(1, qtd):
    m = min(m, abs(l[i] - l[i -1]))
  print(m)