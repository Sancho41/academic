#include <bits/stdc++.h>

using namespace std;

int nextLayer(int i)
{
  if (i == 0)
    return 2;
  int cont = i;
  cont += (i + 1) * 2;
  return cont;
}

int countLayer(int qtd)
{
  int cont = 0;
  for (int i = 0; i < qtd; i++)
  {
    cont += nextLayer(i);
  }
  return cont;
}

void solve()
{
  int qtd;
  cin >> qtd;
  cout << countLayer(qtd) << endl;
}

int main()
{
  int qtd;
  cin >> qtd;
  while (qtd--)
    solve();
  return 0;
}
