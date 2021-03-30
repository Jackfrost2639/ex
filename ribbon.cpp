#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;
int dp[4001];

int main()
{
    cin >> n >> a >> b >> c;

    for(int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }

    for(int i = 1; i <= n; i++)
    {
        int mx = -1;
        if(i-a >= 0 && dp[i-a] != -1) mx = max(mx, dp[i-a]+1);
        if(i-b >= 0 && dp[i-b] != -1) mx = max(mx, dp[i-b]+1);
        if(i-c >= 0 && dp[i-c] != -1) mx = max(mx, dp[i-c]+1);

        dp[i] = mx;
    }

    cout << dp[n] << endl;
}