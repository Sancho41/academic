for _ in range(int(input())):
  for x in range(3):
    for y in range(3):
      a = list(input())
      i = x + y * 3
      b = (int(a[i]) + 1) % 10
      a[i] = b if b != 0 else 1
      print(*a, sep="")
  