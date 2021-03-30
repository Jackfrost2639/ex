#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

const ll MAX = 1e18;

int n;
ll a[401];
ll dp[401][401];

ll dps(int l, int r)
{
    ll mn = MAX;

    if(dp[l][r] != 0)
    {
        return dp[l][r];
    }
    if(l == r) return 0;

    ll sum = 0;
    for(int i = l; i <= r; i++) sum += a[i];

    for(int i = l; i < r; i++)
    {
        mn = min(mn, dps(l, i) + dps(i+1, r) + sum);
    }

    dp[l][r] = mn;
    return dp[l][r];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << dps(0, n-1) << endl;

    return 0;
}