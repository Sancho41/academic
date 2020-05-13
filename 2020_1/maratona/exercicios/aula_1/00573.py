# ACCEPTED
# https://onlinejudge.org/external/5/573.pdf

while True:
    h, u, d, f = map(int, input().split())
    if not h: break

    days = 1
    climbed = 0
    factor = u*f/100

    while True:

        climbed += u
        if (u > 0): u -= factor

        if climbed > h: 
            print("success on day", days)
            break 
        
        climbed -= d

        if climbed < 0:
            print("failure on day", days)
            break
        
        days += 1
