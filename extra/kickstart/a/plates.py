for i in range(int(input())):
  n, k, p = map(int, input().split())

  a = list()
  m = 0

  for j in range(n):
    b = list()
    c = list(map(int, input().split()))
    
    for ci, ca in enumerate(c):
      # if ci > 0:
      #   b.append(ca + b[ci - 1])
      # else:
      b.append(ca)

    a.append(b)

  for s in a:
    print(s)

  

  print(p)
