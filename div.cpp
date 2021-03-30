#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int n, k;
int dp[2001][2001];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 1; i < k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int h = 1; h <= n/j; h++)
            {
                dp[i+1][j * h] += dp[i][j];
                dp[i+1][j * h] %= MOD;
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += dp[k][i];
        sum %= MOD;
    }

    /*for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << sum << endl;
}