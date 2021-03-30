#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n, h, l, r;
int dp[2000][2000];
int tim[2000];

int main() {
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++)
    {
        cin >> tim[i];
    }

    dp[0][0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < h; j++)
        {
            dp[j][i] = max(dp[j-tim[i]][i-1], dp[j-(tim[i]-1)][i-1]);
        }
    }
    return 0;
}