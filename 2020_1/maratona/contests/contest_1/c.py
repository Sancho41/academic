'''
https://codeforces.com/group/uZDbxesr6A/contest/270750/problem/C

C. Longe de Casa
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mateus estava longe de casa a mais de uma semana, sem sinal de GPS, quando encontrou um mapa, aonde estava marcado a sua posição e por coincidência, a de sua casa. Mateus precisa saber a distância para descobrir se ainda está muito longe.

Input
Serão informados quatro inteiros, XA, YA, XC, YC relativos as coordenadas atuais de Mateus e as da casa. (−357≤XA,YA,XC,YC≤357)

Output
Informe a distância entre a casa e a localização atual de Mateus com quatro casas decimais de precisão.

Example
inputCopy
1 1 1 5
outputCopy
4.0
'''
xa, ya, xb, yb = map(int, input().split())
print( round(((xb - xa)**2 + (yb - ya)**2)**0.5, 4) )