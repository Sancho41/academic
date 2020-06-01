#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, vogais, cons;
  string s;
  vector<char> s_vogal = {'a', 'e', 'i', 'o', 'u'};
  cin >> n;
  bool voal;
  while (n--)
  {
    cin >> s;
    string res = "assim nao po";
    vogais = 0;
    cons = 0;
    if (s.size() % 2 == 0)
    {
      for (int i = 0; i < s.size(); i++)
      {
        voal = false;
        for (int j = 0; j < s_vogal.size(); j++)
        {
          if (tolower(s[i]) == s_vogal[j])
          {
            vogais++;
            voal = true;
            break;
          }
        }
        if (!voal)
        {
          cons++;
        }
      }
      if (vogais > 0 and cons % vogais == 0)
      {
        res = "hahaha";
      }
    }
    cout << res << endl;
  }
  return 0;
}