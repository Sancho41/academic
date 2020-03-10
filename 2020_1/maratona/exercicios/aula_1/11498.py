# ACCEPTED
# https://onlinejudge.org/external/114/p11498.pdf

while (True):
    qnt = int(input())
    if not qnt: break
    center = tuple(map(lambda x: - int(x), input().split()))

    for _ in range(qnt):
        house = map(int, input().split())
        x, y = tuple(map(sum, zip(house, center)))

        if not y or not x:
            print('divisa')
        else:
            if y > 0:
                if x > 0: print('NE')
                else: print('NO')
            else:
                if x > 0: print('SE')
                else: print('SO')