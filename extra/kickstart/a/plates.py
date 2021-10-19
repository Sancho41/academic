class Ps:
  def __init__(self, qtd, size, moves, stacks):
    self.stacks = stacks
    self.i = 0
    self.j = 0
    self.qtd = qtd
    self.size = size
    self.moves = moves

  def pd(self, i, j, moves):
    if i >= self.qtd or j >= self.size or moves == 0:
      return 0

    atual = self.stacks[i][j]
    n1 = self.pd(i,j + 1, moves - 1)
    n2 = self.pd(i + 1,0, moves - 1)
    nt = max(n1, n2)  
    return atual + nt

  def resolve(self):
    return self.pd(0, 0, self.moves)
  

for i in range(int(input())):
  n, k, p = map(int, input().split())

  stacks = [list(map(int, input().split())) for _ in range(n)]
  
  a = Ps(n, k, p, stacks)
  print(a.resolve())
  