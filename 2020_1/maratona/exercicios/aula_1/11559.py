# ACCEPTED
# https://onlinejudge.org/external/115/11559.pdf

while True:
    try:

        n, b, h, w = map(int, input().split())
        m = False
        for _ in range(h):
            p = int(input())
            a = map(int, input().split())

            total = p * n
            if total > b: continue
            c = list(filter(lambda x: x >= n, a))
            if c:
                m = total if (total < m or not m) else m
                
        if m: print(m)
        else: print('stay home')

    except: break