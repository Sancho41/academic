# https://onlinejudge.org/external/117/11727.pdf
for case in range(int(input())):
    a, b, c = map(int, input().split())

    print(f'Case {case + 1}: ', end='')
    
    if a > b and a > c:
        if b > c: print(b)
        else: print(c)
    elif b > a and b > c:
        if a > c: print(a)
        else: print(c)
    else:
        if a > b: print(a)
        else: print(b)
