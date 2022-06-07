#include <bits/stdc++.h>
using namespace std;

// wut
int main()
{
  long double get;
  long long int index = 0, cur = 0;
  vector<int> notas = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
  vector<int> taken(notas.size());

  cin >> get;
  long long int fin = get * 100;

  for (int i = 0; i < notas.size(); i++)
  {
    long long int qtd = (int)((fin - cur) / notas[i]);
    cur += notas[i] * qtd;
    taken[i] += qtd;
  }

  cout << "NOTAS:" << endl;
  for (int i = 0; i < 6; i++)
    printf("%d nota(s) de R$ %.2f\n", taken[i], (double)notas[i] / 100);

  cout << "MOEDAS:" << endl;
  for (int i = 6; i < 12; i++)
    printf("%d nota(s) de R$ %.2f\n", taken[i], (double)notas[i] / 100);
  return 0;
}
