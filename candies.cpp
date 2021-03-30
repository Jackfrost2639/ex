#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[101];
int dp[101][100001];
int d= 1e9 + 7;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i <= a[0]; i++) dp[0][i] = 1;

    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(i-1 >= 0 && j-a[i]-1 >= 0) sum -= dp[i-1][j-a[i]-1];
            sum = (sum + d) % d;
            if(i-1 >= 0) sum += dp[i-1][j];
            sum = sum % d;
            dp[i][j] = sum;
        }
        sum = 0;
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j <= k; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][k] << endl;
}