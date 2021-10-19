#include <bits/stdc++.h>
using namespace std;

string invert(string a, int index)
{
  for (int i = 0; i <= index / 2; i++)
  {
    int j = (index - i);
    char aux = a[i];
    a[i] = a[j];
    a[j] = aux;
  }

  return a;
}

int main()
{

  string a;
  int qtd;

  cin >> qtd;
  cin >> a;

  for (int i = 0; i <= qtd; i++)
  {
    if (i && a.length() % i == 0)
    {
      a = invert(a, i - 1);
    }
  }

  cout << a << endl;

  return 0;
}
