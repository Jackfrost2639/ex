#include <bits/stdc++.h>

using namespace std;

int n, w;
long long weight[101];
long long value[101];
long long dp[100001];

int main()
{
    cin >> n >> w;
    long long lval = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
        lval += value[i];
    }

    for (int i=1; i<=lval; i++) {
        dp[i] = 1e18;
    }
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = lval; j > 0; j--)
        {
            if(j - value[i] >= 0) dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
        }
    }

    long long mx = 0;
    for(int i = 1; i <= lval; i++)
    {
        if(dp[i] <= w) mx = i;
    }

    cout << mx << endl;

}