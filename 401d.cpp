#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

const int MAX = 1<<18;
ll n, m;
ll dp[101][MAX];
ll arr[18];
ll counter[10];

ll powm(ll base, ll exp) {
    ll ans = 1;
    for (int i=0; i<exp; i++) {
        ans *= base;
        base %= m;
    }
    return ans;
}

ll fact(int n) {
    if (n == 0) return 1;
    return fact(n-1) * n;
}

int main() {
    cin >> n >> m;
    int t = 0;
    while(n > 0)
    {
        counter[n%10] ++;
        arr[t++] = n % 10;
        n /= 10;
    }

    dp[0][0] = 1;

    for (int bitmask=0; bitmask < 1<<t; bitmask++) {
        int ct = 0;
        int tmp = bitmask;
        while (tmp) {
            ct += tmp&1;
            tmp >>= 1;
        }

        ll multiplier = powm(10, t-ct-1);

        for (int k=0; k<m; k++) {
            for (int j=0; j<t; j++) {
                if (ct == 0 && arr[j] == 0) continue;
                if (bitmask & (1<<j)) continue;
                dp[(k + multiplier * arr[j]) % m][bitmask | (1<<j)] += dp[k][bitmask];
            }
        }
    }

    ll res = dp[0][(1<<t)-1];

    for (int i=0; i<10; i++) {
        res /= fact(counter[i]);
    }

    cout << res;
    
    return 0;
}