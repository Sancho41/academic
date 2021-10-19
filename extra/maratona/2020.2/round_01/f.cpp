#include <bits/stdc++.h>
using namespace std;

int main()
{
  string digit;
  cin >> digit;
  cout << (int)digit.at(digit.size() - 1) % 2 << endl;
}
