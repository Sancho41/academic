qnt, _ = map(int, input().split())
div = list(map(int, input().split()))

div.append(qnt)
div.insert(0, 0)

new_list = list()

for i, n in enumerate(div):
    for x in range(i, len(div)):
        a = div[x] - n
        if a != 0 and a not in new_list:
            new_list.append(div[x] - n)

print(*sorted(new_list))

