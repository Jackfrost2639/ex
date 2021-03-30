#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

ll n;
ll a[3001];
ll dp[3001][3001];

ll dps(int l, int r)
{
    if(dp[l][r] != 0) return dp[l][r];
    if(l == r) return a[l];

    dp[l][r] = max(-1 * dps(l+1, r) + a[l], -1 * dps(l, r-1) + a[r]);
    return dp[l][r];
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << dps(0, n-1) << endl;;
}