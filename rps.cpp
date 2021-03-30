#include <bits/stdc++.h>

using namespace std;

int n, k;
int seq[100001];
int dp[100001][21][3];

int main()
{
    ifstream in("hps.in");
    ofstream out("hps.out");
    
    in >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        char a;
        in >> a;
        if(a == 'H') seq[i] = 0;
        if(a == 'P') seq[i] = 1;
        if(a == 'S') seq[i] = 2;
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int x = 0; x < 3; x++)
            {
                if(i == 0) dp[i][j][x] = 0;
                else if(j == 0)
                {
                    dp[i][j][x] = dp[i-1][j][x] + ((seq[i] == x) ? 1 : 0);
                }
                else
                {
                    int a = dp[i-1][j][x] + ((seq[i] == x) ? 1 : 0);
                    int b = dp[i-1][j-1][(x+1)%3] + ((seq[i] == x) ? 1 : 0);
                    int c = dp[i-1][j-1][(x+2)%3] + ((seq[i] == x) ? 1 : 0);
                    dp[i][j][x] = max(a, max(b, c));
                }
            }
        }
    }

    out << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << endl;
}