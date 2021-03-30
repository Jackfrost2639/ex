#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int seq[100];
int dp[100][3];
const int MAX = 0x7fffffff;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> seq[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[i][j] = MAX;
        }
    }

    if(seq[0] == 1)
    {
        dp[0][1] = 0;
    }
    else if(seq[0] == 2)
    {
        dp[0][0] = 0;
    }
    else if(seq[0] == 3)
    {
        dp[0][0] = 0;
        dp[0][1] = 0;
    }

    dp[0][2] = 1;

    for(int i = 1; i < n; i++)
    {
        dp[i][2] = min({ dp[i-1][0], dp[i-1][1], dp[i-1][2] }) + 1;
        
        if(seq[i] == 1)
        {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
        else if(seq[i] == 2)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
        }
        else if(seq[i] == 3)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
    }

    int ans = MAX;
    for(int i = 0; i < 3; i++)
    {
        ans = min(ans, dp[n-1][i]);
    }

    cout << ans << endl;
    return 0;
}