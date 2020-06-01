from sys import stdin, stdout
 
si = stdin.readline
sis = stdin.readlines
 
so = stdout.write

l = len
f = filter

s_vogal = {'a':1,'e':1,'i':1,'o':1,'u':1,'A':1,'E':1,'I':1,'O':1,'U':1}

qtd = int(si())
vogais, tam = 0, 0
 
lines = sis()
for line in lines:
  vogais = 0
  tam = l(line)
  vogais = l(f(lambda x: x in s_vogal, line))
  if(vogais>0 and (tam - 1)%vogais==0 and ((tam - 1) % 2 == 0)):
    so('hahaha\n')
  else:
    so('assim nao po\n')