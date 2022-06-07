s = 0
m = [ [ 0 for x in range(3) ] for x in range(3) ]

for _ in range(9):
    l, c, v = map(int, input().split())
    m[l][c] = v

s += (m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[2][1] * m[1][0])
s +=  - (m[2][0] * m[1][1] * m[0][2]) - (m[2][1] * m[1][2] * m[0][0]) - (m[2][2] * m[0][1] * m[1][0])
print(s)
