'''
https://codeforces.com/group/uZDbxesr6A/contest/270750/problem/B

B. N Números
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Gabriel estava muito interessado em uma fase extra de seu novo jogo, para entrar nela, se faz necessário resolver um quebra cabeça. No centro da porta existe um número N e para destravar a porta tem que colocar uma senha numérica. Apos estudar bastante o padrão de informações no jogo, Gabriel descobriu que a senha seria N + NN + NNN, ou seja, se o número for 5 então a senha será 5 + 55 + 555 = 615. Ajude Gabriel com um programa que calcule a senha, pois ele precisará passar por essa porta várias vezes durante o jogo e toda vez que ele retorna, a porta muda o valor.

Input
Será informado um número N (1≤N≤9).

Output
Informe o valor inteiro correspondente a senha

Example
inputCopy
5
outputCopy
615
'''
n = int(input())
print(n + (n*11) + (n*111))