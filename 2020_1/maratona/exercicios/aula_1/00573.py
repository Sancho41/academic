# WIP
# https://onlinejudge.org/external/5/573.pdf

while True:
    h, u, d, f = map(int, input().split())
    if not h: break

    days = 1
    climbed = 0

    while True:
        print(days, climbed, u, climbed + u, climbed + u - d, u) 
        climbed += u

        if climbed > h:
            break
        climbed -= d
        if climbed < 0:
            climbed = 0
            break
    

        days += 1
        u -= u * (f / 100)
        if u < 0:
            u = 0

    if (climbed >= h):
        print('success', end=' ')
    print(days)