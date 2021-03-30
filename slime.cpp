#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int a[401];
ll dp[401][401];

ll solve(int l, int r)
{
    if(dp[l][r] != -1) return dp[l][r];
    
    ll sum = 0;
    if(l == r) return 0;
    for(int i = l; i <= r; i++)
    {
        sum += a[i];
    }
    
    ll mn = 1e18;
    for(int i = l; i < r; i++)
    {
        mn = min(mn, solve(l, i) + solve(i+1, r));
    }
    
    sum += mn;
    return dp[l][r] = sum;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) dp[i][j] = -1;
    }
    // solve(0, n-1);
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << solve(0, n-1) << endl;
}