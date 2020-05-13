from math import ceil

alphabet = 'abcdefghijklmnopqrstuvwxyz'
for _ in range(int(input())):
  n, a, b = map(int, input().split())
  r = alphabet[:b]
  if b < 26:
    r += r[-1] * (a - b)
  r = r * (ceil(n / len(r)))
  print(r[:n])
  