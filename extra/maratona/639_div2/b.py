def count (x):
  cont = 1
  cards = 2
  while cards < x:
    cont += 1
    cards += 2 * cont + (cont - 1)
  
  if cards > x:
    cards -= (2 * cont + (cont - 1))

  if cards > 2:
    return count(abs(cards - x)) + 1

  if cards == 2:
    return 1

  return 0

for _ in range(int(input())):
  print(count(int(input())))
