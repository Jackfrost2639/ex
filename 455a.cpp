#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;
typedef long long ll;

int n;
int cnt[100005];
ll dp[100005];

int main() {
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mx = max(mx, t);
        cnt[t]++;
    }

    for(int i = 1; i <= mx + 1; i++)
    {
        dp[i+1] = max(dp[i+1], dp[i]);
        dp[i+2] = max(dp[i+2], dp[i] + ((ll)cnt[i]) * i);
    }

    cout << dp[mx + 2] << endl;
    return 0;
}