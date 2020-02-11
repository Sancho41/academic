qnt, c = int(input()), list(map(int, input().split()))
left,  right = 0, qnt - 1
sereja, dima, serejaTurn = 0, 0, True

while left <= right:
    valor = c[left] if c[left] > c[right] else c[right]
    if c[left] > c[right]: left += 1
    else: right -= 1

    sereja += valor if serejaTurn else 0
    dima += valor if not serejaTurn else 0
    serejaTurn = not serejaTurn

print(sereja, dima)    