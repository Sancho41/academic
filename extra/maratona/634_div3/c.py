for _ in range(int(input())):
  n = [0 for x in range(int(input()))]
  d = 0
  for x in input().split():
    i = int(x) - 1
    n[i] += 1
    d += n[i] == 1

  if (max(n) < d):
    print(max(n))
  elif (d == max(n)):
    print(d - 1)
  else:
    print(d)

'''
1 1 2 4 0 0 0

0 0 1 3 0 0 0



'''