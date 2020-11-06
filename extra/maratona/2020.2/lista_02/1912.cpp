#include <bits/stdc++.h>
using namespace std;

void solve(int N, int A)
{
    vector<int> deitado;
    int input;
    int sumTotal = 0;
    while (N--)
    {
        cin >> input;
        sumTotal += input;

        for (int i = 0; i < input; i++)
            if ((i + 1) <= deitado.size())
                deitado[i]++;
            else
                deitado.push_back(1);
    }

    if (sumTotal == A)
    {
        cout << ":D" << endl;
        return;
    } else if (sumTotal < A)
    {
        cout << "-.-" << endl;
        return;
    }

    int sum = 0;
    int i;

    for (i = deitado.size() - 1; i >= 0 && sum < A; i--)
        sum += deitado[i];
    
    printf("%.4f\n", (float)(i + 1));
}

int main()
{
    int N, A;

    cin >> N >> A;

    while (N != 0 && A != 0)
    {
        solve(N, A);
        cin >> N >> A;
    }

    return 0;
}
