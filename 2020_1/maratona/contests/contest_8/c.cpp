#include <bits/stdc++.h>
#define MAX 50000

using namespace std;

int check_max(int i, vector<int> a)
{
  int b = a[i];       // maior valor
  int s = b;          // maior valor
  int m = a[i];       // maior valor
  int tam = a.size(); // tamanho do vetor

  for (int j = 0; j < s; j++)
  {
    int il = i - 1 - j; // percorre do indice para a esquerda
    int ir = i + 1 + j; // percorre do indice para a direita

    if (il < 0 or ir >= tam) // Para se estiver fora do vetor
      break;

    m--; // Decrementa o próximo tamanho necessário

    int c1 = a[il]; // pega os valores nos indices
    int c2 = a[ir];

    int cm = c1 < c2 ? c1 : c2; // armazena o menor

    if (m == 0 || cm == 0) // se o menor número entre os dois lados
    {                      // for 0 ou o tamanho necessário for 0
                           // Significa que achou o tamanho máximo
      return i - il;
    }
    else if (cm < m) // se o menor tamanho for menor que o tamanho
    {                // necessário, muda o valor necessário
      m = cm;        // O valor necessário será o do menor tamanho
    }
  }

  return b;
}

int main()
{
  int qtd;
  int max = 0, c;
  vector<int> numeros;
  cin >> qtd;

  numeros.push_back(0);
  for (int i = 0; i < qtd; i++)
  {
    int numero;
    cin >> numero;
    numeros.push_back(numero);
  }
  numeros.push_back(0);

  for (int i = 0; i < qtd + 2; i++)
  {
    if (max >= numeros.size() - i)
      break;
    c = check_max(i, numeros);
    max = c > max ? c : max;
  }

  cout << max << endl;

  return 0;
}
