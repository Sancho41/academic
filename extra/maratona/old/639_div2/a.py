for _ in range(int(input())):
  n, m = map(int, input().split())
  a = ((n - 1) * m) + ((m - 1) * n)
  if (n * m) < a:
    print('NO')
  else:
    print('YES')