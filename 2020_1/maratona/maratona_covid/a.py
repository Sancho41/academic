qtd = int(input())
a = list(map(int, input().split()))
found = False
for i in range(qtd):
  j = i
  b = a.copy()
  idc = (b[j] - 1) % qtd
  while idc != 0 and len(b) > 1:
    if j >= len(b):
      j = len(b) - 1
    idc = (b[j] - 1) % len(b)
    if idc != 0:
      b.pop(idc)  
  if len(b) == 1 and b[0] == a[0]:
    print(a[i])
    found = True
    break
if not found:
  print("Nao quero mais brincar!")