"""
    Objetivo: Nivelar conhecimentos especificos de disciplinas do Ensino Médio

    Linguagens: Lingua portuguesa, Redação e Lingua estrangeira.
    Ciencias Exatas: Fisica e Matemática.
    Ciencias Humanas: Historia, Literatura, Geografia, Sociologia e filosofia.
    Ciencias Natureza: Biologia e Quimica. 
"""

linguagens = 59.3
exatas = 75.0
humanas = 70.0
natureza = 54.0

print(f'Linguagens: {linguagens}% de acerto')
print(f'Ciências Exatas: {exatas}% de acerto')
print(f'Ciências Humanas: {humanas}% de acerto')
print(f'Ciências da Natureza: {natureza}% de acerto')

if linguagens < 60:
    print('O rendimento em Linguagens é menor que a média esperada, ler e escrever bem ajuda na comunicação em geral, foque em ler mais livros e leia o material.')
if exatas < 60:
    print('O rendimento em Ciências Exatas é menor que a média esperada, matemática e fisica melhoram seu raciocinio logico em geral, estabeleça a meta de 5 questões de fisica e 5 de matemática diária e leia o material.')
if humanas < 60:
    print('O rendimento em Ciências Humanas é menor que a média esperada, é necessário entender como a sociedade se formou e se estruturou para ser um cidadão que promove a mudança, leia os livros de filosofia e assista as video aulas de historia e geografia em nosso portal.')
if natureza < 60:
    print('O rendimento em Ciências da Natureza é menor que a média esperada, é necessario entender processos quimicos e dos seres vivos em geral, foque em resolver questões e leia o material.')
    
