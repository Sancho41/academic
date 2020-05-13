from functools import reduce
a = list(set(input().split()))
try:
  b = input().split()
  print(reduce(lambda x, y: x + (y not in b), a, 0))
except:
  print(len(a))