#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h1, m1;
  int h2, m2;
  int h3, m3;
  int total1, total2, total3;

  scanf("%d:%d", &h1, &m1);
  scanf("%d:%d", &h2, &m2);

  total1 = h1 * 60 + m1;
  total2 = h2 * 60 + m2;

  total3 = total1 + ((total2 - total1) / 2);
  h3 = total3 / 60;
  m3 = total3 % 60;

  cout << setfill('0') << setw(2) << h3;
  cout << ":";
  cout << setfill('0') << setw(2) << m3 << endl;

  return 0;
}
