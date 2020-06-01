for _ in range(int(input())):
  x, y = map(int, input().split())
  print(max(min(x, y) * 2, max(x, y)) ** 2)