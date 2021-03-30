#include <bits/stdc++.h>

using namespace std;

int n;
int s1[1001];
int s2[1001];
int dp[1001][1001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s1[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> s2[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int t = dp[i-1][j-1] + (abs(s1[i] - s2[j]) <= 4 ? 1 : 0);
            dp[i][j] = max(t, max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n][n] << endl;
}