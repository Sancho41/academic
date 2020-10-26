#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string mens = "ABCDE";
  vector<int> notas(5);
  int input, sum = 0;
  for (int i = 0; i < 5; i++)
  {
    cin >> input;
    notas[i] = input <= 127;
    sum += notas[i];
  }

  if (sum != 1)
    cout << "*" << endl;
  else
    for (int i = 0; i < notas.size(); i++)
      if (notas[i])
        cout << mens[i] << endl;
}

int main()
{
  while (1)
  {
    int qtd;
    cin >> qtd;
    if (!qtd)
      break;
    while (qtd--)
      solve();
  }
  return 0;
}
