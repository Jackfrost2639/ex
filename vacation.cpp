#include <bits/stdc++.h>

using namespace std;

int n;
int happi[100001][3];
int dp[100001][3];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> happi[i][0] >> happi[i][1] >> happi[i][2];
    }

    dp[0][0] = happi[0][0];
    dp[0][1] = happi[0][1];
    dp[0][2] = happi[0][2];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int mn = 0;
            for(int h = 0; h < 3; h++)
            {
                if(h != j) mn = max(mn, dp[i-1][h] + happi[i][j]);
            }

            dp[i][j] = mn;
        }
    }

    int mn = 0;
    for(int i = 0; i < 3; i++)
    {
        mn = max(mn, dp[n-1][i]);
    }

    cout << mn << endl;
}