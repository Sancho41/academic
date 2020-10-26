#include <bits/stdc++.h>
using namespace std;

void solve(int qtd)
{
  queue<int> fila;
  for (int i = 1; i <= qtd; i++)
    fila.push(i);

  cout << "Discarded cards: ";
  while (fila.size() > 1)
  {
    cout << fila.front();
    fila.pop();
    fila.push(fila.front());
    fila.pop();
    if (fila.size() > 1)
      cout << ", ";
  }
  cout << endl
       << "Remaining card: " << fila.front() << endl;
}

int main()
{
  int qtd;
  cin >> qtd;
  do
  {
    solve(qtd);
    cin >> qtd;
  } while (qtd != 0);
  return 0;
}
