#include <bits/stdc++.h>
using namespace std;

int main()
{
  int qtd;
  string nome;
  map<string, int> nomes;

  cin >> qtd;
  while (qtd--)
  {
    cin >> nome;
    nomes[nome]++;
    cout << (nomes[nome] >= 2 ? "YES" : "NO") << endl;
  }

  return 0;
}
