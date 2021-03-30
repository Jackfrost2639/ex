#include <bits/stdc++.h>

using namespace std;

int n;
double p[3000];
double dp[3000][3000];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    dp[1][1] = p[1];
    dp[1][0] = 1 - p[1];

    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] * (1-p[i]);
    }
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i-1][j-1] * p[i]) + (dp[i-1][j] * (1-p[i]));
        }
    }

    double sum = 0;
    for(int i = (n+1)/2; i <= n; i++)
    {
        sum += dp[n][i];
    }

    printf("%.10lf", sum);
}