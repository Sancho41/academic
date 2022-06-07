#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 2; i <= n && i - 1 < n; i += 2)
    cout << i << "^2 = " << (long long int)pow(i, 2) << endl;
  return 0;
}
