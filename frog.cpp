#include <bits/stdc++.h>

using namespace std;

int n, k;
int cost[100001];
int dp[100001];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int mn = 0x7fffffff;
        for(int j = 1; j <= k; j++)
        {
            if((i-j) >= 0)
            {
                mn = min(mn, dp[i-j] + abs(cost[i] - cost[i-j]));
            }
        }

        dp[i] = mn;
    }
    
    cout << dp[n-1] << endl;
}