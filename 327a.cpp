#include <bits/stdc++.h>

using namespace std;

int n;
int a[101];
int sum = 0;
int dp[101];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            sum++;
            dp[i]++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        dp[i] += dp[i-1];
    }

    int mx = -1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int n1 = dp[j] - dp[i-1];
            int n0 = j - i + 1 - n1;

            mx = max(mx, n0-n1);
        }
    }

    cout << sum + mx << endl;
}