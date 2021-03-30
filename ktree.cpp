#include <bits/stdc++.h>

using namespace std;

int n, k, d;
int kt[101];
int dt[101];

int main()
{
    cin >> n >> k >> d;

    kt[0] = 1;
    dt[0] = 1;
    d--;
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 1; j <= k; j++)
        {
            if((i-j) >= 0)
            {
                sum += kt[i-j];
                sum %= 1000000007;
            }
        }

        kt[i] = sum;
    }

    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 1; j <= d; j++)
        {
            if((i-j) >= 0) sum += dt[i-j];
        }

        dt[i] = sum;
    }

    cout << kt[n] - dt[n] << endl;
}