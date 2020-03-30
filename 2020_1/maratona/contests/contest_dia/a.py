a = int(input())
for _ in range(a):
    a, b = map(int, input().split())
    r = b - (a % b)
    print(r if r != b else 0)

