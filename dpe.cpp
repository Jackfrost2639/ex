#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

const ll MAX = 1e18;
ll n, w;
ll item[101][2];
ll dp[101][100001];
int main() {
    cin >> n >> w;
    ll tval = 0;
    for(int i = 1; i <= n; i++)
    {
        //value, weight
        cin >> item[i][1] >> item[i][0];
        tval += item[i][0];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= tval; j++)
        {
            dp[i][j] = MAX;
        }
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= tval; j++)
        {
            dp[i][j] = dp[i-1][j];
        }
        for(int j = 0; j <= tval; j++)
        {
            if(dp[i-1][j] != MAX)
            {
                dp[i][j + item[i][0]] = min(dp[i][j + item[i][0]], dp[i-1][j] + item[i][1]);
            }
        }
    }

    ll ans = MAX;
    for(int i = 0; i <= tval; i++)
    {
        if(dp[n][i] <= w) ans = i;
    }

    cout << ans << endl;
    return 0;
}