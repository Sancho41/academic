'''
https://codeforces.com/group/uZDbxesr6A/contest/270750/problem/A

A. Ciranda
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mais um semestre no IESB e os alunos de teatro estão novamente no pátio, dessa vez realizando uma brincadeira chamada Ciranda, que consiste em juntar vários alunos com as mãos dadas em um circulo. Kevin, ficou interessado por saber quantas pessoas estariam na brincadeira dependendo do raio do circulo. Considere que a distancia entre as mãos de uma mesma pessoa na roda é de 175 centímetros. Considere as 6 primeiras casas decimais de PI.

Input
Será informado um número real R relativo ao raio do circulo (1≤R≤105) em metros.

Output
Informe um único inteiro com a menor quantidade de pessoas necessárias para formar um Ciranda de raio R.

Example
inputCopy
5.2
outputCopy
19

'''


import math
print(math.ceil((2* round(math.pi, 6) * float(input())) * 100 / 175))