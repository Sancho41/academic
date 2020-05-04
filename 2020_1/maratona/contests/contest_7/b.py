for _ in range(int(input())):
  x, sub = map(int, input().split())
  a = list(set(list(map(int, input().split()))))

  if sub < len(a):
    print(-1)
  else:
    a = [*a, *[x for x in range(1, sub + 1) if x not in a][:sub - len(a)]]
    print(len(a) * x) 
    print(*(a * (x)))
