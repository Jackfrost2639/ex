#include <bits/stdc++.h>

using namespace std;

int n, k;
int s[401];
int is[401];
int mx[401][401];
int dp[401][401];

int main()
{
    cin >> n >> k;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> is[i];
        sum += is[i];
        s[i] = sum;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = 0x7fffffff;
        }
    }

    //set up mx array here
    for(int i = 0; i < n-1; i++)
    {
        int t = 0;
        for(int j = i+1; j < n; j++)
        {
            for(int h = i; h <= j; h++)
            {
                t = max(t, is[h]);
            }
            mx[i][j] = t;
        }
        
    }

    dp[0][0] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = i; j <= k; j++)
        {
            int temp = 0x7fffffff;
            for(int h = 0; h < i; h++)
            {
                for(int a = 0; a < j; a++)
                {
                    temp = min(temp, dp[h][a] + is[mx[h][i]] * (i-h));
                }
            }
            dp[i][j] = min(temp, dp[i-1][j]);
        }
    }
    
    int mn = 0x7fffffff;
    for(int i = 0; i <= k; i++)
    {
        mn = min(mn, dp[i][k-1]);
    }

    //cout << mn << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}