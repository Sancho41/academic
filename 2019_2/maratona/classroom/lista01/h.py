while(True):
    l = list(map(lambda x: int(x) - 1, input().split()))
    tam_key, key = l[0] + 1, l[1:]

    if not tam_key:
        break

    msg = input()
    tam_msg = len(msg)

    blank = 0
    if tam_msg % tam_key != 0:
        blank = tam_key - (tam_msg % tam_key)

    print("'", end="")
    for i in range(tam_msg + blank):
        div, mod = divmod(i, tam_key)
        b = div * tam_key + key[mod]
        print(msg[b] if b < tam_msg else " ", end="")
    print("'")
    