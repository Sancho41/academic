import random
import json
a = 97
z = 122
r = z - a + 1

participantes = list()

aaaa
aaab
aaac


for x in range(r):
    for y in range(r):
        for z in range(r):
            for w in range(r):
                nome = "{}{}{}{}".format(chr(a + x), chr(a + y), chr(a + z), chr(a + w))
                part = {}
                part["nomeAluno"] = nome
                part["nota1"] = round(random.uniform(0,10), 2)
                part["nota2"] = round(random.uniform(0,10), 2)
                part["nota3"] = round(random.uniform(0,10), 2)
                participantes.append(part)

final = {}
final['quantidadeVagas'] = 2
final['participantes'] = participantes

j = json.dumps(final)


f = open("final.json", "w")
f.write(j)
f.close()