import math 
import time 
def prime(n):
    if n <= 1:
      return False
    max_div = math.floor(math.sqrt(n)) 
    for i in range(2, 1 + max_div): 
        if n % i == 0: 
            return i
    return False

for _ in range(int(input())):
  n, k = map(int, input().split())
  if k >= n:
    print(1)
  else:
    a = prime(n)
    if not a:
      print(n)
    else:
      b = min(a, n // a)
      if b > k:
        print(n)
      else:
        print(b)

 