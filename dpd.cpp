#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n, w;
ll dp[100001][100];
ll item[101][2];
int main() {
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> item[i][1] >> item[i][0];
    }
    for(int i = 0; i <= w; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++) {
            dp[j][i] = dp[j][i-1];
        }
        for(int j = 0; j <= w; j++)
        {
            if(dp[j][i-1] != -1 && (j + item[i][1]) <= w)
            {
                dp[j + item[i][1]][i] = max(dp[j + item[i][1]][i], dp[j][i-1] + item[i][0]);
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            //cout << dp[j][i] << ' ';
            ans = max(ans, dp[j][i]);
        }
        //cout << endl;
    }
    cout << ans << endl;
}