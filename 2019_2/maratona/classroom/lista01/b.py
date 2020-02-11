qnt = int(input())
count = 0

for _ in range(qnt):
    count += input().count('1') >= 2

print(count)