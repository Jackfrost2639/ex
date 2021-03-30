#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n;
ll t1[100001];
ll t2[100001];
ll dp[100001][3];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t1[i];
    for(int i = 0; i < n; i++) cin >> t2[i];

    dp[0][0] = 0;
    dp[0][1] = t1[0];
    dp[0][2] = t2[0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + t1[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + t2[i];
    }

    ll ans = 0;
    for(int i = 0; i < 3; i++)
    {
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}