'''
    https://onlinejudge.org/external/101/10114.pdf
    WA
'''

while True:
    total_days, dpay, loan_amount, qnt_depr = map(float, input().split())
    car = loan_amount + dpay
    par = loan_amount / total_days

    if total_days < 0: break

    _, depr = map(float, input().split())

    car -= car * depr

    current_day = 1

    last_depr = depr

    for _ in range(int(qnt_depr) - 1):
        depr_day, depr = map(float, input().split())

        for x in range(current_day, int(depr_day)):
            car -= car * last_depr
            loan_amount -= par
            if car < loan_amount:
                current_day += 1
            else: break

        last_depr = depr
        car -= car * last_depr
        loan_amount -= par
        if car < loan_amount:
            current_day += 1

    for x in range(current_day, int(total_days) + 1):
        last_depr = depr
        car -= car * last_depr
        loan_amount -= par
        if car < loan_amount:
            current_day += 1
        else:
            print(current_day, end=" ")
            print("month" if current_day == 1 else "months")
            break


        

'''
4 months
1 month
49 months
'''