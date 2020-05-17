from math import sqrt
s = sqrt
a, b, c, d = map(int, input().split())


ans = -1
for i in range(a, s(c), a):
  if (c % int(s(i)) == 0):
    if(not (i % a) and (i % b) and not (c % i) and (d % i)):
      ans = i
      break

print(ans)
