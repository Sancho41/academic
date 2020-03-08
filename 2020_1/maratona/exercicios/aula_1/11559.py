'''
    WA 
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
'''
while True:
    try:

        n, b, h, w = map(int, input().split())
        for _ in range(h):
            p = int(input())
            a = map(int, input().split())

            total = p * n
            if total > b: continue
            c = list(filter(lambda x: x >= n, a))
            if c:
                break
        if c: print(total)
        else: print('stay home')


    except: break