i, h = map(float, input().split())
s = int(input())

m1 = i * h ** 2
m2 = s * h ** 2

print("%.7f" % (m1 - m2))