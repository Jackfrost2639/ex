#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int const MOD = 1e9+7;
int n, k;
int candy[101];
int dp[101][100001];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> candy[i];
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        ll sum = 0;
        int l = 0;
        for(int j = 0; j <= k; j++)
        {
            sum += dp[i-1][j];
        
            while(l >= 0 && l < j-candy[i])
            {
                sum -= dp[i-1][l];
                l++;
            }

            dp[i][j] = sum%MOD;
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}