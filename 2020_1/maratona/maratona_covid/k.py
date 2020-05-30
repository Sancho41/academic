qtd = int(input())

a = list(map(lambda x: int(x) % qtd), input().split())
print(a)