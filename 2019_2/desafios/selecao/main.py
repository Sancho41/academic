import json

with open('candidatos.json') as file:
    data = json.load(file)

vagas = data['quantidadeVagas']
if vagas <= 0:
    print("Nenhum participante aprovado pois não existem vagas!")
    exit()

notas = {}

for aluno in data['participantes']:
    media = round((aluno['nota1'] + aluno['nota2'] + aluno['nota3']) / 3, 2)
    nome = aluno['nomeAluno']
    if media not in notas:
        notas[media] = list()
    
    notas[media].append(nome)


aprovados = list()

while vagas > 0 and len(notas) > 0:
    nota = max(notas)
    mesma_nota = notas[nota]
    del notas[nota]
    if len(mesma_nota) <= vagas:
        vagas -= len(mesma_nota)
        for x in mesma_nota: 
            part = {}
            part['nome'] = x
            part['nota'] = nota
            aprovados.append(part)
        
    else:
        while vagas > 0:
            msg = "digite o número do participante a ocupar a {}ª vaga: ( {} restantes❗ )"
            print(msg.format(data['quantidadeVagas'] - vagas + 1, vagas))

            for i, aluno in enumerate(mesma_nota):
                print("{} ➡ {}".format(i, aluno))

            try:
                op = int(input())
                if op not in range(len(mesma_nota)):
                    continue
            except KeyboardInterrupt: 
                print("Saindo...\n")
                exit()
            except: continue
            
            part = {}
            part['nome'] = mesma_nota[op]
            part['nota'] = nota
            aprovados.append(part)

            mesma_nota.remove(mesma_nota[op])
            vagas -= 1

print('\nOs aprovados foram:🎉')
for x in aprovados:
    print("{:20} com nota: ✔ {}".format(x['nome'], x['nota']))