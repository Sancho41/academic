# WA - ( Não encontrei o corner case )
# https://onlinejudge.org/external/101/10114.pdf

while True:
    months, paid, loan_amount, qnt_depr = map(float, input().split())

    if months < 0: break

    l_per = list()

    last = 0

    for _ in range(int(qnt_depr)):

        month, percent = map(float, input().split())
        month = int(month)

        for _ in range(last, month):
            l_per.append(l_per[-1])
        l_per.append(percent)
        last = month + 1
    
    now = 0
    month_pay = loan_amount / months
    current_val = (loan_amount + paid) * (1 - l_per[0])
    current_loan = loan_amount

    while (current_val < current_loan):
        now += 1

        percent = (l_per[now] if now < len(l_per) else l_per[-1])

        current_loan -= month_pay
        current_val = current_val * (1 - percent)
    print(now, "monts" if now > 1 else "month")
