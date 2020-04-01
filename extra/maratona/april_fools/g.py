'''
per nextum in unam tum XI conscribementis fac sic
    vestibulo perlegementum da varo.
    morde varo.
    seqis cumula varum.
cis

per nextum in unam tum XI conscribementis fac sic
    seqis decumulamenta da varo.
    varum privamentum fodementum da aresulto.
    varum tum III elevamentum tum V multiplicamentum da bresulto.
    aresultum tum bresultum addementum da resulto.

    si CD tum resultum non praestantiam fac sic
        dictum sic f(%d) = %.2f cis tum varum tum resultum egresso describe.
        novumversum egresso scribe.
    cis
    si CD tum resultum praestantiam fac sic
        dictum sic f(%d) = MAGNA NIMIS! cis tum varum egresso describe.
        novumversum egresso scribe.        
    cis
cis
'''

from math import sqrt

l = list()
for _ in range(11):
  l.append(int(input()))

for _ in range(11):
  varo = l.pop()
  aresulto = abs(varo**(1/2))
  bresulto = (varo**3) * 5
  resulto = aresulto + bresulto

  print(f'f({varo}) =', end=" ")
  if 400 >= resulto:
    print('%.2f' % resulto)
  else:
    print('MAGNA NIMIS!')