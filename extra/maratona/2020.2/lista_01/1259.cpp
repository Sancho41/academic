#include <bits/stdc++.h>
using namespace std;

int main () {
    int qtd;
    int input;
    vector<int> par, impar;


    cin >> qtd;

    while(qtd--)
    {
        cin >> input;
        if (input % 2 == 0)
            par.push_back(input);
        else
            impar.push_back(-input);
    }

    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());

    for (auto x : par)
        cout << x << endl;
    
    for (auto x : impar)
        cout << (-x) << endl;

    return 0;
}
