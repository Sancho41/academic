# ACCEPTED
# https://onlinejudge.org/external/117/11799.pdf

qnt = int(input())

for x in range(qnt):
    print(f'Case {x + 1}: {max(map(int, input().split()[1:]))}')

