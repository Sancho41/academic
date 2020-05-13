for i in range(int(input())):
    qtd, budget = map(int, input().split())
    houses = sorted(map(int, input().split()))
    s = 0
    qtd = 0
    
    for house in houses:
        if s > budget:
            break

        s += house
        qtd += 1

    
    print('Case #{}: {}'.format(i + 1, qtd - 1 if s > budget else qtd))
