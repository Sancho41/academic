#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> soldiers(n, 0);

  for (int i = 0; i < soldiers.size(); i++)
    soldiers[i] = i + 1;

  auto curr = (k - 1) % soldiers.size();

  int cont = 0;
  while (soldiers.size() != 1)
  {
    soldiers.erase(next(soldiers.begin(), curr));
    curr = (curr + k - 1) % soldiers.size();
  }
  cout << soldiers[0];
}

int main()
{

  int qtd, counter = 0;
  cin >> qtd;
  while (qtd--)
  {
    cout << "Case " << ++counter << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}
