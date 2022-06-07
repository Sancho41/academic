#include <bits/stdc++.h>
using namespace std;

int main()
{
  int qtd;
  cin >> qtd;
  vector<int> soldiers(qtd);

  int men = 99999, ans1, ans2;

  cin >> soldiers[0];
  for (int i = 1; i < qtd; i++)
  {
    cin >> soldiers[i];
    if (abs(soldiers[i] - soldiers[i - 1]) < men)
    {
      men = abs(soldiers[i] - soldiers[i - 1]);
      ans1 = i + 1;
      ans2 = i;
    }
  }

  if (abs(soldiers[0] - soldiers[qtd - 1]) < men)
  {
    ans1 = qtd;
    ans2 = 1;
  }

  cout << ans1 << " " << ans2 << endl;

  return 0;
}
