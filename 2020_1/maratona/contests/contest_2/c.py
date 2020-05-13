'''
d p i
0 0 0: 1
0 0 1: 1
0 1 0: 0
0 1 1: 0
1 0 0: 1
1 0 1: 0
1 1 0: 1
1 1 1: 0

d/pi 00 01 10 11
0    1  1  0  0
1    1  0  1  0

(not d * not p) + (not p * not i) + (d * p * not i)
'''
d, p, i = map(int, input().split())
if (not d and not p) or (not p and not i) or (d and p and not i):
    print('VALIDO')
else:
    print('INVALIDO')