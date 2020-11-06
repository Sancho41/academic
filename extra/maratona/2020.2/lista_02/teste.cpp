#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int n;
int mapa[MAX][MAX];

bool pode(int lin, int col) {
    for (int i = 0; i < n; i++)
    {
        if (mapa[i][col] == 1 || mapa[lin][col] == 1)
            return false;
    }
        
}

void solve(int lin, int col) {

    if (pode(lin, col))
    {
        mapa[lin][col] = 1;
        solve(0, col + 1);
    }
    pode(lin + 1, col);
}

int main () {
    cin >> n;

    return 0;
}
