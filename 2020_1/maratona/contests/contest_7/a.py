a = [ 2 ** (x + 1) for x in range(30) ]

for _ in range(int(input())):
  b = int(input())

  n, m = 0, 0
  c = b // 2
  l, r = 0, b - 1

  n = a[r]
  r -= 1
  c -= 1

  while c != 0:
    n += a[l]
    l += 1
    c -= 1
  
  while l <= r:
    m += a[l]
    l += 1

  print(abs(n - m))
