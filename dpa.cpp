#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
int h[100000];
int dp[100000];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}