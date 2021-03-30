#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

typedef long long ll;

ll n, m, k;
ll cnt(ll x)
{
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += min((x-1)/i, m);
    }

    return sum;
}

int main() {
    cin >> n >> m >> k;
    ll l = 1;
    ll r = n * m;
    ll ans = 0;

    while(l <= r)
    {
        ll mid = (l+r)/2;
        ll s = cnt(mid);

        if(s <= k - 1)
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else if(s >= k)
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}