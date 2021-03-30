#include <bits/stdc++.h>

using namespace std;

int n, m, k;
long long x[1000001];

int main()
{
    cin >> n >> m >> k;
    long long total = 1;

    for(int i = 1; i <= n; i++)
    {
        total = (total*m)%1000000007;
        if(i<k) x[i] = total;
    }

    for(int i = k; i < n; i++)
    {
        for(int c = 1; c <= k-1 ; c++) x[i] = (x[i] + x[i-c]) % 1000000007;
        x[i] = (x[i] * m-1) % 1000000007;
    }

    cout << total - x[n] << endl;
}