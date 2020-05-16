import bisect



for _ in range(int(input())):
  n = int(input())
  queue = list()
  a = [ 0 for _ in range(n) ]

  bisect.insort(queue, (n, [0, n -1]))

  for i in range(1, n + 1):
    cur = queue.pop()[1]
    index = (cur[0] + cur[1]) // 2
    a[index] = i

    if cur[0] < index:
      bisect.insort(queue, ((index - cur[0] + 0.5), [cur[0], index - 1]))
    
    if index < cur[1]:
      bisect.insort(queue, ((cur[1] - index), [index + 1, cur[1]]))
    print(index, ";", a, cur, queue)
  
  # print(*a)
      