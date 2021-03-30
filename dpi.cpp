#include <bits/stdc++.h>
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

int n;
double prob[3001];
double dp[3001][3001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> prob[i];
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j)
            {
                dp[i][j] = dp[i-1][j-1] * prob[i] + dp[i-1][j] * (1-prob[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j] * (1-prob[i]);
            }
        }
    }

    double ans = 0;
    for(int i = (n+1)/2; i <= n; i++)
    {
        ans += dp[n][i];
    }
    cout << setprecision(9);
    cout << ans << endl;
    return 0;
}