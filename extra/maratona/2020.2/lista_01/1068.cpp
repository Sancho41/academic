#include <bits/stdc++.h>
using namespace std;

int main()
{
  string check;
  while (cin >> check)
  {
    stack<char> pilha;
    bool incorrect = false;
    for (auto letra : check)
    {
      if (letra == '(')
        pilha.push('(');
      if (letra == ')')
      {
        if (pilha.empty())
        {
          incorrect = true;
          break;
        }
        else
          pilha.pop();
      }
    }
    if (incorrect || !pilha.empty())
    {
      cout << "incorrect" << endl;
    }
    else
      cout << "correct" << endl;
  }
  return 0;
}
