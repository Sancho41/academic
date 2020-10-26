#include <bits/stdc++.h>
using namespace std;

int solve()
{
  vector<int> qtds = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  string numero;
  int cont = 0;
  cin >> numero;
  for (auto n : numero)
    cont += qtds[(int)n - 48];
  return cont;
}

int main()
{
  int qtd;
  cin >> qtd;
  while (qtd--)
    cout << solve() << " leds\n";
  return 0;
}
