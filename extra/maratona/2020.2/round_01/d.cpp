#include <bits/stdc++.h>
using namespace std;

void solve()
{

  string nome, hash;
  cin >> nome >> hash;

  vector<int> letras(300), testes;

  for (auto letra : nome)
    letras[letra]++;

  int tamNome = nome.size();
  int tamHash = hash.size();

  for (int i = 0; i < tamHash; i++)
  {
    if (letras[hash[i]] > 0)
    {
      testes = letras;
      int cont = 0;
      for (int j = i; j < tamHash; j++)
      {
        char curr = hash[j];
        if (testes[curr] == 0)
          break;
        cont++;
        testes[curr]--;
        if (cont == tamNome)
          break;
      }
      if (cont == tamNome)
      {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}

int main()
{
  int qtd;
  cin >> qtd;
  while (qtd--)
    solve();
}
