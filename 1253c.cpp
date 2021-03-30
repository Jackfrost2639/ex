#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n, m;
const int MAX = 2e5 + 1;
int sweet[MAX];
ll dp[MAX];
ll sum[MAX];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> sweet[i];
    sort(sweet+1, sweet+n+1);

    for(int i = 1; i <= m; i++)
    {
        sum[i] = sweet[i];
    }
    for(int i = m+1; i <= n; i++)
    {
        sum[i] = sum[i-m] + sweet[i];
    }

    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + sum[i];
        cout << dp[i] << ' ';
    }
    cout << endl;
    return 0;
}