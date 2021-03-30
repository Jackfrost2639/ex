#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int dp[100001][3];
int tree[100001][2];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> tree[i][0] >> tree[i][1];

    if(tree[0][0] + tree[0][1] < tree[1][0]) dp[0][0] = 1;
    else dp[0][0] = 0;

    dp[0][1] = 1;
    dp[0][2] = 0;

    for(int i = 1; i < n-1; i++)
    {
        if(tree[i+1][0] > (tree[i][0] + tree[i][1]))
        {
            dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        }

        if(tree[i-1][0] + tree[i-1][1] < tree[i][0] - tree[i][1])
        {
            dp[i][1] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        }
        else if(tree[i-1][0] < tree[i][0] - tree[i][1])
        {
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]) + 1;
        }
        
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }

    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        ans = max(ans, dp[n-2][i]);
    }

    cout << ans + 1 << endl;
    return 0;
}