#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n, k;
int const MOD = 1e9+7;
ll dp[2001][2001];

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) dp[i][1] = 1;

    for(int i = 1; i < k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int t = 1;
            while(t*j <= n)
            { 
                dp[t*j][i+1] += dp[j][i];
                dp[t*j][i+1] %= MOD;
                t++;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += dp[i][k];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}