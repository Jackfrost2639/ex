#include <bits/stdc++.h>

using namespace std;

int n;
int board[101];
int dp[101][101][101];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> board[i];
    }

    if(board[1] == 0)
    {
        dp[1][1][1] = 0;
    }
    else
    {
        dp[1][1][1] = 1;
    }
    

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                if(j < i)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if(board[i] != i-j) dp[i][j][k]++;
                }
                else
                {
                    int mn = 0x7fffffff;
                    for(int x = 1; x < j; x++)
                    {
                        mn = min(mn, dp[j-1][x][k-1]);
                    }
                    dp[i][j][k] = mn;
                    if(board[i] != i-j) dp[i][j][k]++;
                }
                
            }
        }
    }

    for(int k = 0; k <= n; k++)
    {
        int mn = 0x7fffffff;
        for(int j = 1; j <= n; j++)
        {
            mn = min(mn, dp[n][j][k]);
        }
        cout << mn << endl;
    }
}