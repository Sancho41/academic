# WA - ( Não encontrei o corner case )
# https://onlinejudge.org/external/115/11507.pdf
def change(x):
    signal, letter = x
    number = dict({
        'x': 1,
        'y': 2,
        'z': 3
    })
    number = number.get(letter, 0)
    return number if signal == '+' else number * -1

while True:
    qnt = int(input())
    if not qnt: break

    x = 1
    current = x

    for co in map(change, input().split()):
        if current == 1:

            current = co if co != 0 else x

        elif abs(co) == abs(current):
            if current + co:
                x *= -1
                current = x
            else: current = x

    values = dict({
        1: 'x',
        2: 'y',
        3: 'z'
    })

    print('+' if current > 0 else '-', values[abs(current)], sep="")