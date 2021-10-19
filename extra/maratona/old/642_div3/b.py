for _ in range(int(input())):
  _, k = map(int, input().split())
  a = sorted(map(int, input().split()))
  b = sorted(map(int, input().split()))
  s = sum(a)

  for i in range(k):
    if (b[-1] > a[i]):
      s += b.pop() - a[i]
  
  print(s)
