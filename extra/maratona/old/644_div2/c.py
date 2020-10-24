for _ in range(int(input())):
  qtd = int(input())
  l = sorted(list(map(int, input().split())))

  b = [x % 2 for x in l]
  s = [1 if abs(l[x] - l[x + 1]) == 1 else 0 for x in range(qtd - 1)]

  b1, b0 = b.count(1), b.count(0)
  s1, s0 = s.count(1)

  if b1 % 2 == 0 and b0 % 2 == 0:
    print("YES")
  elif b1 % 2 and b0 % 2 and s1 > 0:
    print("YES")
  else:
    print("NO")
