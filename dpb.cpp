#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int h[100000];
int dp[100000];
int k;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = 0x7fffffff;
    }
    
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 0)
            {
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}