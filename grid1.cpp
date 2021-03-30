#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;
int h, w;
bool grid[1001][1001];
int dp[1001][1001];

int main()
{
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            char t;
            cin >> t;
            if(t == '#') grid[i][j] = true;
        }
    }

    dp[1][1] = 1;

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(grid[i][j]) continue;
            
            if(!grid[i][j-1]) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MAX;

            if(!grid[i-1][j]) dp[i][j] += dp[i-1][j];
            dp[i][j] %= MAX;
        }
    }

    cout << dp[h][w] << endl;
}